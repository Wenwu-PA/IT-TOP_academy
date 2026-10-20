-- 1.1
SELECT
    p.Category,
    SUM(s.Revenue) AS Revenue,
    SUM(s.Quantity * p.PurchasePrice) AS Cost,
    SUM(s.Revenue - s.Quantity * p.PurchasePrice) AS Profit,
    SUM(s.Revenue - s.Quantity * p.PurchasePrice) * 100.0
        / NULLIF(SUM(s.Revenue), 0) AS Margin
FROM Sales s
JOIN Products p ON s.ProductID = p.ProductID
GROUP BY p.Category;

-- 1.2
SELECT
    p.Category,
    SUM(p.SellingPrice * s.Quantity - s.Revenue) AS DiscountLoss,
    SUM(p.SellingPrice * s.Quantity - s.Revenue) * 100.0
        / NULLIF(SUM(p.SellingPrice * s.Quantity), 0) AS DiscountPercent
FROM Sales s
JOIN Products p ON s.ProductID = p.ProductID
GROUP BY p.Category
ORDER BY DiscountLoss DESC;

-- 2.1
SELECT
    st.StoreName,
    SUM(s.Revenue - s.Quantity * p.PurchasePrice) AS Profit,
    st.RentMonthly + st.StaffSalaryMonthly AS Costs,
    SUM(s.Revenue - s.Quantity * p.PurchasePrice)
        - st.RentMonthly - st.StaffSalaryMonthly AS NetProfit
FROM Stores st
JOIN Sales s ON st.StoreID = s.StoreID
JOIN Products p ON s.ProductID = p.ProductID
GROUP BY st.StoreName, st.RentMonthly, st.StaffSalaryMonthly
ORDER BY NetProfit DESC;

-- 3.1
SELECT
    c.CustomerID,
    c.CustomerName,
    SUM(s.Revenue - s.Quantity * p.PurchasePrice) AS Profit,
    AVG(s.DiscountPercent) AS AvgDiscount
FROM Customers c
JOIN Sales s ON c.CustomerID = s.CustomerID
JOIN Products p ON s.ProductID = p.ProductID
GROUP BY c.CustomerID, c.CustomerName
ORDER BY Profit DESC;

-- 4.1
SELECT
    st.StoreName,
    SUM(s.Revenue - s.Quantity * p.PurchasePrice) * 1.0
        / NULLIF(SUM(s.Quantity), 0) AS ProfitPerUnit,

    (st.RentMonthly + st.StaffSalaryMonthly) * SUM(s.Quantity) * 1.0
        / NULLIF(SUM(s.Revenue - s.Quantity * p.PurchasePrice), 0) AS UnitsToSell
FROM Stores st
JOIN Sales s ON st.StoreID = s.StoreID
JOIN Products p ON s.ProductID = p.ProductID
GROUP BY st.StoreName, st.RentMonthly, st.StaffSalaryMonthly
ORDER BY UnitsToSell;

-- 5.1
WITH Profit AS (
    SELECT
        p.ProductID,
        p.ProductName,
        SUM(s.Revenue - s.Quantity * p.PurchasePrice) AS Profit
    FROM Products p
    JOIN Sales s ON p.ProductID = s.ProductID
    GROUP BY p.ProductID, p.ProductName
),
Total AS (
    SELECT
        ProductID,
        ProductName,
        Profit,
        SUM(Profit) OVER (ORDER BY Profit DESC) * 100.0
            / NULLIF(SUM(Profit) OVER (), 0) AS PercentTotal
    FROM Profit
)
SELECT
    ProductID,
    ProductName,
    Profit,
    CASE
        WHEN PercentTotal <= 80 THEN 'A'
        WHEN PercentTotal <= 95 THEN 'B'
        ELSE 'C'
    END AS ABC_Class
FROM Total
ORDER BY Profit DESC;
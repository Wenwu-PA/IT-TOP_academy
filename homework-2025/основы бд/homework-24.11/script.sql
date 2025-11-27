--1
SELECT 
    c.name AS category_name,
    COUNT(fc.film_id) AS film_count
FROM category c
LEFT JOIN film_category fc ON c.category_id = fc.category_id
GROUP BY c.category_id, c.name
ORDER BY film_count DESC;
--2
SELECT 
    c.first_name,
    c.last_name,
    SUM(p.amount) AS TotalPayments
FROM customer c
JOIN payment p ON c.customer_id = p.customer_id
GROUP BY c.customer_id, c.first_name, c.last_name
ORDER BY TotalPayments DESC
LIMIT 5;
--4
SELECT 
    st.first_name,
    st.last_name,
    s.store_id,
    SUM(p.amount) AS StoreRevenue
FROM staff st
JOIN store s ON st.store_id = s.store_id
JOIN payment p ON st.staff_id = p.staff_id
GROUP BY st.staff_id, st.first_name, st.last_name, s.store_id
ORDER BY s.store_id, StoreRevenue DESC;
--5
SELECT 
    a.first_name,
    a.last_name,
    COUNT(r.rental_id) AS rental_count
FROM actor a
JOIN film_actor fa ON a.actor_id = fa.actor_id
JOIN film f ON fa.film_id = f.film_id
JOIN inventory i ON f.film_id = i.film_id
JOIN rental r ON i.inventory_id = r.inventory_id
GROUP BY a.actor_id, a.first_name, a.last_name
ORDER BY rental_count DESC
LIMIT 5;
--6
SELECT 
    s.id AS sale_id,
    s.sale_date,
    p.name AS product,
    c.name AS category
FROM Sales s
JOIN Products p ON s.product_id = p.id
JOIN Categories c ON p.category_id = c.id
ORDER BY s.id;
--7
SELECT 
    c.name AS category,
    SUM(p.price) AS total_sales
FROM Categories c
JOIN Products p ON c.id = p.category_id
JOIN Sales s ON p.id = s.product_id
GROUP BY c.id, c.name
ORDER BY total_sales DESC
LIMIT 1;
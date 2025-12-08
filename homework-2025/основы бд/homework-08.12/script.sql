-- Аркадий Игоревич, доп материал что то и тут не робит(С впн работает, странно)

--1

CREATE TABLE Students (
    id INT NOT NULL UNIQUE,
    name VARCHAR(20) NOT NULL,
    surname VARCHAR(20) NOT NULL,
    age INT DEFAULT 18,
    date_of_receipt DATE DEFAULT (CURRENT_DATE),
    phone_number VARCHAR(20),
    
    PRIMARY KEY (id),
    
    CONSTRAINT chk_name CHECK (name != ''),
    CONSTRAINT chk_surname CHECK (surname != ''),
    CONSTRAINT chk_age CHECK (age >= 18),
    CONSTRAINT chk_date CHECK (date_of_receipt >= '2023-09-01'),
    CONSTRAINT chk_phone CHECK (
        phone_number REGEXP '^[78] \\([0-9]{3}\\) [0-9]{3}-[0-9]{2}-[0-9]{2}$'
    )
);

--2
SELECT u.id,COUNT(o.id) AS purchases_in_2023
FROM Users u LEFT JOIN Orders o ON u.id = o.buyer_id AND YEAR(o.order_date) = 2023
GROUP BY u.id ORDER BY u.id;
--3
SELECT SUM(b.apple_count + IFNULL(s.apple_count, 0)) AS total_apples,SUM(b.orange_count + IFNULL(s.orange_count, 0)) AS total_oranges
FROM BigBoxes b LEFT JOIN SmallBoxes s ON b.small_box_id = s.id;
--4
SELECT COUNT(*) AS total_pairs
FROM Points p1 JOIN Points p2 ON p1.id < p2.id
WHERE p1.x != p2.x AND p1.y != p2.y;
--5
SELECT p1.id AS p1,p2.id AS p2,ABS(p1.x - p2.x) * ABS(p1.y - p2.y) AS area
FROM Points p1 JOIN Points p2 ON p1.id < p2.id
WHERE p1.x != p2.x AND p1.y != p2.y
ORDER BY area DESC, p1 ASC, p2 ASC;
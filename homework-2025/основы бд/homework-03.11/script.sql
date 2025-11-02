-- 1)
SELECT store_id, COUNT(film_id) AS film_count
FROM inventory
GROUP BY store_id;

-- 2)
SELECT rating, COUNT(film_id) AS film_count
FROM film
GROUP BY rating
ORDER BY film_count DESC;

-- 3)
SELECT p.customer_id, SUM(p.amount) AS total_amount
FROM payment p
JOIN customer c ON p.customer_id = c.customer_id
GROUP BY p.customer_id
ORDER BY p.customer_id;

-- 4)
SELECT MONTH(rental_date) AS month, COUNT(rental_id) AS rental_count
FROM rental
GROUP BY MONTH(rental_date);

-- 5)
SELECT rating, COUNT(film_id) AS film_count
FROM film
GROUP BY rating
HAVING COUNT(film_id) > 200;

-- 6)
SELECT p.customer_id, SUM(p.amount) AS total_amount
FROM payment p
JOIN customer c ON p.customer_id = c.customer_id
GROUP BY p.customer_id
HAVING SUM(p.amount) > 150
ORDER BY p.customer_id;

-- 7)
SELECT first_name, last_name
FROM customer
WHERE city = 'London';
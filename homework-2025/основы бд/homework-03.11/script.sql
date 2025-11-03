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
SELECT customer_id, 
(SELECT SUM(amount)FROM payment p2 WHERE p2.customer_id = p1.customer_id) AS total_amount
FROM payment p1
GROUP BY customer_id
ORDER BY customer_id;

-- 4)
SELECT YEAR(rental_date) AS year, MONTH(rental_date) AS month, COUNT(rental_id) AS rental_count
FROM rental
GROUP BY YEAR(rental_date), MONTH(rental_date);

-- 5)
SELECT rating, film_count
FROM 
(SELECT rating, COUNT(film_id) AS film_count FROM film GROUP BY rating) AS rating_counts
WHERE film_count > 200;

-- 6)
SELECT customer_id, total_amount
FROM 
(SELECT customer_id, SUM(amount) AS total_amount FROM payment GROUP BY customer_id) AS customer_totals
WHERE total_amount > 150
ORDER BY customer_id;

-- 7)
SELECT first_name, last_name
FROM customer
WHERE address_id IN 
(SELECT address_id FROM address WHERE city_id IN 
(SELECT city_id FROM city WHERE city = 'London'));
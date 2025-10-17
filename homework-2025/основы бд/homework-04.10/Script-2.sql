 -- 1)
SELECT title 
FROM film 
WHERE title LIKE 'A%' OR title LIKE '% Man';

-- 2)
SELECT actor_id, first_name, last_name
FROM actor 
WHERE last_name LIKE '%NN%';

-- 3)
SELECT customer_id, first_name, last_name
FROM customer 
WHERE first_name LIKE 'J%Y' AND LENGTH(first_name) >= 5;

-- 4)
SELECT staff_id, 
       first_name, 
       last_name,
       CONCAT(first_name, ' ', last_name) AS 'ФИО сотрудника'
FROM staff;

-- 5)
SELECT film_id,
       title,
       rental_rate,
       (rental_rate * 5) AS total_rental_cost
FROM film
ORDER BY total_rental_cost DESC;
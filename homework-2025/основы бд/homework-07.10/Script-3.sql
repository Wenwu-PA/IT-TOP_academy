1)
SELECT name,surname,CONCAT(REPEAT('*', CHAR_LENGTH(SUBSTRING_INDEX(email, '@', 1))),'@',SUBSTRING_INDEX(email, '@', -1)) AS email
FROM directors
ORDER BY SUBSTRING_INDEX(email, '@', 1);

2)
SELECT id,a,b,CONCAT('[', a, '; ', b, ']') AS "range"
FROM Ranges;

3)
SELECT x,y,(x * x + y * y) AS squared_distance
FROM points
WHERE (x * x + y * y) > 400
ORDER BY squared_distance DESC;

4)
SELECT id,CONCAT('[', a, '; ', b, ']') AS `range`,
CAST(a + RAND() * (b - a + 1) AS UNSIGNED) AS random_value
FROM Ranges
ORDER BY id;

5)
SELECT film_id,title,REPLACE(title, 'The', 'A') AS modified_title
FROM film;

6)
SELECT title,
LEFT(description, 20) AS short_description
FROM film
WHERE title = 'ACADEMY DINOSAUR';
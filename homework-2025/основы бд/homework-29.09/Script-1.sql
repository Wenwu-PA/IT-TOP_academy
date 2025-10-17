-- Запрос для задания 1

SELECT title FROM film ORDER BY title


-- Запросы для задания 2

SELECT * FROM pups WHERE Age BETWEEN 5 AND 8;

SELECT * FROM pups WHERE Name != 'Снежок';

SELECT * FROM pups WHERE Age = 6 OR Price = 12000;
 
SELECT * FROM pups WHERE Age BETWEEN 5 AND 8 OR Price = 5000;

SELECT * FROM pups WHERE Age BETWEEN 7 AND 40 OR Price BETWEEN 6000 AND 13000;
 
SELECT * FROM pups WHERE Age = 6 OR Price != 7000;

SELECT * FROM pups LIMIT 3 OFFSET 5;

SELECT * FROM pups ORDER BY Price ASC;

SELECT * FROM pups ORDER BY Age DESC LIMIT 5 OFFSET 1;
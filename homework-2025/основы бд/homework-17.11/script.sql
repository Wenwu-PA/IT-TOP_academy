-- 1)
SELECT followee AS user, COUNT(*) AS followers
FROM Follow 
WHERE followee IN (
    SELECT DISTINCT followee 
    FROM Follow 
    WHERE followee IN (SELECT DISTINCT follower FROM Follow)
)
GROUP BY followee
ORDER BY user ASC;

-- 2)
SELECT 
    id,
    SUM(quantity) AS total_quantity,
    COUNT(DISTINCT product_id) AS distinct_products
FROM Orders
GROUP BY id
HAVING MAX(quantity) > ALL (
    SELECT SUM(quantity) * 1.0 / COUNT(DISTINCT product_id)
    FROM Orders
    GROUP BY id
)
ORDER BY id;

-- 3)
SELECT id
FROM Candidates
WHERE years_of_exp >= 2
AND interview_id IN (
    SELECT interview_id 
    FROM Rounds 
    GROUP BY interview_id 
    HAVING SUM(score) > 15
);

-- 4)
SELECT 
    player_name,
    team,
    day,
    score_points,
    (SELECT SUM(score_points)
     FROM Scores 
     WHERE team = Scores.team 
     AND day <= Scores.day
    ) AS total
FROM Scores
ORDER BY team, day;

-- 5)
SELECT first_name, last_name
FROM customer
WHERE address_id IN (
    SELECT address_id 
    FROM address 
    WHERE city_id IN (
        SELECT city_id 
        FROM city 
        WHERE city = 'London'
    )
);

-- 6)
SELECT title
FROM Films
WHERE running_time > (
    SELECT running_time
    FROM Films 
    WHERE show_date = DATE_SUB(Films.show_date, INTERVAL 1 DAY)
)
ORDER BY title;
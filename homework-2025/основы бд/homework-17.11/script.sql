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
SELECT DISTINCT Candidates.id
FROM Candidates
JOIN Rounds ON Candidates.interview_id = Rounds.interview_id
WHERE Candidates.years_of_exp >= 2
GROUP BY Candidates.id, Candidates.interview_id
HAVING SUM(Rounds.score) > 15;

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
FROM (
    SELECT 
        title,
        running_time,
        LAG(running_time) OVER (ORDER BY show_date) as prev_day_running_time
    FROM Films
) as film_stats
WHERE running_time > prev_day_running_time
ORDER BY title;
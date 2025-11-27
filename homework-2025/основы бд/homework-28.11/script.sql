--1
CREATE TABLE BlueLock_Players 
(
    player_id INT IDENTITY(1,1) NOT NULL PRIMARY KEY,
    name      VARCHAR(50)       NOT NULL UNIQUE,
    team      VARCHAR(20)       NOT NULL,
    goals     INT               NOT NULL DEFAULT 0
);
INSERT INTO BlueLock_Players (name, team, goals) VALUES
('Yoichi Isagi', 'Team Z', 8),
('Meguru Bachira', 'Team Z', 6),
('Rensuke Kunigami', 'Team Z', 5),
('Hyoma Chigiri', 'Team Z', 4),
('Wataru Kuon', 'Team Z', 2),
('Jingo Raichi', 'Team Z', 1),
('Yudai Imamura', 'Team Z', 0),
('Gin Gagamaru', 'Team Z', 0),
('Asahi Naruhaya', 'Team Z', 0),
('Okuhito Iemon', 'Team Z', 0);

-- Аркадий Игоревич, подъехали отсылки )

--2
SELECT 
    p1.name AS home_player,
    p2.name AS away_player
FROM BlueLock_Players p1
CROSS JOIN BlueLock_Players p2
WHERE p1.name != p2.name
ORDER BY p1.name, p2.name;

--3
SELECT 
    m.symbol AS metal,
    n.symbol AS nonmetal
FROM 
    (SELECT symbol FROM Elements WHERE type = 'metal') m
CROSS JOIN 
    (SELECT symbol FROM Elements WHERE type = 'nonmetal') n
ORDER BY 
    m.symbol, n.symbol;

--4
SELECT 
    c.name AS category_name,
    AVG(TIMESTAMPDIFF(HOUR, r.rental_date, r.return_date)) AS avg_rental_duration_hours
FROM 
    category c
    JOIN film_category fc ON c.category_id = fc.category_id
    JOIN film f ON fc.film_id = f.film_id
    JOIN inventory i ON f.film_id = i.film_id
    JOIN rental r ON i.inventory_id = r.inventory_id
WHERE 
    r.return_date IS NOT NULL
GROUP BY 
    c.category_id, c.name
ORDER BY 
    avg_rental_duration_hours DESC;
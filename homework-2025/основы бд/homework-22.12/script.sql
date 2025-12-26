--1
SELECT 
    airport_id
FROM (
    SELECT 
        airport_id,
        SUM(flights_count) AS total_traffic
    FROM (
        SELECT departure_airport AS airport_id, flights_count
        FROM Flights
        UNION ALL
        SELECT arrival_airport AS airport_id, flights_count
        FROM Flights
    ) AS AllAirports
    GROUP BY airport_id
) AS TrafficSummary

WHERE total_traffic = (
    SELECT MAX(total_traffic)
    FROM (
        SELECT 
            airport_id,
            SUM(flights_count) AS total_traffic
        FROM (
            SELECT departure_airport AS airport_id, flights_count
            FROM Flights
            
            UNION ALL
            
            SELECT arrival_airport AS airport_id, flights_count
            FROM Flights
        ) AS t1
        GROUP BY airport_id
    ) AS t2
)
ORDER BY airport_id;

--2
WITH CompanyTaxRates AS (
    SELECT 
        company_id,
        CASE
            WHEN MAX(salary) < 1000 THEN 0.00
            WHEN MAX(salary) BETWEEN 1000 AND 10000 THEN 0.24
            WHEN MAX(salary) > 10000 THEN 0.49
        END AS tax_rate
    FROM Salaries
    GROUP BY company_id
)
SELECT 
    employee_id AS id,
    employee_name AS name,
    ROUND(salary * (1 - tax_rate)) AS salary
FROM Salaries s
JOIN CompanyTaxRates ctr ON s.company_id = ctr.company_id
ORDER BY id;

--3
WITH VoterVotes AS (
    SELECT 
        voter,
        COUNT(candidate) AS candidate_count
    FROM Votes
    GROUP BY voter
), CandidateScores AS (
    SELECT 
        v.candidate,
        SUM(1.0 / vv.candidate_count) AS total_votes
    FROM Votes v
    JOIN VoterVotes vv ON v.voter = vv.voter
    WHERE v.candidate IS NOT NULL
    GROUP BY v.candidate
), MaxVotes AS (
    SELECT MAX(total_votes) AS max_votes
    FROM CandidateScores
)
SELECT 
    candidate
FROM CandidateScores cs
JOIN MaxVotes mv ON cs.total_votes = mv.max_votes;

--4
WITH PassengerBus AS (
    SELECT 
        p.id AS passenger_id,
        p.arrival_time,
        MIN(b.id) AS bus_id
    FROM Passengers p
    JOIN Buses b ON b.departure_time >= p.arrival_time
    GROUP BY p.id, p.arrival_time
)
SELECT 
    b.id AS bus_id,
    COUNT(pb.passenger_id) AS passenger_count
FROM Buses b
LEFT JOIN PassengerBus pb ON b.id = pb.bus_id
GROUP BY b.id
ORDER BY b.id;

--5
CREATE TABLE Numbers (
    num INT
);
INSERT INTO Numbers (num) 
VALUES (1), (5), (3), (7), (2);

--6
WITH RECURSIVE AllNumbers AS (
    SELECT MIN(num) AS num
    FROM Numbers
    UNION ALL
    SELECT num + 1
    FROM AllNumbers
    WHERE num < (SELECT MAX(num) FROM Numbers)
)
SELECT num
FROM AllNumbers
ORDER BY num;
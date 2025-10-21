1)
SELECT 
    CONCAT(name, ' ', surname) AS staffer,
    SEC_TO_TIME(
        TIME_TO_SEC(TIMEDIFF(work_end, work_start)) - 
        TIME_TO_SEC(TIMEDIFF(break_end, break_start))
    ) AS work_time
FROM 
    Staff
ORDER BY 
    work_time DESC,
    staffer ASC;
2)
SELECT 
    name,
    TIMEDIFF(rent_end, rent_start) AS rent_time,
    CONCAT(FLOOR(TIME_TO_SEC(TIMEDIFF(rent_end, rent_start)) / 3600) * 10, '€') AS rent_amount
FROM 
    Rental
WHERE 
    car_brand = 'BMW'
ORDER BY 
    rent_time ASC,
    name ASC;
3)
SELECT 
    task,
    executor,
    DATEDIFF(task_end, task_start) + 1 AS days_spent
FROM 
    Tasks
ORDER BY 
    days_spent DESC
LIMIT 1;
USE EducationPlatform;
GO

-- 1 --
SELECT Email, LastName, FirstName FROM Students;

SELECT Price, Title FROM Courses WHERE Price <= 0 ORDER BY Title ASC;

SELECT a.FirstName, a.LastName, a.Bio FROM Authors AS a;

-- 2 --
SELECT FirstName, LastName, Country, IsPremium 
FROM Students 
WHERE IsPremium = 1 AND (Country = N'Россия' OR Country = 'Russia');

SELECT Title, DurationHours, DifficultyLevel 
FROM Courses 
WHERE DurationHours >= 21 AND DifficultyLevel LIKE 'Beginner';

SELECT Comment, ReviewDate 
FROM Reviews 
WHERE Rating >= 5 
ORDER BY 2;

SELECT FirstName, LastName, BirthDate 
FROM Students 
WHERE YEAR(BirthDate) >= 2001;

-- 3 --
SELECT Title, Price FROM Courses ORDER BY 2 DESC;

SELECT FirstName, LastName FROM Students ORDER BY LastName ASC, FirstName ASC;

SELECT TOP 5 Title, DurationHours FROM Courses ORDER BY DurationHours DESC;

-- 4 --
SELECT Authors.FirstName, Authors.LastName, Courses.Title AS CourseName
FROM Authors
INNER JOIN Courses ON Authors.AuthorID = Courses.AuthorID;

SELECT st.FirstName, st.LastName, crs.Title AS CourseName
FROM Students st
JOIN Subscriptions sb ON st.StudentID = sb.StudentID
JOIN Courses crs ON sb.CourseID = crs.CourseID;

SELECT st.FirstName, st.LastName, crs.Title AS CourseName, vw.DeviceType
FROM Views vw
JOIN Students st ON vw.StudentID = st.StudentID
JOIN Subscriptions sb ON st.StudentID = sb.StudentID
JOIN Courses crs ON sb.CourseID = crs.CourseID;

SELECT st.FirstName, st.LastName, crs.Title AS CourseName, rv.Rating, rv.Comment
FROM Reviews rv
JOIN Students st ON rv.StudentID = st.StudentID
JOIN Subscriptions sb ON st.StudentID = sb.StudentID
JOIN Courses crs ON sb.CourseID = crs.CourseID;

-- 5 --
SELECT Country, COUNT(StudentID) AS TotalStudents 
FROM Students 
GROUP BY Country 
ORDER BY COUNT(StudentID) DESC;

SELECT c.Title, COUNT(sub.SubscriptionID) AS TotalSubs 
FROM Courses c
JOIN Subscriptions sub ON c.CourseID = sub.CourseID
WHERE sub.IsActive = 1
GROUP BY c.Title;

SELECT c.Title, AVG(CAST(r.Rating AS FLOAT)) AS AvgRating 
FROM Courses c
JOIN Reviews r ON c.CourseID = r.CourseID
GROUP BY c.Title;

SELECT DeviceType, COUNT(ViewID) AS Amount 
FROM Views 
GROUP BY DeviceType;

SELECT a.AuthorID, a.FirstName, a.LastName, COUNT(c.CourseID) AS TotalCourses 
FROM Authors a
LEFT JOIN Courses c ON a.AuthorID = c.AuthorID
GROUP BY a.AuthorID, a.FirstName, a.LastName;

-- 6 --
SELECT s.FirstName, s.LastName, COUNT(v.ViewID) AS TotalViews
FROM Students s
LEFT JOIN Views v ON s.StudentID = v.StudentID
GROUP BY s.FirstName, s.LastName;

SELECT c.Title, AVG(v.DurationMinutes * 1.0) AS AverageDuration 
FROM Courses c
JOIN Views v ON c.CourseID = v.CourseID
GROUP BY c.Title;

SELECT MIN(Price) AS MinPrice, MAX(Price) AS MaxPrice 
FROM dbo.Courses;

SELECT c.Title, COUNT(r.ReviewID) AS TotalReviews, AVG(r.Rating) AS AverageRating
FROM Courses c
JOIN Reviews r ON c.CourseID = r.CourseID
GROUP BY c.Title;

-- 7 --
SELECT TOP (3) c.CourseID, c.Title, COUNT(sub.SubscriptionID) AS SubCount
FROM Courses c
JOIN Subscriptions sub ON c.CourseID = sub.CourseID
GROUP BY c.CourseID, c.Title
ORDER BY SubCount DESC;

SELECT s.StudentID, s.FirstName, s.LastName, COUNT(sub.SubscriptionID) AS ActiveSubscriptions
FROM Students s
JOIN Subscriptions sub ON s.StudentID = sub.StudentID
WHERE sub.IsActive = 1
GROUP BY s.StudentID, s.FirstName, s.LastName
HAVING COUNT(sub.SubscriptionID) > 2;

SELECT c.CourseID, c.Title, AVG(r.Rating * 1.0) AS AvgRating
FROM Courses c
JOIN Reviews r ON c.CourseID = r.CourseID
GROUP BY c.CourseID, c.Title
HAVING AVG(r.Rating) > 4;

SELECT a.AuthorID, a.FirstName, a.LastName, COUNT(c.CourseID) AS CourseCount
FROM Authors a
JOIN Courses c ON a.AuthorID = c.AuthorID
GROUP BY a.AuthorID, a.FirstName, a.LastName
ORDER BY CourseCount DESC;

-- 8 --
SELECT *
FROM Subscriptions
WHERE ExpirationDate >= CAST('2026-07-01' AS DATE);

SELECT *
FROM Students
WHERE DATEPART(YEAR, RegistrationDate) = 2026;

SELECT 
    DATEPART(YEAR, ViewDate) AS ViewYear,
    DATEPART(MONTH, ViewDate) AS ViewMonth,
    COUNT(ViewID) AS ViewCount
FROM Views
GROUP BY DATEPART(YEAR, ViewDate), DATEPART(MONTH, ViewDate)
ORDER BY ViewYear, ViewMonth;

SELECT *
FROM Subscriptions
WHERE ExpirationDate IS NOT NULL
  AND ExpirationDate <= DATEADD(DAY, 30, GETDATE())
  AND ExpirationDate >= GETDATE();

-- 9 --
SELECT StudentID, FirstName, LastName,
    CASE IsPremium
        WHEN 1 THEN N'Премиум'
        ELSE N'Обычный'
    END AS StudentStatus
FROM Students;

SELECT CourseID, Title, Price,
    IIF(Price = 0, N'Бесплатный', N'Платный') AS CourseType
FROM Courses;

SELECT DISTINCT s.StudentID, s.FirstName, s.LastName
FROM Students s
WHERE EXISTS (SELECT 1 FROM Views v WHERE v.StudentID = s.StudentID)
  AND NOT EXISTS (SELECT 1 FROM Reviews r WHERE r.StudentID = s.StudentID);

-- 10 --
WITH ViewStats AS (
    SELECT StudentID, COUNT(ViewID) AS Cnt
    FROM Views
    GROUP BY StudentID
)
SELECT s.StudentID, s.FirstName, s.LastName, vs.Cnt AS ViewCount
FROM Students s
JOIN ViewStats vs ON s.StudentID = vs.StudentID
WHERE vs.Cnt > (SELECT AVG(Cnt) FROM ViewStats);

WITH Subs AS (
    SELECT CourseID, COUNT(SubscriptionID) AS SubCnt
    FROM Subscriptions
    GROUP BY CourseID
),
Rats AS (
    SELECT CourseID, AVG(Rating * 1.0) AS AvgRat
    FROM Reviews
    GROUP BY CourseID
),
Vws AS (
    SELECT CourseID, SUM(DurationMinutes) AS SumDur
    FROM Views
    GROUP BY CourseID
)
SELECT 
    c.CourseID,
    c.Title,
    ISNULL(s.SubCnt, 0) AS SubscriptionCount,
    ISNULL(r.AvgRat, 0) AS AvgRating,
    ISNULL(v.SumDur, 0) AS TotalDurationMinutes
FROM Courses c
LEFT JOIN Subs s ON c.CourseID = s.CourseID
LEFT JOIN Rats r ON c.CourseID = r.CourseID
LEFT JOIN Vws v ON c.CourseID = v.CourseID
ORDER BY c.CourseID;

SELECT DISTINCT s.StudentID, s.FirstName, s.LastName
FROM Students s
WHERE EXISTS (SELECT 1 FROM Subscriptions sub WHERE sub.StudentID = s.StudentID)
  AND NOT EXISTS (SELECT 1 FROM Views v WHERE v.StudentID = s.StudentID);

SELECT 
    a.AuthorID,
    CONCAT(a.FirstName, N' ', a.LastName) AS AuthorName,
    COUNT(DISTINCT c.CourseID) AS CourseCount,
    COUNT(DISTINCT s.StudentID) AS TotalStudents
FROM Authors a
LEFT JOIN Courses c ON a.AuthorID = c.AuthorID
LEFT JOIN Subscriptions s ON c.CourseID = s.CourseID
GROUP BY a.AuthorID, a.FirstName, a.LastName
ORDER BY CourseCount DESC, AuthorName;
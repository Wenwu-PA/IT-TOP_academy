CREATE TABLE Films(
    id           INTEGER PRIMARY KEY,
    title        TEXT,
    director     TEXT,
    release_date YEAR,
);

INSERT INTO Films (id, title, director, release_date,)
VALUES (1,'The Incredibles', 'Brad Bird', '2004'),
       (2,'WALL-E', 'Andrew Stanton', '2008'),
       (3,'Inside Out', 'Pete Docter', '2015'),
       (4,'The Good Dinosaur', 'Peter Sohn', '2015'),
       (5,'Ratatouille', 'Brad Bird', '2007');
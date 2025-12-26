-- 1
CREATE TABLE Users (
    id INT PRIMARY KEY,
    name VARCHAR(50) NOT NULL,
    surname VARCHAR(50) NOT NULL,
    email VARCHAR(100) NOT NULL UNIQUE
);
CREATE TABLE UsersEmailHistory (
    log_id INT PRIMARY KEY AUTO_INCREMENT,
    user_id INT NOT NULL,
    old_email VARCHAR(100),
    new_email VARCHAR(100) NOT NULL,
    updated_on DATE NOT NULL,
    FOREIGN KEY (user_id) REFERENCES Users(id)
);

-- 2
DELIMITER $$

CREATE TRIGGER after_users_email_update
AFTER UPDATE ON Users
FOR EACH ROW
BEGIN
    IF OLD.email <> NEW.email THEN
        INSERT INTO UsersEmailHistory (user_id, old_email, new_email, updated_on)
        VALUES (OLD.id, OLD.email, NEW.email, CURDATE());
    END IF;
END$$

DELIMITER;

-- 3
DELIMITER $$

CREATE TRIGGER after_purchase_insert
AFTER INSERT ON Purchases
FOR EACH ROW
BEGIN
    DECLARE film_price DECIMAL(5, 2);
    SELECT price INTO film_price
    FROM Films
    WHERE id = NEW.film_id;
    UPDATE Users
    SET total_spending = total_spending + film_price
    WHERE id = NEW.user_id;
END$$

DELIMITER;
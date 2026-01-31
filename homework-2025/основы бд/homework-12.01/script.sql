--1
DELIMITER $$
CREATE FUNCTION NON_SPACE_CHARACTERS(string VARCHAR(1000))
RETURNS INT
DETERMINISTIC
BEGIN
    DECLARE result INT;

    SET result = CHAR_LENGTH(REPLACE(string, ' ', ''));
    
    RETURN result;
END$$

DELIMITER;

SELECT NON_SPACE_CHARACTERS(' Bee Geek ');

--2
DELIMITER $$

CREATE FUNCTION SAME_DIGITS(number INT)
RETURNS INT
DETERMINISTIC
BEGIN

    RETURN CASE 
        WHEN REPLACE(CAST(number AS CHAR), LEFT(CAST(number AS CHAR), 1), '') = '' 
        THEN 1 
        ELSE 0 
    END;
END$$

DELIMITER;

--3
DELIMITER $$

CREATE FUNCTION CALCULATE(a FLOAT, b FLOAT, operation CHAR(1))
RETURNS FLOAT
DETERMINISTIC
BEGIN
    DECLARE result FLOAT;
    
    CASE operation
        WHEN '+' THEN SET result = a + b;
        WHEN '-' THEN SET result = a - b;
        WHEN '*' THEN SET result = a * b;
        WHEN '/' THEN SET result = a / b;
        ELSE SET result = NULL;
    END CASE;
    
    RETURN result;
END$$

DELIMITER;
--4
DELIMITER $$

CREATE FUNCTION MIDDLE_POINT(x1 INT, y1 INT, x2 INT, y2 INT)
RETURNS VARCHAR(50)
DETERMINISTIC
BEGIN
    DECLARE mid_x FLOAT;
    DECLARE mid_y FLOAT;
    SET mid_x = (x1 + x2) / 2.0;
    SET mid_y = (y1 + y2) / 2.0;
    RETURN CONCAT('(', FORMAT(mid_x, 1), '; ', FORMAT(mid_y, 1), ')');
END$$

DELIMITER;

--5
DELIMITER $$

CREATE FUNCTION LAST_SECOND_DIGIT(number INT)
RETURNS INT
DETERMINISTIC
BEGIN
    DECLARE num_str VARCHAR(20);
    DECLARE str_len INT;
    
    -- Преобразуем число в строку
    SET num_str = CAST(number AS CHAR);
    SET str_len = CHAR_LENGTH(num_str);
    
    -- Проверяем, что число имеет как минимум 2 цифры
    IF str_len >= 2 THEN
        -- Возвращаем предпоследнюю цифру (вторая с конца)
        RETURN CAST(SUBSTRING(num_str, str_len - 1, 1) AS UNSIGNED);
    ELSE
        -- Для однозначных чисел возвращаем NULL
        RETURN NULL;
    END IF;
END$$

DELIMITER;


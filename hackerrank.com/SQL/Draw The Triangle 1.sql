DECLARE @stars INT;
SET @stars = 20;

WHILE @stars > 0
    BEGIN
        PRINT(REPLICATE('* ', @stars))
        SET @stars = @stars - 1
    END
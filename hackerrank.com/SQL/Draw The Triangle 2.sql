DECLARE @stars INT;
SET @stars = 1;

WHILE @stars <= 20
    BEGIN
        PRINT(REPLICATE('* ', @stars))
        SET @stars = @stars + 1;    
    END
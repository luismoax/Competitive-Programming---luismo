DECLARE @lim INT
DECLARE @i INT
DECLARE @k INT
DECLARE @answ VARCHAR(1000)


SET @lim = 1000
SET @i = 3
SET @k = 2

SET @answ = '2'

WHILE @i < @lim	
	BEGIN
	SET @k = 2
		WHILE (@k <= @i)
			BEGIN
				IF (@i % @k) = 0
					-- if prime number
					IF (@i - @k) = 0
						BEGIN						
							SET @answ = CONCAT(@answ, '&', @i)
						END
					-- if not a prime number
					ELSE SET @k = @i				
				SET @k = @k + 1
			END	
	SET @i = @i + 1  	
	END
	
PRINT @answ


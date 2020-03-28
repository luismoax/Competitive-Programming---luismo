SELECT  CAST(ROUND(SQRT( (a-c)*(a-c) + (b-d)*(b-d)) , 4) AS DECIMAL(9,4)) 
FROM
(
    SELECT  
            ROUND(MIN(LAT_N), 4) AS a,
            ROUND(MIN(LONG_W), 4) AS b,
            ROUND(MAX(LAT_N), 4) AS c,
            ROUND(MAX(LONG_W), 4) AS d    
    FROM    STATION
) AS Q
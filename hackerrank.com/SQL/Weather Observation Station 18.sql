SELECT  CAST(ROUND((c - a) + (d - b), 4) AS FLOAT)
FROM
(
    SELECT  
            ROUND(MIN(LAT_N), 4) AS a,
            ROUND(MIN(LONG_W), 4) AS b,
            ROUND(MAX(LAT_N), 4) AS c,
            ROUND(MAX(LONG_W), 4) AS d    
    FROM    STATION
) AS Q
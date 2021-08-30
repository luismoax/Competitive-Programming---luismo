SELECT
     CAST(SUM(LAT_N)  AS DECIMAL(18, 2)) AS Lat
    ,CAST(SUM(LONG_W) AS DECIMAL(18, 2))  AS Lon
FROM STATION
    
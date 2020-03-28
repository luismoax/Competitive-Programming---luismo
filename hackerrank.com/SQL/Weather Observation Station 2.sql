-- in order to keep track of the last two values the result was casted as a decimal(12,2)
SELECT  CAST( ROUND(SUM(LAT_N), 2) AS DECIMAL(12,2) ) AS lat,
        CAST( ROUND(SUM(LONG_W), 2) AS DECIMAL(12,2) ) AS lon
FROM    STATION
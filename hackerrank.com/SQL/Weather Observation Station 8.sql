SELECT
    DISTINCT [City]
FROM
    STATION
WHERE 1 = 1
    AND LEFT(City, 1) IN ('a', 'e', 'i', 'o', 'u')
    AND RIGHT(City, 1) IN ('a', 'e', 'i', 'o', 'u')
SELECT
    DISTINCT [City]
FROM
    STATION
WHERE 1 = 1
    AND LEFT(City, 1) NOT IN ('a', 'e', 'i', 'o', 'u')
    OR RIGHT(City, 1) NOT IN ('a', 'e', 'i', 'o', 'u')
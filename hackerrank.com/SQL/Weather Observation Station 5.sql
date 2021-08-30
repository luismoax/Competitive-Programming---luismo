WITH NameAndLength AS
(
SELECT
    [City]
    ,LEN([City]) AS [Lenght]
FROM
    STATION
)

SELECT 
    *
FROM
(
    SELECT TOP 1
        *
    FROM
        NameAndLength
    ORDER BY [Lenght] ASC, [City] ASC
) AS Q

UNION

SELECT
    *
FROM
(
    SELECT TOP 1
        *
    FROM
        NameAndLength
    ORDER BY [Lenght] DESC, [City] ASC
) AS F
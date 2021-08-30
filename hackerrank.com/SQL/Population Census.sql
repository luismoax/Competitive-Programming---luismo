SELECT
    SUM([city].[POPULATION])
FROM
    CITY [city]
INNER JOIN
    COUNTRY [country] ON [city].[COUNTRYCODE] = [country].[CODE]
WHERE 1 = 1
    AND [country].[CONTINENT] = 'ASIA'
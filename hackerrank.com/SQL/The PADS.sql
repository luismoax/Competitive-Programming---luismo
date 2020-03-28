SELECT      CONCAT(O.Name, '(', LEFT(O.Occupation,1), ')') AS Q
FROM        OCCUPATIONS O
ORDER BY    O.Name;

SELECT      CONCAT('There are a total of ', COUNT(O.Occupation), ' ', LOWER(O.Occupation), 's.')
FROM        OCCUPATIONS O
GROUP BY    O.Occupation
ORDER BY    COUNT(O.Occupation) ASC, O.Occupation ASC;
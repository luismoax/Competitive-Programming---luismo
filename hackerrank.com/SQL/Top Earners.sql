SELECT  TOP 1 (salary * months), COUNT(*)
FROM    Employee
GROUP BY (salary * months)
ORDER BY (salary * months) DESC
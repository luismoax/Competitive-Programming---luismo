;WITH StudentSalary ([Id], [Salary])
AS
(
    SELECT  s.[Id], p.[Salary]
    FROM    Students s
            INNER JOIN Packages p ON s.Id = p.Id
        
)
SELECT  s.[Name]
FROM    Students s
        INNER JOIN Packages p ON s.Id = p.Id
        INNER JOIN Friends f ON s.Id = f.Id
        LEFT OUTER JOIN StudentSalary ss ON ss.[Id] = f.[Friend_Id] AND ss.[Salary] > p.[Salary]
WHERE   ss.Id IS NOT NULL
ORDER BY ss.[Salary] 
    SELECT  
            CASE 
                WHEN g.[Grade] < 8 THEN 'NULL' 
                ELSE s.[Name] 
            END AS [Name],
            g.[Grade] AS [Grade],
            s.[Marks]           

    FROM    Students  s, Grades g
    WHERE   s.Marks >= g.Min_Mark and s.Marks <= g.Max_Mark
    ORDER BY g.[Grade] DESC, s.[Name] ASC, s.[Marks] ASC
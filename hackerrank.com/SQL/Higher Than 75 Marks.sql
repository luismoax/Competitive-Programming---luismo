SELECT
    [stu].[Name]
FROM
    STUDENTS [stu]
WHERE Marks > 75
ORDER BY RIGHT([stu].[Name], 3) ASC, [stu].[ID] ASC
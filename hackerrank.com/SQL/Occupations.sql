-- This is a nice Challenge, had to use ROW_NUMBER and PIVOT together
SELECT
        [Doctor],
        [Professor],
        [Singer],
        [Actor]
FROM
(
    SELECT  *
    FROM
    (
        -- Pick numbered name and occupation (ordered by Name) 
        SELECT
                ROW_NUMBER() OVER (PARTITION BY Occupation ORDER BY [Name]) AS [RowNumber],
                [Name],
                [Occupation]
        FROM    Occupations
    ) NumberedNameOccupation
    PIVOT
    (
        MAX(NumberedNameOccupation.Name)
        FOR NumberedNameOccupation.Occupation
        IN
        (
            [Doctor],
            [Professor],
            [Singer],
            [Actor]
        )
    ) pivoted
) AS Answer
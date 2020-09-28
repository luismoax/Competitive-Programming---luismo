-- Tough one
;WITH AllDates (Date)
AS
(
    -- Start Dates
    SELECT  p.End_Date AS [Date]
    FROM    Projects p
            LEFT OUTER JOIN Projects ri ON DATEDIFF(day,  p.End_Date, ri.End_Date) = 1
    WHERE   ri.End_Date IS NULL

    UNION
    -- End Dates
    SELECT  p.Start_Date AS [Date]
    FROM    Projects p
            LEFT OUTER JOIN Projects le ON DATEDIFF(day, le.Start_Date, p.Start_Date) = 1
    WHERE   le.Start_Date IS NULL
),
BeginDates (Date)
AS
(
    -- Start Dates
    SELECT  p.Start_Date AS [Date]
    FROM    Projects p
            LEFT OUTER JOIN Projects le ON DATEDIFF(day, le.Start_Date, p.Start_Date) = 1
    WHERE   le.Start_Date IS NULL    
),
BegMinDiff ([Date], [Diff])
AS
(    
    SELECT      aa.[Date], 
                MIN(DATEDIFF(day, aa.[Date], bb.[Date])) [Diff]
    FROM        AllDates aa
                CROSS JOIN AllDates bb
    WHERE       DATEDIFF(day, aa.[Date], bb.[Date]) > 0
    GROUP BY    aa.[Date]
)
SELECT  bd.[Date] [Start], DATEADD(day, bmd.[Diff], bd.[Date]) [End]
FROM    BegMinDiff bmd
        INNER JOIN BeginDates bd ON bmd.[Date] = bd.[Date]
ORDER BY DATEDIFF(day, DATEADD(day, bmd.[Diff], bd.[Date]), bd.[Date]) DESC, bd.[Date]

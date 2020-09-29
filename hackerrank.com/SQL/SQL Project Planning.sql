;WITH EndDates (Date)
AS
(
    -- End Dates
    SELECT  p.End_Date AS [Date]
    FROM    Projects p
            LEFT OUTER JOIN Projects ri ON DATEDIFF(day,  p.End_Date, ri.End_Date) = 1
    WHERE   ri.End_Date IS NULL
),
StartDates (Date)
AS
(
    -- Start Dates
    SELECT  p.Start_Date AS [Date]
    FROM    Projects p
            LEFT OUTER JOIN Projects le ON DATEDIFF(day, le.Start_Date, p.Start_Date) = 1
    WHERE   le.Start_Date IS NULL    
),
-- project start and end
ProjectIntervals ([Start], [End])
AS
(
    -- Cross Join starts, with ends (with start < end) and pick the minimun end which is after each start
    SELECT      sd.[Date], MIN(ed.[Date])
    FROM        StartDates sd
                CROSS JOIN
                EndDates ed
    WHERE       sd.[Date] <= ed.[Date]
    GROUP BY    sd.[Date] -- group  by starting dates
)
SELECT      *
FROM        ProjectIntervals pi
ORDER BY    DATEDIFF(day, pi.[Start], pi.[End]), pi.[Start] -- order by given criteria

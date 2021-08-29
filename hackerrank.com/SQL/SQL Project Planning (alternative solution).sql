WITH Ends AS
(
    SELECT
        pro.[End_Date]
        ,'End' [Type] 
        ,ROW_NUMBER() OVER (ORDER BY pro.[End_Date] ASC) AS [Row]
    FROM
        Projects AS pro    
    WHERE pro.[End_Date] NOT IN
        (
            SELECT
            DISTINCT [Start_date]
            FROM Projects
         )
),
Starts AS
(
    SELECT
        pro.[Start_Date]
        ,'Start' [Type]
        ,ROW_NUMBER() OVER (ORDER BY pro.[Start_Date] ASC) AS [Row]
    FROM
        Projects AS pro
    WHERE pro.[Start_Date] NOT IN
        (            
            SELECT
            DISTINCT [End_Date]
            FROM Projects
         )
)
SELECT 
    Starts.[Start_Date]
    ,Ends.[End_Date]
FROM 
    Starts
INNER JOIN
    Ends ON Starts.[Row] = Ends.[Row]
ORDER BY
    DATEDIFF(day, Starts.[Start_Date], Ends.[End_Date]) ASC, Starts.[Start_Date] ASC

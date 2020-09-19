;WITH 
TotalCnt
AS
(
    SELECT COUNT(*) cnt FROM STATION    
),
NumberedRows
AS
(
    SELECT  ROW_NUMBER() OVER(ORDER BY LAT_N ASC) - 1 AS RN,
            LAT_N
    FROM    STATION
),
LeftMid
AS
(
    SELECT  LAT_N
    FROM    NumberedRows, TotalCnt
    WHERE   RN = TotalCnt.cnt / 2
),
RightMid
AS
(
    SELECT  LAT_N
    FROM    NumberedRows, TotalCnt
    WHERE   RN = TotalCnt.cnt / 2 + 1
)
SELECT  
        CASE
            WHEN TotalCnt.cnt % 2 = 1 THEN CAST( LEftMid.Lat_N AS DECIMAL(18, 4))
            ELSE CAST( (LeftMid.Lat_N + RightMid.Lat_N) / 2 AS DECIMAL(18, 4))
        END
FROM    TotalCnt, LeftMid, RightMid
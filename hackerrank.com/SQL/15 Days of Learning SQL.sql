
DECLARE @dp AS TABLE
(
    [submission_date] [DATE],
    [hacker_id] INT,
    [cnt] INT
)
INSERT INTO @dp
SELECT  s.submission_date, s.hacker_id, COUNT(*) AS cnt
FROM    Hackers h 
        INNER JOIN Submissions s ON h.hacker_id = s.hacker_id
GROUP BY s.submission_date, s.hacker_id

DECLARE @consec AS TABLE
(
    [submission_date] [DATE],
    [hacker_id] INT
)

INSERT INTO @consec
SELECT  DISTINCT [submission_date], [hacker_id]
FROM    Submissions s
WHERE   s.[submission_date] = '2016-03-01';

INSERT INTO @consec
SELECT  [submission_date], [hacker_id]
FROM    Submissions s
WHERE   s.[submission_date] = '2016-03-02' AND hacker_id IN
        (
            SELECT DISTINCT [hacker_id]
            FROM   @consec
            WHERE  [submission_date] = '2016-03-01'
        );
INSERT INTO @consec
SELECT  [submission_date], [hacker_id]
FROM    Submissions s
WHERE   s.[submission_date] = '2016-03-03' AND hacker_id IN
        (
            SELECT DISTINCT [hacker_id]
            FROM   @consec
            WHERE  [submission_date] = '2016-03-02'
        );
INSERT INTO @consec
SELECT  [submission_date], [hacker_id]
FROM    Submissions s
WHERE   s.[submission_date] = '2016-03-04' AND hacker_id IN
        (
            SELECT DISTINCT [hacker_id]
            FROM   @consec
            WHERE  [submission_date] = '2016-03-03'
        );
INSERT INTO @consec
SELECT  [submission_date], [hacker_id]
FROM    Submissions s
WHERE   s.[submission_date] = '2016-03-05' AND hacker_id IN
        (
            SELECT DISTINCT [hacker_id]
            FROM   @consec
            WHERE  [submission_date] = '2016-03-04'
        );
INSERT INTO @consec
SELECT  [submission_date], [hacker_id]
FROM    Submissions s
WHERE   s.[submission_date] = '2016-03-06' AND hacker_id IN
        (
            SELECT DISTINCT [hacker_id]
            FROM   @consec
            WHERE  [submission_date] = '2016-03-05'
        );
INSERT INTO @consec
SELECT  [submission_date], [hacker_id]
FROM    Submissions s
WHERE   s.[submission_date] = '2016-03-07' AND hacker_id IN
        (
            SELECT DISTINCT [hacker_id]
            FROM   @consec
            WHERE  [submission_date] = '2016-03-06'
        );
INSERT INTO @consec
SELECT  [submission_date], [hacker_id]
FROM    Submissions s
WHERE   s.[submission_date] = '2016-03-08' AND hacker_id IN
        (
            SELECT DISTINCT [hacker_id]
            FROM   @consec
            WHERE  [submission_date] = '2016-03-07'
        );
INSERT INTO @consec
SELECT  [submission_date], [hacker_id]
FROM    Submissions s
WHERE   s.[submission_date] = '2016-03-09' AND hacker_id IN
        (
            SELECT DISTINCT [hacker_id]
            FROM   @consec
            WHERE  [submission_date] = '2016-03-08'
        );
INSERT INTO @consec
SELECT  [submission_date], [hacker_id]
FROM    Submissions s
WHERE   s.[submission_date] = '2016-03-10' AND hacker_id IN
        (
            SELECT DISTINCT [hacker_id]
            FROM   @consec
            WHERE  [submission_date] = '2016-03-09'
        );
INSERT INTO @consec
SELECT  [submission_date], [hacker_id]
FROM    Submissions s
WHERE   s.[submission_date] = '2016-03-11' AND hacker_id IN
        (
            SELECT DISTINCT [hacker_id]
            FROM   @consec
            WHERE  [submission_date] = '2016-03-10'
        );
INSERT INTO @consec
SELECT  [submission_date], [hacker_id]
FROM    Submissions s
WHERE   s.[submission_date] = '2016-03-12' AND hacker_id IN
        (
            SELECT DISTINCT [hacker_id]
            FROM   @consec
            WHERE  [submission_date] = '2016-03-11'
        );
INSERT INTO @consec
SELECT  [submission_date], [hacker_id]
FROM    Submissions s
WHERE   s.[submission_date] = '2016-03-13' AND hacker_id IN
        (
            SELECT DISTINCT [hacker_id]
            FROM   @consec
            WHERE  [submission_date] = '2016-03-12'
        );
INSERT INTO @consec
SELECT  [submission_date], [hacker_id]
FROM    Submissions s
WHERE   s.[submission_date] = '2016-03-14' AND hacker_id IN
        (
            SELECT DISTINCT [hacker_id]
            FROM   @consec
            WHERE  [submission_date] = '2016-03-13'
        );
INSERT INTO @consec
SELECT  [submission_date], [hacker_id]
FROM    Submissions s
WHERE   s.[submission_date] = '2016-03-15' AND hacker_id IN
        (
            SELECT DISTINCT [hacker_id]
            FROM   @consec
            WHERE  [submission_date] = '2016-03-14'
        );
        
-- Query
SELECT  F.submission_date, K.[hackers_total], F.[hacker_id], h.[name]
FROM    Hackers h
        INNER JOIN
        (
            SELECT  dp.submission_date, MIN(dp.hacker_id) [hacker_id], dp.[cnt]
            FROM    @dp dp
                    INNER JOIN
                    (
                        SELECT      dp.[submission_date], MAX(dp.cnt) [MaxCnt]
                        FROM        @dp dp
                        GROUP BY    dp.[submission_date]         
                    ) Q ON Q.submission_date = dp.submission_date AND Q.[MaxCnt] = dp.[cnt]
            GROUP BY dp.submission_date, dp.[cnt]
        ) F on h.hacker_id = F.hacker_id
        INNER JOIN 
        (
            SELECT  [submission_date], COUNT(DISTINCT(hacker_id)) [hackers_total]
            FROM    @consec
            GROUP   BY [submission_date]
        ) K ON K.submission_date = F.submission_date
ORDER BY F.submission_date
-- luismo
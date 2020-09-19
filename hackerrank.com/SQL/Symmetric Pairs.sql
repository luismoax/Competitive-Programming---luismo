SELECT  *
FROM
(
    -- pick pairs with distinct x and y
    SELECT  f1.X, f1.Y
    FROM    Functions f1
            INNER JOIN Functions f2 ON f1.X = f2.Y AND f1.Y = f2.X AND f1.X < f1.Y

    UNION   

    -- pick repeated pairs with same x and y
    SELECT      f.X, f.Y
    FROM        Functions f
    WHERE       f.X = f.Y
    GROUP BY    f.X, f.Y
    HAVING      COUNT(*) > 1
    
) AS Q
ORDER BY Q.X, Q.Y
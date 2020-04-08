SELECT	M.hacker_id, M.name, M.cnt
FROM
(
    SELECT *
    FROM
    (
        SELECT      h.hacker_id, h.name, COUNT(*) cnt
        FROM        Hackers h
                    INNER JOIN Challenges c ON h.hacker_id = c.hacker_id
        GROUP BY    h.hacker_id, h.name
    ) AS Q
    WHERE Q.cnt = 
            (
                SELECT          MAX(F.cnt)
                FROM
                (
                    SELECT      COUNT(*) AS cnt
                    FROM        Hackers h
                                INNER JOIN Challenges c ON h.hacker_id = c.hacker_id
                    GROUP BY    h.hacker_id
                ) AS F
            )

    UNION

    SELECT	MAX(Q.hacker_id), MAX(Q.name), Q.cnt
    FROM
    (
        SELECT      h.hacker_id, h.name, COUNT(*) cnt
        FROM        Hackers h
                    INNER JOIN Challenges c ON h.hacker_id = c.hacker_id
        GROUP BY    h.hacker_id, h.name
    ) AS Q
    GROUP BY Q.cnt
    HAVING COUNT(*) = 1

) AS M
ORDER BY M.cnt DESC, M.hacker_id ASC
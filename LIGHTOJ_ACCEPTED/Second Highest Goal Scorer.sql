SELECT
    player
    ,team
    ,G.goals_scored
    ,played
FROM Goals G
    INNER JOIN
    (
        SELECT Q.goals_scored
        FROM
        (
            SELECT DISTINCT goals_scored
            FROM Goals
            ORDER BY goals_scored DESC
            Limit 2
        ) Q
        ORDER BY Q.goals_scored
        Limit 1
    ) F ON F.goals_scored = G.goals_scored
ORDER BY G.player
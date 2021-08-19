SELECT
    player
    ,team
    ,G.goals_scored
    ,played
FROM Goals G
    INNER JOIN
    (
        SELECT goals_scored
        FROM
            Goals 
        ORDER BY goals_scored DESC
        Limit 1
    ) F ON F.goals_scored = G.goals_scored
ORDER BY G.player
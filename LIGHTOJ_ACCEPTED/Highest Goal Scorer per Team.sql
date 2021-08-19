SELECT
    G.player
    ,G.team
    ,G.goals_scored
    ,G.played
FROM
    Goals G
INNER JOIN
    (
        SELECT
            Team
            ,MAX(Goals_Scored) AS Max_Goals_Scored
        FROM
            Goals
        GROUP BY Team
    ) AS 
    TH ON G.Team = TH.Team AND G.Goals_Scored = TH.Max_Goals_Scored
ORDER BY 
    G.Team
    ,G.Player

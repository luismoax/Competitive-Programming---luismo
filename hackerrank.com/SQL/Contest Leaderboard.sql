-- use a CTE to group by s.hacker_id, h.name, s.challenge_id and obtain
-- the MAX(score) being it greater than zero
;WITH CTEHackerChallengeMax (hackerid, name, challengeid, score)
AS
(
    SELECT      s.hacker_id, h.name, s.challenge_id, MAX(score)
    FROM        Hackers h
                INNER JOIN Submissions s ON H.hacker_id = s.hacker_id
    GROUP BY    s.hacker_id, h.name, s.challenge_id
    HAVING      MAX(score) > 0
)
SELECT      hackerid, name, SUM(score)
FROM        CTEHackerChallengeMax
GROUP BY    hackerid, name
ORDER BY    SUM(score) DESC, hackerid ASC
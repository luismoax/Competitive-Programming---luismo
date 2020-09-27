;WITH FullyScored (hacker_id, challenge_id, sub_id)
AS
(
    SELECT      h.hacker_id, c.challenge_id, MIN(s.submission_id)
    FROM        Hackers h
                INNER JOIN  Submissions s ON s.hacker_id = h.hacker_id
                INNER JOIN  Challenges c ON c.challenge_id = s.challenge_id
                INNER JOIN  Difficulty d ON d.difficulty_level = c.difficulty_level
    WHERE       d.score = s.Score
    GROUP BY    h.hacker_id, c.challenge_id    
)
SELECT      h.hacker_id, h.name
FROM        Hackers h
            INNER JOIN  FullyScored s ON s.hacker_id = h.hacker_id
            INNER JOIN  Challenges c ON c.challenge_id = s.challenge_id

GROUP BY    h.hacker_id, h.name
HAVING      COUNT(DISTINCT c.challenge_id) > 1
ORDER BY    COUNT(DISTINCT c.challenge_id) DESC, hacker_id ASC
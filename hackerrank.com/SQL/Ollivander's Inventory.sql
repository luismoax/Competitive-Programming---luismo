-- use a Common Table Expression, to group by age and power, and get the wand with minimmum coins needed
;WITH GroupedByPowerAndAge (age, power, coins_needed)
AS
(
    SELECT      wp.age, w.power, MIN(w.coins_needed)
    FROM        wands w
                INNER JOIN wands_property wp ON w.Code = wp.Code
    WHERE       wp.is_evil = 0
    GROUP BY    wp.age, w.power
)
SELECT      id, wp.age, w.coins_needed, w.power
FROM        wands w
            INNER JOIN wands_property wp ON w.Code = wp.Code
            INNER JOIN GroupedByPowerAndAge gbpa ON gbpa.age = wp.age AND gbpa.power = w.power
                        AND gbpa.coins_needed = w.coins_needed
ORDER BY    w.power DESC, wp.age DESC
-- LUISMO
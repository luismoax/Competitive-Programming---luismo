-- use an auxiliar table to insert the values
DECLARE @tt AS TABLE
(
    [Id] INT,
    [Type] VARCHAR(MAX) 
);

-- insert all nodes initially as leaf
INSERT INTO @tt
SELECT  [N], 'Leaf'
FROM    BST

-- update the ones which are father of some other node as Inner
UPDATE  @tt
SET     [Type] = 'Inner'
WHERE   [Id] IN
        (
            SELECT  DISTINCT [P]
            FROM    BST
        )
        
-- update the root which has no father
UPDATE  @tt
SET     [Type] = 'Root'
WHERE   [Id] = 
        (
            SELECT  [N]
            FROM    BST
            WHERE   [P] IS NULL
        )

SELECT      *
FROM        @tt
ORDER BY    [Id]
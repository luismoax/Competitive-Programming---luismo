SELECT     
    DISTINCT [node].N
    ,CASE
        WHEN [parent].N IS NULL THEN 'Root'
        WHEN [child].N IS NULL THEN 'Leaf'
        ELSE 'Inner'
    END AS [Type]
FROM
    BST [node]
LEFT JOIN
    BST [parent] ON [node].P = [parent].N
LEFT JOIN
    BST [child] ON [node].N = [child].P
ORDER BY [node].N ASC

SELECT  CAST
        (
            CEILING 
            (
                AVG(CAST(Salary AS FLOAT)) -
                AVG( CAST( REPLACE( CAST(Salary AS VARCHAR) , '0', '') AS FLOAT) ) 
            ) 
            AS INT
        )
FROM    EMPLOYEES 

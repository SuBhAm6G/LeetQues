# Write your MySQL query statement below
SELECT(
    SELECT 
        salary  
    FROM (SELECT salary, DENSE_RANK() OVER (ORDER BY salary DESC) rnk FROM Employee)t
    WHERE rnk = 2
    LIMIT 1
) SecondHighestSalary;
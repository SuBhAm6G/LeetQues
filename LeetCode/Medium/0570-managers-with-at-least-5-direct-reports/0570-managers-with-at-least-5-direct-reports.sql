/* Write your T-SQL query statement below */
SELECT
    e2.name
FROM Employee e1
inner JOIN Employee e2
ON e1.managerId = e2.id
GROUP BY e2.id, e2.name
having COUNT(e2.id) >=5;


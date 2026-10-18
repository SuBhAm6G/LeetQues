# Write your MySQL query statement below
select
    e1.name Employee 
from Employee e1
LEFT JOIN Employee e2
ON e1.managerId = e2.id
WHERE e1.salary > e2.salary
# Write your MySQL query statement below
WITH ranked_salary as (select 
    e.id,
    e.name Employee,
    e.salary Salary,
    DENSE_RANK() OVER(PARTITION BY e.departmentId ORDER BY e.salary DESC) rnk,
    d.name Department 
from Employee e
LEFT JOIN Department d
ON e.departmentId = d.id)

select
    Department,
    Employee,
    Salary
from ranked_salary
WHERE rnk=1;
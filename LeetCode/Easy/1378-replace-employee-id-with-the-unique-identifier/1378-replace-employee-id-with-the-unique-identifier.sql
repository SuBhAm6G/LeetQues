/* Write your PL/SQL query statement below */
SELECT 
    empu.unique_id,
    emp.name
FROM Employees emp
left JOIN EmployeeUNI empu
ON emp.id = empu.id
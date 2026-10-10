CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
    select max(salary) getNthHighestSalary
    from (select salary, dense_rank() over(ORDER BY salary desc) rnk from Employee)t
    where rnk = N
  );
END
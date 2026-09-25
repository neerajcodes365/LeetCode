# Write your MySQL query statement below
-- with cte as (
-- select salary , dense_rank() over(order by salary DESC) as rnk from Employee 
-- )
-- select ifnull(salary,null) as SecondHighestSalary from cte where rnk=2 limit 1;

WITH cte AS (
  SELECT salary, DENSE_RANK() OVER (ORDER BY salary DESC) AS rnk
  FROM Employee
)
SELECT (SELECT salary FROM cte WHERE rnk = 2 LIMIT 1) AS SecondHighestSalary;
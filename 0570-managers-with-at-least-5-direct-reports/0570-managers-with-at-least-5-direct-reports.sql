with ctename as(
SELECT managerId, COUNT(*) AS cnt
FROM Employee
GROUP BY managerId
)
select e.name from Employee e join ctename c on e.id=c.managerid where cnt>4;

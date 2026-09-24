# Write your MySQL query statement below
with main as(
select employee_id , name ,reports_to,age from Employees 
),
emp as (
    select employee_id , name ,reports_to,age from Employees where reports_to is not null
)

select main.employee_id,main.name,count(emp.employee_id) as reports_count,round(avg(emp.age)) as average_age from main join emp 
on main.employee_id=emp.reports_to group by main.employee_id order by main.employee_id;
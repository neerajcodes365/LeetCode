# Write your MySQL query statement below
select t.name , tt.bonus from Employee t left join Bonus tt
on t.empID=tt.empID where tt.bonus<1000 or tt.bonus is NULL;
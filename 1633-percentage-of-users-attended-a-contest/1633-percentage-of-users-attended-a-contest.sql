# Write your MySQL query statement below
-- with cte as (
    
-- )
select r.contest_id , round(count(r.user_id)/
(select count(user_id) as total from Users) *100,2) as percentage
from Register r group by contest_id order by percentage DESC ,r.contest_id ;
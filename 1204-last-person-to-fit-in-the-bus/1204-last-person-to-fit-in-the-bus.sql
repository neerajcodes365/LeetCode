# Write your MySQL query statement below
with cte as (
    select *,sum(weight) over(order by turn ) as sum  from Queue
)
select person_name from cte where sum<=1000 order by sum DESC limit 1;
# Write your MySQL query statement below
select machine_id,
round(
    avg(
        if(activity_type='start',-timestamp,timestamp)
        )*2
    ,3) as processing_time
from activity group by machine_id;

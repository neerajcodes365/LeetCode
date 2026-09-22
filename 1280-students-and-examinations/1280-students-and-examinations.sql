# Write your MySQL query statement below
with cte as (
    select student_id,subject_name,count(*) as attended_exams
    from Examinations group by student_id,subject_name
)
select s.student_id,s.student_name,sub.subject_name,
coalesce(cte.attended_exams,0) as attended_exams
from Students s cross join Subjects sub
left join cte on s.student_id=cte.student_id and sub.subject_name=cte.subject_name 
order by s.student_id,sub.subject_name;
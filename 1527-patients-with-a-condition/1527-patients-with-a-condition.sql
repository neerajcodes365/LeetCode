-- # Write your MySQL query statement below
-- select * from Patients where INstr(conditions,'DIAB1') !=0;
select *
from Patients 
where 
	conditions like 'DIAB1%' or
	conditions like '% DIAB1%';
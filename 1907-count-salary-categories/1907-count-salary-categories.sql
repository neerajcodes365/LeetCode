with low as (
    select count(*) as counti from Accounts where income <20000
),average_sal as (
    select count(*) as counti from Accounts where income between 20000 and 50000 
),high_sal as(
        select count(*) as counti from Accounts where income >50000
)
select 'Low Salary' as Category , counti as accounts_count from low
union 
select 'Average Salary' as Category , counti as accounts_count from average_sal
union 
select 'High Salary' as Category , counti as accounts_count from high_sal;
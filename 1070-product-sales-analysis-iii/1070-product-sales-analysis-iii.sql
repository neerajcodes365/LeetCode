# Write your MySQL query statement below
with cte as (
    select product_id,min(year) as year from Sales group by product_id
)

select s.product_id,cte.year as first_year,s.quantity,s.price from Sales s join cte on 
s.product_id=cte.product_id and s.year=cte.year ;
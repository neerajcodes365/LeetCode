# Write your MySQL query statement below
-- with cte as (
    select p.product_id,round(
        sum(
                case 
                        when u.units is null then 0 
                        else p.price*u.units 
                        end
            ) /
         case when sum(u.units) is null then 1 else sum(u.units) end,2) 
        as average_price from 
    Prices P left join UnitsSold U on p.product_id=u.product_id
    AND u.purchase_date BETWEEN p.start_date AND p.end_date
      group by p.product_id;
-- )
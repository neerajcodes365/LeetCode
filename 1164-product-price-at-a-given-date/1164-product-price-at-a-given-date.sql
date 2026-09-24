-- # Write your MySQL query statement below
-- with cte as(
--     select product_id,max(change_date) as maxdate from Products where change_date<="2019-08-16" group by product_id
-- )
-- select p.product_id, coalesce(p.new_price,10) as price from Products p left join cte 



SELECT product_id, new_price AS price
FROM Products
WHERE (product_id, change_date) IN
(
    SELECT product_id, max(change_date)
    FROM Products
    WHERE change_date <= '2019-08-16'
    GROUP BY product_id
)
UNION

SELECT product_id, 10 AS price
FROM Products
WHERE product_id NOT IN
(
    SELECT product_id
    FROM Products
    WHERE change_date <= '2019-08-16'
)
# Write your MySQL query statement
select q.query_name, round(sum(q.rating/q.position)/count(q.position),2) as quality , round(sum(
    case when q.rating <3 then 1 else 0 end
)/count(q.rating)*100,2) as poor_query_percentage from Queries q
group by query_name;
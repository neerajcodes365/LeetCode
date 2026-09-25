# Write your MySQL query statement below
select 
case 
    when id in (select count(*) as counti from Seat) and id%2=1 then id 
    else 
        case 
            when id%2=1 then id+1 
            else id-1
        end
    -- else id =id
end 
as id,student from Seat 
order by id ;
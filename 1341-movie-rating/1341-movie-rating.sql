select results from (
    select u.name as results, count(*) as cnt
    from MovieRating mr
    join Users u on mr.user_id = u.user_id
    group by mr.user_id
    order by cnt desc, u.name asc
    limit 1
) t1

union ALL

select results from (
    select m.title as results, avg(mr.rating) as avg_rating
    from MovieRating mr
    join Movies m on mr.movie_id = m.movie_id
    where mr.created_at between '2020-02-01' and '2020-02-29'
    group by mr.movie_id
    order by avg_rating desc, m.title asc
    limit 1
) t2;
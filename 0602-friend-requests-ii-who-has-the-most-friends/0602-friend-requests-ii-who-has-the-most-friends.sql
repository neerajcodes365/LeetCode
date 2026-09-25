# Write your MySQL query statement below
WITH requester_counts AS (
    SELECT requester_id AS id, COUNT(*) AS cnt
    FROM RequestAccepted
    GROUP BY requester_id
),
accepter_counts AS (
    SELECT accepter_id AS id, COUNT(*) AS cnt
    FROM RequestAccepted
    GROUP BY accepter_id
),
combined AS (
    SELECT id, cnt FROM requester_counts
    UNION ALL
    SELECT id, cnt FROM accepter_counts
)
SELECT id, SUM(cnt) AS num
FROM combined
GROUP BY id
ORDER BY num DESC
LIMIT 1;
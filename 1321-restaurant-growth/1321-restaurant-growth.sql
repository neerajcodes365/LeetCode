WITH daily AS (
    SELECT visited_on, SUM(amount) AS amount
    FROM Customer
    GROUP BY visited_on
),
numbered AS (
    SELECT
        visited_on,
        ROW_NUMBER() OVER (ORDER BY visited_on) AS rn,
        SUM(amount) OVER (ORDER BY visited_on) AS cum_sum
    FROM daily
)
SELECT
    curr.visited_on,
    curr.cum_sum - COALESCE(prev.cum_sum, 0) AS amount,
    ROUND((curr.cum_sum - COALESCE(prev.cum_sum, 0)) / 7.0, 2) AS average_amount
FROM numbered curr
LEFT JOIN numbered prev
    ON prev.rn = curr.rn - 7
WHERE curr.rn >= 7
ORDER BY curr.visited_on;
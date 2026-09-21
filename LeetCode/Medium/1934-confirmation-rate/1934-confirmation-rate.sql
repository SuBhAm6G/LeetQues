/* Write your PL/SQL query statement below */
SELECT
    s.user_id,
    ROUND(COUNT(CASE WHEN c.action = 'confirmed' THEN 1 END)/COUNT(*),2) confirmation_rate
FROM Signups s
LEFT JOIN Confirmations c
ON s.user_id = c.user_id
GROUP BY s.user_id
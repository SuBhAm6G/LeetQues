# Write your MySQL query statement below
with ranked_date as (select
    player_id,
    event_date first_login,
    dense_rank() over(partition by player_id order by event_date asc) rnk
from Activity)

select player_id, first_login from ranked_date
where rnk = 1;
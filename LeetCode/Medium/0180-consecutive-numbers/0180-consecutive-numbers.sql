with logs2 as (
    select
    num,
    lead(num,1) over(order by id) lead1,
    lead(num,2) over(order by id) lead2
    from Logs
)
select 
    distinct num ConsecutiveNums
from logs2
where num= lead1 and lead1=lead2
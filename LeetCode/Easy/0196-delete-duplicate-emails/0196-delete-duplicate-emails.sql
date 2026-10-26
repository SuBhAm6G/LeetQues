/* Write your T-SQL query statement below */

with ranked_tab as (
    select
        email,
        dense_rank() over(partition by email order by id) rnk
    from Person
)
delete from ranked_tab
where rnk>1;
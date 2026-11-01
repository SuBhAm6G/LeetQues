select
    name
from Salesperson
WHERE sales_id not in (
    select o.sales_id
    from Orders o
    INNER JOIN Company c on o.com_id = c.com_id
    where c.name = 'RED'
)
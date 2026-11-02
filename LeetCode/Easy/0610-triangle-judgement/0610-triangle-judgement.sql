# Write your MySQL query statement below
select
    x,
    y,
    z,
    case
        when abs(x+y)>abs(z) and abs(y+z)>abs(x) and abs(x+z)>abs(y) then 'Yes'
        else 'No'
    end triangle
from Triangle;
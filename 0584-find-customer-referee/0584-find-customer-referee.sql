# Write your MySQL query statement below
SELECT name FROM Customer
 WHERE referee_id NOT in(2)
 OR referee_id is null;
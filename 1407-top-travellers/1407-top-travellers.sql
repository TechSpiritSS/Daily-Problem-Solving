# Write your MySQL query statement below
SELECT name, CASE
    WHEN Users.id NOT IN (SELECT user_id FROM Rides) THEN 0
    ELSE SUM(distance) 
    END AS travelled_distance
FROM Users
LEFT JOIN Rides ON rides.user_id = Users.id
GROUP BY user_id
ORDER BY travelled_distance DESC, name
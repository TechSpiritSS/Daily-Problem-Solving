# Write your MySQL query statement below
SELECT weather.id 
FROM weather JOIN weather w ON DATEDIFF(weather.recordDate, w.recordDate) = 1
AND weather.temperature > w.temperature
# Write your MySQL query statement below
SELECT name, SUM(amount) AS balance
FROM Transactions
JOIN Users ON Transactions.account = Users.account
GROUP BY Users.account
HAVING balance > 10000
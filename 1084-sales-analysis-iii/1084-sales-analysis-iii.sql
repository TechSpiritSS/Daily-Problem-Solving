# Write your MySQL query statement below
SELECT product_id, product_name
FROM Product
WHERE product_id IN
(
    SELECT product_id
    FROM Sales
    GROUP BY product_id
    HAVING SUM(
        sale_date BETWEEN 
        '2019-01-01' AND '2019-03-31'
    ) = COUNT(sale_date)
)
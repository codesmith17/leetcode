SELECT customer_number
FROM ORDERS
GROUP BY customer_number
ORDER BY COUNT(order_number) DESC
LIMIT 1;

# LeetCode Problem 595. Big Countries (easy)
SELECT
    name,
    population,
    area
FROM World
WHERE area > 3000000 OR population > 25000000
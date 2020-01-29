# LeetCode problem 620. Not Boring Movies (easy)
SELECT * FROM cinema
WHERE id % 2 = 1 AND NOT description = 'boring'
ORDER BY rating DESC
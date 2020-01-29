# LeetCode Problem 627. Swap Salary (easy)
UPDATE salary
SET SEX = CASE 
    WHEN sex = 'm'
    THEN 'f'
    WHEN sex = 'f'
    THEN 'm'
    END
WHERE sex = 'm' OR sex = 'f'

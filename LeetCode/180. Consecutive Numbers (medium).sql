# LeetCode problem 180. Consecutive Numbers (medium)
# Finding cases of 3 consecutive numbers
SELECT DISTINCT
    Logs.Num as ConsecutiveNums
FROM Logs
LEFT JOIN Logs as L1
ON L1.Id = Logs.Id + 1
Left JOIN Logs as L2
ON L2.Id = L1.Id + 1
WHERE Logs.Num = L1.Num and L1.Num = L2.Num;

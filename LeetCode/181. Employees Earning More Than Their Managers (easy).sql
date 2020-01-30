# LeetCode problem 181. Employees Earning More Than Their Managers (easy)
SELECT 
    Employee.Name as Employee
FROM Employee
LEFT JOIN Employee as Emp
ON Emp.Id = Employee.ManagerId
WHERE Employee.ManagerId IS NOT NULL AND Employee.Salary > Emp.Salary
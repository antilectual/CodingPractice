# LeetCode problem 1179. Reformat Department Table (easy)

# Write your MySQL query statement below
SELECT
    Department.id, 
    DeptJan.revenue AS Jan_Revenue,
    DeptFeb.revenue AS Feb_Revenue,
    DeptMar.revenue AS Mar_Revenue,
    DeptApr.revenue AS Apr_Revenue,
    DeptMay.revenue AS May_Revenue,
    DeptJun.revenue AS Jun_Revenue,
    DeptJul.revenue AS Jul_Revenue,
    DeptAug.revenue AS Aug_Revenue,
    DeptSep.revenue AS Sep_Revenue,
    DeptOct.revenue AS Oct_Revenue,
    DeptNov.revenue AS Nov_Revenue,
    DeptDec.revenue AS Dec_Revenue
FROM Department
LEFT JOIN Department AS DeptJan 
ON Department.id = DeptJan.id AND DeptJan.month = "Jan"
LEFT JOIN Department AS DeptFeb 
ON Department.id = DeptFeb.id AND DeptFeb.month = "Feb"
LEFT JOIN Department AS DeptMar 
ON Department.id = DeptMar.id AND DeptMar.month = "Mar"
LEFT JOIN Department AS DeptApr 
ON Department.id = DeptApr.id AND DeptApr.month = "Apr"
LEFT JOIN Department AS DeptMay 
ON Department.id = DeptMay.id AND DeptMay.month = "May"
LEFT JOIN Department AS DeptJun 
ON Department.id = DeptJun.id AND DeptJun.month = "Jun"
LEFT JOIN Department AS DeptJul 
ON Department.id = DeptJul.id AND DeptJul.month = "Jul"
LEFT JOIN Department AS DeptAug 
ON Department.id = DeptAug.id AND DeptAug.month = "Aug"
LEFT JOIN Department AS DeptSep 
ON Department.id = DeptSep.id AND DeptSep.month = "Sep"
LEFT JOIN Department AS DeptOct 
ON Department.id = DeptOct.id AND DeptOct.month = "Oct"
LEFT JOIN Department AS DeptNov 
ON Department.id = DeptNov.id AND DeptNov.month = "Nov"
LEFT JOIN Department AS DeptDec 
ON Department.id = DeptDec.id AND DeptDec.month = "Dec"
GROUP BY Department.id;
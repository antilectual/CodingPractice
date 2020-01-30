# LeetCode Problem 196. Delete Duplicate Emails (easy)
DELETE FROM Person
WHERE Id IN 
(SELECT Id FROM
    (SELECT 
        P1.Id,
        P1.Email
    FROM Person AS P1, Person AS P2
    WHERE P1.Id > P2.Id AND P1.Email = P2.Email)
 AS P3);
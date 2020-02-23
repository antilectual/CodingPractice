# LeetCode problem 1342. Number of Steps to Reduce a Number to Zero (easy)
# Algorithm:  If the current number is even, you divide it by 2, otherwise, subtract 1 from it. Count the steps until 0.

class Solution:
    def numberOfSteps (self, num: int) -> int:
        count = 0
        while num > 0:
            if num % 2 == 1:
                num -= 1
            else:
               num = num / 2
            count += 1
        return count
# LeetCode problem 171. Excel Sheet Column Number (easy)
# Algorithm: Start with right hand digit moving left and add the value of the digit's place value in base 26

class Solution:
    def titleToNumber(self, s: str) -> int:
        place = result = 0
        for ch in s[::-1]:
            result = result + (ord(ch)-64) * 26**place
            place +=1
        return result
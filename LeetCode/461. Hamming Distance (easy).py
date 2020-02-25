# LeetCode problem 461. Hamming Distance (easy)
# Algorithm: XOR x and y and count the 1 bits in the resulting value by modulo 2 and then dividing by 2 until the value is 0.

class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        z = x^y
        count = 0
        while(z > 0):
            if(z%2 == 1):
                count += 1
            z //= 2
        return count
        
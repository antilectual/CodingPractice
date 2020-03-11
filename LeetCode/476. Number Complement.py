# LeetCode problem 1009. Complement of Base 10 Integer (easy)
# LeetCode problem 476. Number Complement (easy)

# Algorithm: XOR each bit from least significant to most significant bit and add to the result.

class Solution:
    def bitwiseComplement(self, N: int) -> int:
        count = 0
        result = 0
        if N == 0:
            return 1
        while N > 0:
            result += (((N % 2) ^ 1) << count)
            count += 1
            N //= 2
        return result
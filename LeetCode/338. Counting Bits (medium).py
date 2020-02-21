# LeetCode problem 338. Counting Bits (medium)
# Algorithm: Count bits by modulo 2 and divide by 2 until no more bits are left.  Store calculated bits in fullList to reduce repeated calculations
class Solution:
    fullList = []
    def countBits(self, num: int) -> List[int]:
        length = len(self.fullList)
        if length < num:
            for i in range(length, (num + 1)):
                n = i
                sum = 0
                while n > 0:
                    sum += n % 2
                    n = int(n / 2)
                self.fullList.append(sum)
        return self.fullList[:(num+1)]
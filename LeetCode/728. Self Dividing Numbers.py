# LeetCode problem 728. Self Dividing Numbers (easy)

# Algorithm: Brute force following algorithm described in problem. Iterated all numbers in the range and test to make sure they are divisible by every one of their digits. 
class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        results = []
        for val in range(left, right + 1):
            current = val
            isDividing = True
            while(current > 0):
                right = current % 10
                if(right == 0 or val % right != 0):
                    isDividing = False
                    break
                current = current // 10
            if(isDividing):
                results.append(val)
        return results
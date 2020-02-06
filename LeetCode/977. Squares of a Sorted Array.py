# LeetCode Problem 977. Squares of a Sorted Array (easy)
class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        results = [x**2 for x in A]
        results.sort()
        return results
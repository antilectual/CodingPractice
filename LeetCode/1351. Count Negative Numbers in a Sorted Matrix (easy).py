# LeetCode problem 1351. Count Negative Numbers in a Sorted Matrix (easy)
# Algorithm: Iterate from bottom right counting negatives in each row from right to left. When 0+ is found, move up to next row.

class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        count = 0
        for row in grid[::-1]:
            for x in row[::-1]:
                if x < 0:
                    count += 1
                else:
                    break
        return count
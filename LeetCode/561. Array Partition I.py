# LeetCode Problem 561. Array Partition I

# Algorithm: Sort the array and pair odd indexes with even indexes (Add every other sorted number).
class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()
        total = 0
        for i,val in enumerate(nums):
            if i%2 == 0:
                total += val
        return total
# LeetCode problem 1365. How Many Numbers Are Smaller Than the Current Number (easy)
# Algorithm: Make a sorted copy of the list of numbers, then iterate the original list counting how many in the sorted list are smaller.

class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        if nums == None:
            return  None
        elif nums == []:
            return 
        result = []
        sortedNums = sorted(nums)
        for x in nums:
            count = 0
            curr = sortedNums[0]
            while curr < x:
                count += 1
                curr = sortedNums[count]
            result.append(count)
        return result
# LeetCode problem 1365. How Many Numbers Are Smaller Than the Current Number
# Algorithm: Make a 101 buckets to count how many of each value there is (between 0 and 100 inclusive). Iterate nums and count the values in the buckets less than the current value and add the count to the results list.

class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        if nums == None:
            return  None
        elif nums == []:
            return 
        result = []
        buckets = [0 for i in range(101)]
        for x in nums:
            buckets[x] += 1
        for x in nums:
            count = 0
            for i in range(x):
                count += buckets[i]
            result.append(count)
        return result
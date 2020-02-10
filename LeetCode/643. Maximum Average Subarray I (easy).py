# LeetCode problem 643. Maximum Average Subarray I (easy)

# Algorithm: Calculate original sum of first k contiguous integers.  Iterate the rest of the list subtracting the oldest element's value from the sum and adding the newest element's value to the sum.
#			 Keep track of largest value.  Divide the value by K to get the average.

class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        maxSum = -40000.0
        currentSum = 0
        
        for i in range(k):              # important constraint: nums.size() is larger than k
            currentSum += nums[i]
        maxSum = currentSum
        
        for i, x in enumerate(nums):
            if(i < k):
                pass
            else:
                currentSum -= nums[i-k]
                currentSum += nums[i]
                if currentSum > maxSum:
                    maxSum = currentSum
        return maxSum / k
            
        
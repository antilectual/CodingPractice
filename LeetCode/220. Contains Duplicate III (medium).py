# LeetCode problem 220. Contains Duplicate III (medium)

# Algorithm: Brute Force (Timeout): Iterate the array testing values within k distance for having absolute difference of <= t
class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        size = len(nums);
        for i, num in enumerate(nums):
            count = 1
            while(count <= k):
                if(i + count >= size):
                    break
                diff = nums[i] - nums[i+count]
                if(diff < 0):
                    diff *= -1
                if(diff <= t):
                    return True
                count += 1
        return False
# LeetCode problem 167. Two Sum II - Input array is sorted (easy)
# Algorithm: Iterate from the front and back at the same time to approach the correct pair of values

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        j = len(numbers) - 1
        i = 0
        while(numbers[i] + numbers[j] != target):
            if(numbers[i] + numbers[j] > target):
                j -= 1
            if(numbers[i] + numbers[j] <target):
                i += 1
        return [i+1, j+1]
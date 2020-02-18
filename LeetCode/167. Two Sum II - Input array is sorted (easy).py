# LeetCode problem 167. Two Sum II - Input array is sorted (easy)
# Algorithm: Choose a number in the numbers array. Iterate the numbers array between the value and the target - value. Return when the solution is found 

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        for i,n in enumerate(numbers):
            j = i + 1
            end = len(numbers) - 1
            tempTarget = target - n
            while(j < end and numbers[j] < tempTarget):
                j += 1
            if(numbers[i] + numbers[j] == target):
                return [i+1,j+1]
        return
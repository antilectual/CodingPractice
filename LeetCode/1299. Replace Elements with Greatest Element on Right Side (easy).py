# 1299. Replace Elements with Greatest Element on Right Side

# Algorithm: iterate the list from right to left finding the largest value and replacing the current value in the same index in a copy of the list
class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        newList = []
        maxInt = -1
        for i in reversed(arr):
            newList.insert(0,maxInt)
            if i > maxInt:
                maxInt = i
        return newList
        
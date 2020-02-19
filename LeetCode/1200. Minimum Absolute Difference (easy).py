# LeetCode problem 1200. Minimum Absolute Difference (easy)
# Algorithm: Sort the list and then iterate it once to find the smallest difference between numbers. Iterate a second time to find all pairs with that minimum difference.
class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        sArr = sorted(arr)
        last = sArr[0]
        diff = 10000001
        for x in sArr[1:]:
            if abs(x - last) < diff:
                diff = abs(x - last)
            last = x
        results = []
        last = sArr[0]
        for x in sArr[1:]:
            if abs(x - last) == diff:
                results.append([last,x])
            last = x
        return results
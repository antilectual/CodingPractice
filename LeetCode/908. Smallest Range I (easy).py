# LeetCode problem 908. Smallest Range I (easy)
# Algorithm: Find min and max values and find the difference. Subtract 2x K from that difference to find the smallest range.
#            Less than 0 means smallest range is 0.  

class Solution:
    def smallestRangeI(self, A: List[int], K: int) -> int:
        a = max(A)
        b = min(A)
        diff = a - b
        if diff <= 0:
            return 0
        diff = diff - (2 * K)
        if diff <= 0:
            return 0
        return diff
        
# LeetCode problem 796. Rotate String (easy)
# Algorithm: Iterate through A and test to see if the concatenation of the left side of the current index with the right side of the current index equals B
class Solution:
    def rotateString(self, A: str, B: str) -> bool:
        if len(A) != len(B):
            return False
        if A == B:
            return True
        for i in range(len(A)):
            if B == A[i:] + A[:i]:
                return True
        return False
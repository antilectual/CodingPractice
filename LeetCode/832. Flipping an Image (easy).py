# LeetCode problem 832. Flipping an Image (easy). Python problem #2.

# Flips an image horizontally and inverts it
class Solution:
    def flipAndInvertImage(self, A: List[List[int]]) -> List[List[int]]:
        newList = []
        for row in A:
            reverseRow = row[::-1]
            newRow = [x ^ 1 for x in reverseRow]
            newList.append(newRow)
        return newList
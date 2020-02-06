# LeetCode Problem 700. Search in a Binary Search Tree

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        current = root
        while(current != None):
            if(current.val == val):
                return current
            elif(val < current.val):
                current = current.left
            else:
                current = current.right
        return current

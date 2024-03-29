# LeetCode Problem 700. Search in a Binary Search Tree (easy)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        if(root == None or root.val == val):
            return root
        elif(val < root.val):
            return self.searchBST(root.left, val)
        else:
            return self.searchBST(root.right, val)
            
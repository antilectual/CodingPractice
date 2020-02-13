# LeetCode problem 226. Invert Binary Tree
# Algorithm: Recursively swap right branch with left branch.

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if root == None:
            return root
        if root.left == None and root.right == None:
            return root
        else:
            temp = root.left
            root.left = root.right
            root.right = temp
            self.invertTree(root.right)
            self.invertTree(root.left)
        return root
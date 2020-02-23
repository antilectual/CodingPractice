# LeetCode problem 617. Merge Two Binary Trees (Easy)
# Algorithm: traverse both trees simultaneously and merging them into the left tree.

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode:
        if t1 == None and t2 == None:
            return None
        elif t1 == None and t2 != None:
            t1 = TreeNode(t2.val)
        elif t1 != None and t2 == None:
            return t1
        elif t1.val == None and t2.val == None:
            return None
        elif t1.val != None and t2.val != None:
            t1.val += t2.val
        t1.left = self.mergeTrees(t1.left, t2.left)
        t1.right = self.mergeTrees(t1.right, t2.right)
        return t1
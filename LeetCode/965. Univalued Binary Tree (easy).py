# LeetCode problem 965. Univalued Binary Tree (easy)
# Algorithm: Recursively traverse the tree checking to see if all values are equal to the rood node's value.

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    searchVal = -1
    def isUnivalTree(self, root: TreeNode) -> bool:
        self.searchVal = root.val
        return self.isUnivalTreeHelper(root.left) and self.isUnivalTreeHelper(root.right)
    
    def isUnivalTreeHelper(self, currNode: TreeNode) -> bool:
        if currNode == None:
            return True
        else:
            if currNode.val == self.searchVal:
                return self.isUnivalTreeHelper(currNode.left) and self.isUnivalTreeHelper(currNode.right)
            else:
                return False
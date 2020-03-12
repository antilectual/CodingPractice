# LeetCode problem 654. Maximum Binary Tree (medium)
# Algorithm: Locate the index of the max value in the list. Use that location to determine: Max Value, Left Partition, Right Partition.  Recursively create tree using nodes from max value as root.val, root.left from left partion, and root.right from right partition.

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> TreeNode:
        if nums == [] or nums == None:
            return None
        i = nums.index(max(nums))
        maxVal = nums[i]
        left = nums[0:i]
        right = nums[i:len(nums)]
        root = TreeNode(maxVal)
        right.remove(maxVal)
        root.left = self.constructMaximumBinaryTree(left)
        root.right = self.constructMaximumBinaryTree(right)
        return root
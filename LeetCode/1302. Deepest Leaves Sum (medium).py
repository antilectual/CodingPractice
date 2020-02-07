# LeetCode problem 1302. Deepest Leaves Sum (medium)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# Algorithm: Traverses tree to find depth. Re-traverses tree and sums nodes that are at the tree depth.
class Solution:
    sum = 0
    maxDepth = 0
    def deepestLeavesSum(self, root: TreeNode) -> int:
        self.sum = 0    # reset sum on function call
        self.maxDepth = 0
        if(root != None):
            self.maxDepth = self.findDepth(root)
        else:
            return 0
        self.findSum(root, 1)
        return self.sum
            
    # Recursively traverses nodes for find the max depth o(n)
    def findDepth(self, node: TreeNode) -> int:
        left = 0
        right = 0
        # leaf node
        if(node.left == None and node.right == None):
            return 1
        # has left child
        if(node.right != None):
            right = self.findDepth(node.right) + 1
        # has right child
        if(node.left != None):
            left = self.findDepth(node.left) + 1
        return max(left, right)
    
    # Recursively traverses the and adds values of nodes where the depth = max depth
    def findSum(self, node: TreeNode, depth : int):
        if(depth == self.maxDepth):
            self.sum += node.val
            return
        if(node.left != None):
            left = self.findSum(node.left, depth + 1)
        if(node.right != None):
            right = self.findSum(node.right, depth + 1)
        return
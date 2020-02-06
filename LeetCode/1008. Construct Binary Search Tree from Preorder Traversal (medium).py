# LeetCode problem 1008. Construct Binary Search Tree from Preorder Traversal (medium)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# Algorithm: Iterate the list and append values as an appropriate leaf in the tree. Does not garauntee a balanced tree.
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        root = None
        for x in preorder:
            newNode = self.findNode(root, x)
            # case: empty tree 
            if(newNode == None):
                root = TreeNode(x) 
            elif(x < newNode.val):
                newNode.left = TreeNode(x)
            elif(x > newNode.val):
                newNode.right = TreeNode(x)
        return root
            
        
    def findNode(self, node: ListNode, x: int) -> TreeNode:
        if (node == None):
            return None
        if (x < node.val):
            lastNode = self.findNode(node.left, x)
        else:
            lastNode = self.findNode(node.right, x)
        
        if (lastNode == None):
            return node
        else:
            return lastNode
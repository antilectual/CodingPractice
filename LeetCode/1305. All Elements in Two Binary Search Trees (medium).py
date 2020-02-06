# LeetCode Problem 1305. All Elements in Two Binary Search Trees (medium)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# Algorithm: Naive solution: Add all elements to a list and then sort the list using pythons TimSort.
# Updates:  Fix to ensure elementsList is cleared for each call of getAllElements.
#           Preorder traversal changed to inorder traversal so that each list is created in sorted order to help speed up sorting.
class Solution:
    elementsList = []
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        self.elementsList = []
        self.getElementsFromSingleRoot(root1)
        self.getElementsFromSingleRoot(root2)
        self.elementsList.sort()
        return self.elementsList
    
    def getElementsFromSingleRoot(self, root: TreeNode):
        if(root == None):
            return
        else:
            self.getElementsFromSingleRoot(root.left)
            self.elementsList.append(root.val)
            self.getElementsFromSingleRoot(root.right)
            
# LeetCode problem 237. Delete Node in a Linked List (easy)
# Algorithm: Delete current node by recursively copying the next node into the current until there are no nodes left.

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        if node == None:
            return
        if node.next != None:
            node.val = node.next.val
            if node.next.next == None:
                node.next = None
            self.deleteNode(node.next)
# LeetCode problem 876. Middle of the Linked List (easy)
# Algorithm: Iterate the list to count the nodes. Calculate mid point and go next nodes to the midpoint

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        curr = head
        count = 0.0
        while curr is not None:
            curr = curr.next
            count += 1
        curr = head
        mid = int(count / 2)
        for i in range(mid):
            curr = curr.next
        return curr
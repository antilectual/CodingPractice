// Leetcode Problem 1290. Convert Binary Number in a Linked List to Integer (easy)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int count = 0;
        int result = 0;
        ListNode *tempHead = head;
        if(head == NULL)
        {
            return 0;
        }
        while(tempHead->next != NULL)
        {
            count++;
            tempHead = tempHead->next;
        }
        tempHead = head;
        while(tempHead != NULL)
        {
            result += tempHead->val * pow(2, count);
            count--;
            tempHead = tempHead->next;
        }
        return result;
    }
};
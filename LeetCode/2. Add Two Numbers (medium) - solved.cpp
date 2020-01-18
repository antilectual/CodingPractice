// 2. Add Two Numbers (medium)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Naively assumes linked lists contain (mostly) valid positive integers
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tempL1 = l1;
        ListNode* tempL2 = l2;
        ListNode* resultListInt;
        int currentDigit = 0, carry = 0;
        // if a list is null, returning the opposite list (or a null list is both are null)
        if(l1 == NULL)
        {
            return l2;
        }
        else if (l2 == NULL)
        {
            return l1;
        }
        // Initiializes the list with the first value
        currentDigit = (tempL1->val + tempL2->val);
        resultListInt = new ListNode(currentDigit % 10);
        carry = currentDigit / 10;
        ListNode* tempResultNode = resultListInt;
        tempL1 = tempL1->next;
        tempL2 = tempL2->next;
        // add the rest of the digits until one list has no more digits
        while(tempL1 != NULL && tempL2 != NULL)
        {
            currentDigit = tempL1->val + tempL2->val;
            tempResultNode->next = new ListNode((currentDigit + carry) % 10 );
            carry = (currentDigit + carry) / 10;
            tempL1 = tempL1->next;
            tempL2 = tempL2->next;
            tempResultNode = tempResultNode->next;
        }
        // if there was only a carry left, add the carry and return the list
        if(tempL1 == NULL && tempL2 == NULL && carry > 0)
        {
            tempResultNode->next = new ListNode(carry);
            return resultListInt;
        }
        // set the unfinished list as tempL1
        if(tempL2 != NULL)
        {
            tempL1 = tempL2;
        }
        // add the carry to the next digit
        if(carry > 0)
        {
            tempResultNode->next = new ListNode((tempL1->val + carry) % 10);
            carry = (tempL1->val + carry) / 10;
            tempResultNode = tempResultNode->next;
            tempL1 = tempL1->next;
        }
        // add the rest of the digits from the non-finished list
        while(tempL1 != NULL)
        {
            tempResultNode->next = new ListNode((tempL1->val + carry) % 10);
            carry = (tempL1->val + carry) / 10;
            tempResultNode = tempResultNode->next;
            tempL1 = tempL1->next;
        }
        // bugfix - can have a carry at the end to add one last digit
        if(carry > 0)
        {
            tempResultNode->next = new ListNode(carry);
        }
        return resultListInt;
    }
};
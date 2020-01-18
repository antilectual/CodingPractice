// 2. Add Two Numbers

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
        long l1Int = 0, l2Int = 0;
        int digit = 0;
        long sumInt = 0;
        while(tempL1 != NULL)
        {
            l1Int += tempL1->val * pow(10, digit);
            digit++;
            tempL1 = tempL1->next;
        }
        digit = 0;
        while(tempL2 != NULL)
        {
            l2Int += tempL2->val * pow(10, digit);
            digit++;
            tempL2 = tempL2->next;
        }
        sumInt = l2Int + l1Int;
        // Testing for valid int output not necessary for this problem.
        /*if(sumInt > INT_MAX)
        {
            sumInt = INT_MAX;
        }*/
        resultListInt = new ListNode(sumInt % 10);
        ListNode* tempResultNode = resultListInt;
        sumInt /= 10;
        while(sumInt > 0)
        {
            tempResultNode->next = new ListNode(sumInt % 10);
            tempResultNode = tempResultNode->next;
            sumInt /= 10;
        }
        return resultListInt;
    }
};
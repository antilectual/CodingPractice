// 938. Range Sum of BST (easy)
// Brute Force Method by checking every value in the binary tree.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) 
    {
        int sumResult = 0;
        if(root == NULL)
        {
            return 0;
        }
        else if(root->val >= L && root->val <= R)
        {
            sumResult += root->val;
        }
        sumResult += rangeSumBST(root->left, L, R);
        sumResult += rangeSumBST(root->right, L, R);
        return sumResult;
    }
};
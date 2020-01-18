// 938. Range Sum of BST (easy)
// Faster - Prevent useless directional tree travel
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
        if(root->val > L) {sumResult += rangeSumBST(root->left, L, R);}
        if(root->val < R) {sumResult += rangeSumBST(root->right, L, R);}
        return sumResult;
    }
};
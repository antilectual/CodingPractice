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
    int sumEvenGrandparent(TreeNode* root) {
        int total = sumEvenGrandparentSearch(root);
        return total;
    }
    int sumEvenGrandparentSearch(TreeNode* root){
        int sum = 0;
        // if grandparent is even then check its grandchildren.
        if(root->val % 2 == 0)
        {
            if(root->left != NULL)
            {
                if(root->left->right != NULL)
                {
                    sum += root->left->right->val;
                }
                if(root->left->left !=NULL)
                {
                    sum += root->left->left->val;
                }
            }
            if(root->right !=NULL)
            {
                if(root->right->right != NULL)
                {
                    sum += root->right->right->val;
                }
                if(root->right->left !=NULL)
                {
                    sum += root->right->left->val;
                }
            }
        }
		// search the children.
        if(root->left!=NULL)
        {
           sum += sumEvenGrandparentSearch(root->left);
        }
        if(root->right!=NULL)
        {
           sum += sumEvenGrandparentSearch(root->right);
        }
        return sum;
    }
};
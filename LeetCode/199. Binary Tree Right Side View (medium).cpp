// Test Case: [1,2,3,4,null,5,null,6,7,8,9,10,null,11,null,12,null,null,null,13,14,15,null,null,null,null,null,16]
// 199. Binary Tree Right Side View (medium)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // *Current solution is incorrect.  Only follows the right most branch as far as it can, but left side can have deeper branches that would be visible.
 // Proposed solution: Get the depth of the full tree and then do Breath First Search, adding only the rightmost node per depth level.
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> outputList;
        int depth = 0;
        bool finished = 0;
        TreeNode* previousNode = root;
        if(root != NULL)
        {
            while(finished == false)
            {
                while(root->right != NULL || root->left != NULL)
                {
                    outputList.push_back(root->val);
                    if(root->right != NULL)
                    {
                        root = root->right;
                    }
                    else
                    {
                        root = root->left;
                    }
                    depth++;
                }
            
            // add the final leaf node
            outputList.push_back(root->val);
            }

        }
        return outputList;
    }
};
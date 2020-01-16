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
 // Current solution: Add every value from a specific level to an array for that level in order from left to right.  At each level, grab the value from the end of the array and add it to the final list.
class Solution {
public:
	vector<vector <int>> treeByDepth;
    vector<int> rightSideView(TreeNode* root) {
        vector<int> outputList;
		int maxDepth = getTreeHeight(root);
		treeByDepth.resize(maxDepth);
		SearchForRightValues(root, maxDepth);
        // maxDepth -1 is the root level and decreases going down to the tree. the deepest leaf is at level 0;
		for(int i = maxDepth -1; i >= 0; i--)
		{
			outputList.push_back(treeByDepth[i].back());
		}
        return outputList;
    }
	
	// Adds values based on level. Traverses from left to right, so the last value added will be what is seen for that level.
    // maxDepth - 1 = root. 
	void SearchForRightValues(TreeNode *current, int depth)
	{
		if(depth == 0 || current == NULL)
		{
			return;
		}
		treeByDepth[depth-1].push_back(current->val); 
		SearchForRightValues(current->left, depth-1);
		SearchForRightValues(current->right, depth-1);
		return;
	}
	
	int getTreeHeight(TreeNode *top)
	{
		if(top == NULL)
		{
			return 0;
		}
		int rightHeight = getTreeHeight(top->right), leftHeight = getTreeHeight(top->left);
		if(rightHeight > leftHeight)
		{
			return rightHeight + 1;
		}
		else
		{
			return leftHeight + 1;
		}
	}
};
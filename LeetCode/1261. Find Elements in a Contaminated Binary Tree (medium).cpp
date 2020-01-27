// LeetCode problem 1261. Find Elements in a Contaminated Binary Tree (medium)
// Updated: Optimized better for speed.
//
//    root.val == 0
//    If treeNode.val == x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
//    If treeNode.val == x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
// Note: This is equivalent to numbering the nodes in the tree starting with root = 0, root->left = 1, root->right = 2, etc.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
private:
	TreeNode* _root;
    int _target = -1;
	vector<bool> fullTree;
	  
    // Recursively iterates the tree and stores whether the node's value exists by using a boolean array where the node value = index.
    void repairNode(TreeNode * currNode, int x, bool isLeft)
    {
        if(currNode != NULL)
        {
            int val = -1;
            if(isLeft)
            {
                val = 2*x+1;                
            }
            else
            {
                val = 2*x+2;
            }
            // bugfix = + 1 more element to ensure size is enough.
            if(fullTree.size() < 2*x+3)
            {
                fullTree.resize(2*x+3, 0);
            }
            fullTree[val] = true;
            repairNode(currNode->left, val, true);
            repairNode(currNode->right, val, false);
        }
    }
	
public:
    
    // Reconstructs the binary tree. Root starts at 0.
    FindElements(TreeNode* root) {
        _root = root;
        if(_root != NULL)
        {
            fullTree.resize(3,0);
            fullTree[0] = _root->val = 0;
            repairNode(root->left, 0, true);
            repairNode(root->right, 0, false);
        }
    }
    
    // Returns if the target value exists in the tree.  If it does exist, the value at the index = target will be true.
    bool find(int target) {
        if(target < fullTree.size())
        {
            return fullTree[target];
        }
        return false;
    }

};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
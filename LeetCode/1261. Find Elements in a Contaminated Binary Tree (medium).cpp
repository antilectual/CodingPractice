// LeetCode problem 1261. Find Elements in a Contaminated Binary Tree (medium)
// Brute Force solution

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
public:
    TreeNode* _root;
    int _target = -1;
    FindElements(TreeNode* root) {
        _root = root;
        if(_root != NULL)
        {
            _root->val = 0;
            repairNode(root->left, _root->val, true);
            repairNode(root->right, _root->val, false);
        }
    }
    
    void repairNode(TreeNode * currNode, int x, bool isLeft)
    {
        if(currNode != NULL)
        {
            if(isLeft)
            {
                currNode->val = 2*x + 1;     
            }
            else
            {
                currNode->val = 2*x + 2;
            }
            
            repairNode(currNode->left, currNode->val, true);
            repairNode(currNode->right, currNode->val, false);
        }
    }
    
    bool find(int target) {
        _target = target;
        return findHelper(_root);
    }
    
    bool findHelper(TreeNode* currNode)
    {
        if(currNode == NULL)
        {
            return false;
        }
        else
        {
            if(currNode->val == _target)
            {
                return true;
            }
            else
            {
                return findHelper(currNode->left) || findHelper(currNode->right);
            }
        }
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
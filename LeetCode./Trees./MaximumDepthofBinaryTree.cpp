/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
protected:
    
    void maxDepth(TreeNode* crnt, int& crntDpt, int& maxDpt)
    {
        if(!crnt) return;
        
        ++crntDpt;
        maxDepth(crnt->left, crntDpt, maxDpt);
        maxDepth(crnt->right, crntDpt, maxDpt);
        --crntDpt;
        
        maxDpt = std::max(crntDpt, maxDpt);
    }
    
public:
    int maxDepth(TreeNode* root) 
    {
        int cd = 1;
        int md = 0;
        maxDepth(root, cd, md);
        return md;
    }
};

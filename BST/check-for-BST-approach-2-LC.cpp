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
class Solution {
public:
    
    bool check(TreeNode* root, long long minv, long long maxv) {

        if(root == nullptr){return true;}

        if (root->val <= minv || root->val >= maxv)
        return false;

        return check(root->left, minv, root->val) &&
               check(root->right, root->val, maxv);
        
    }
    bool isValidBST(TreeNode* root)
    {   
        return check(root,LLONG_MIN,LLONG_MAX);
    }
};

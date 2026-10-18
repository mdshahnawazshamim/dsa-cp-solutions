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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
    
    TreeNode* n = new TreeNode(val);
    if(root == nullptr){return n;}

    TreeNode *c = root, *p = nullptr;

    while(c!= nullptr)
    {   p=c;
        if(val < c->val)
        {
          c = c->left;
        }
        else
        {
            c = c->right;
        }
    }

    if(val<p->val)
    {
        p->left = n;
    }
    else
    {
        p->right = n;
    }
    return root;
    
    }
};
//TC:O(H),SC:O(1)
//LeetCode - 701

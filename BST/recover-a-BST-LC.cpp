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
    vector<TreeNode*> in;
    void inorder(TreeNode* root)
    {
        if(root == nullptr){return;}

        inorder(root->left);
        in.push_back(root);
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {

        inorder(root);

        TreeNode* f = nullptr;
        TreeNode* s = nullptr;

        for(int i=1;i<in.size();++i)
        {
            if(in[i-1]->val > in[i]->val)
            {
                if(f==nullptr)
                {
                    f=in[i-1];
                    s=in[i];
                }
                else
                {
                    s=in[i];
                }
            }
        }
        swap(f->val,s->val);
        
    }
};

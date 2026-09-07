class Solution {
public:
    // Returns: first -> whether the subtree is balanced, second -> height of the subtree
    pair<bool, int> check(TreeNode* root) {

        // An empty tree is balanced and has height 0.
        if (root == nullptr) {
            return {true, 0};
        }

        // Recursively check the left and right subtrees.
        pair<bool, int> l = check(root->left);
        pair<bool, int> r = check(root->right);
      
       // The current subtree is balanced if: 
       // 1. Left subtree is balanced 
       // 2. Right subtree is balanced 
       // 3. Difference between their heights is at most 1
        bool isBal = l.first && r.first &&
                     abs(l.second - r.second) <= 1;

        // Height of the current node is 1 + the greater height of its left and right subtrees.
        int h = max(l.second, r.second) + 1;

        // Return both the balance status and height.
        return {isBal, h};
    }

   // The problem only requires whether the entire tree is balanced.
   // check(root).first gives the balance status.
    bool isBalanced(TreeNode* root) {

        return check(root).first;
 
    }
};

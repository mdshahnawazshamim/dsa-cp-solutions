/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    Node* p = nullptr;
    bool ISBST = true;
    void check(Node* root) {
        // code here
        if(root == nullptr)
        {
            return;
        }
        check(root->left);
        if(p!=nullptr && root->data <= p->data)
        {
            ISBST = false;
        }
        p=root;
        check(root->right);
        
    }
    bool isBST(Node* root)
    {   p = nullptr;
        ISBST = true;
        check(root);
        return ISBST;
    }
};

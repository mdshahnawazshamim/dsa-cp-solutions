/* Definition for Node
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool search(Node* root, int key) {
        Node *temp = root;
        
        while(temp!=nullptr)
        {
            if(temp->data == key)
            {
                return true;
            }
            else if(temp->data < key)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }
        return false;
    }
};
//worst case scenario, lenght of largest path from root to leaf is height of a tree, so Time Complexity = TC(H).

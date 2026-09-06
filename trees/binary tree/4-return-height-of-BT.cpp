int height(Node* root) {
        // code here
        if(root == nullptr)
        {
            return -1;// nullptr = -1  →  leaf = 0  →  parent = 1  →  grandparent = 2
        }
        
        return max(height(root->left),height(root->right))+1;
    }

// Why return -1 when root == nullptr?
//
// Suppose we are at a leaf node (5):
//
//        5
//       / \
//   nullptr nullptr
//
// We are calculating height in terms of EDGES.
// A leaf node has height 0 because there are 0 edges below it.
//
// So:
// height(5) = max(height(nullptr), height(nullptr)) + 1
//            = max(-1, -1) + 1
//            = -1 + 1
//            = 0
//
// Therefore, we return -1 for nullptr so that a leaf node's height
// correctly becomes 0.

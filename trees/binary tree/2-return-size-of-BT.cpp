int getSize(Node* root) {
    
       if(root == nullptr){return 0;}
       return getSize(root->left) + getSize(root->right)+1;
     
    }

class Solution {
  public:
    int findMax(Node *root) {
        // code here
        if(root==nullptr){return INT_MIN;}
        
        int maxi = max(findMax(root->left),findMax(root->right));
        return max(maxi,root->data);
      
        
    
    }

    int findMin(Node *root) {
        // code here
         if(root==nullptr){return INT_MAX;}
        
         int mini = min(findMin(root->left),findMin(root->right));
         return min(mini,root->data);
    }
};

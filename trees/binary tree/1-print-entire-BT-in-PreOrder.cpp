//Q.Given root node of a binary tree, print entire BT in preOrder

void preOrder(Node* root)
{
  if(root == nullptr)
  {return};

  cout<<(root->data)<<" ";
  preOrder(root->left);
  preOrder(root->right);
  
}

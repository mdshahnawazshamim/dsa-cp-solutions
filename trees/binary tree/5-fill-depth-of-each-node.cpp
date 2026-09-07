//Q. Given a binary tree, fill the depth of each node

class Node{
public:

int data,depth;
Node *left,*right;

Node(int x)
{
  left = right = nullptr;
  data = x;
}


};

void fillDepth(Node* root, int d)
{
  if(root == nullptr){return;}

  root->depth = d;

  fillDepth(root->left,d+1);
  fillDepth(root->right,d+1);
  
}

int main()
{
 fillDepth(root, 0);
}

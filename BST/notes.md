# Binary Search Tree (BST) — Complete Notes

## 1. What is a Binary Search Tree?

A **Binary Search Tree (BST)** is a special type of binary tree in which each node follows these rules:

- **Left subtree:** Contains values smaller than the node's value.
- **Right subtree:** Contains values greater than the node's value.
- Both left and right subtrees must also follow the BST property.

**Example:**

```text
          50
         /  \
       30    70
      / \    / \
     20 40  60 80
```

For the node `50`:
- All values on the left are smaller than `50`.
- All values on the right are greater than `50`.

*Note: These notes assume distinct keys. Duplicate-handling rules depend on the implementation.*

## 2. Binary Tree vs Binary Search Tree

| Feature | Binary Tree | BST |
|---|---|---|
| Maximum children | 2 | 2 |
| Ordering rule | No specific rule | Left < Root < Right |
| Searching | Usually O(n) | Average O(log n) |
| Inorder traversal | Not necessarily sorted | Sorted order |

## 3. Important Terminology

- **Root:** The topmost node.
- **Parent:** A node that has child nodes.
- **Leaf:** A node with no children.
- **Subtree:** A node and all its descendants.
- **Height:** The length of the longest downward path from a node to a leaf, measured in edges.
- **Depth:** The number of edges from the root to a node.

## 4. Searching in a BST

To search for a value:

1. Start at the root.
2. If the target equals the current node, the value is found.
3. If the target is smaller, move left.
4. If the target is greater, move right.
5. If you reach `NULL`, the value does not exist in the tree.

**Example:** Search for `60`.

```text
          50
         /  \
       30    70
            /  \
           60   80
```

Path: `50 → 70 → 60`

At each step, the BST property eliminates the subtree that cannot contain the target.

### C++ Implementation

```cpp
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

bool search(Node* root, int key) {
    if (root == nullptr)
        return false;

    if (root->data == key)
        return true;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}
```

## 5. Insertion in a BST

Insertion always places the new value at an appropriate empty position while preserving the BST property.

**Algorithm:**
1. If the tree is empty, create a new root.
2. If the value is smaller than the current node, move left.
3. If the value is greater, move right.
4. Repeat until an empty position is found.
5. Insert the new node there.

### C++ Implementation

```cpp
Node* insert(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}
```

This implementation ignores duplicate values.

## 6. Deletion in a BST

Deletion has three main cases.

### Case 1: Node is a leaf

Simply remove the node.

```text
Before:              After deleting 20:

     30                    30
    /  \                     \
   20  40                    40
```

### Case 2: Node has one child

Replace the node with its only child.

```text
Before:              After deleting 30:

     30                    40
       \
        40
```

### Case 3: Node has two children

1. Find the inorder successor (the smallest value in the right subtree), or the inorder predecessor (the largest value in the left subtree).
2. Copy that value into the node being deleted.
3. Delete the successor or predecessor from its original position.

The successor has no left child, so its removal reduces to the leaf or one-child case.

## 7. Tree Traversals

Traversal means visiting every node in a particular order.

Consider this tree:

```text
          50
         /  \
       30    70
      / \    / \
     20 40  60 80
```

| Traversal | Order | Output |
|---|---|---|
| Inorder | Left → Root → Right | 20 30 40 50 60 70 80 |
| Preorder | Root → Left → Right | 50 30 20 40 70 60 80 |
| Postorder | Left → Right → Root | 20 40 30 60 80 70 50 |
| Level order | Level by level | 50 30 70 20 40 

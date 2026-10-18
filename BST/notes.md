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
| Level order | Level by level | 50 30 70 20 40 60 80 |

**Important:** Inorder traversal of a BST produces values in sorted ascending order when keys are distinct.

### C++ Traversal Code

```cpp
void inorder(Node* root) {
    if (root == nullptr) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == nullptr) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
```

## 8. Time Complexity

Let `n` be the number of nodes and `h` be the height of the tree.

| Operation | Average case | Worst case |
|---|---:|---:|
| Search | O(log n) | O(n) |
| Insertion | O(log n) | O(n) |
| Deletion | O(log n) | O(n) |
| Traversal | O(n) | O(n) |
| Find minimum/maximum | O(log n) | O(n) |

A BST does **not** automatically remain balanced.

### Why can the worst case be O(n)?

If we insert values in ascending order, such as `10, 20, 30, 40, 50`, the tree becomes skewed:

```text
10
  \
   20
     \
      30
        \
         40
           \
            50
```

Searching can then require visiting every node.

Balanced BSTs, such as AVL trees and Red-Black trees, maintain logarithmic height through additional balancing rules.

## 9. Applications of BSTs

- Maintaining data in sorted order.
- Efficient searching, insertion and deletion in dynamic data.
- Finding minimum and maximum elements.
- Finding predecessor and successor values.
- Implementing ordered sets and maps.
- Range queries and sorted data processing.

## 10. Key Points for Competitive Programming

- Inorder traversal of a BST gives sorted output.
- A BST can become skewed, so ordinary BST operations are not always O(log n).
- Insertion order affects the tree's shape.
- Deletion with two children commonly uses the inorder successor.
- Searching follows only one path from the root.
- A BST is not the same as a binary heap.
- An empty tree has height `-1` under the edge-count convention used in these notes; some sources use a different convention.

## 11. Practice Questions

Try solving these without looking at the implementation first:

1. Insert `50, 30, 70, 20, 40, 60, 80` into an empty BST and draw the result.
2. Find the inorder, preorder and postorder traversals of the resulting tree.
3. Search for `60` and write the path followed.
4. Delete a leaf node, a node with one child, and a node with two children.
5. Explain why sorted insertion can make a BST inefficient.
6. Find the minimum and maximum values in a BST.
7. Construct a BST from a given preorder traversal.

---

**Quick revision:** BST property = Left < Root < Right. Inorder = sorted order. Search, insertion and deletion take O(h), where `h` is the tree height. In the worst case, `h = O(n)`.


A BST is not the same as a binary heap.

An empty tree has height -1 under the edge-count convention used in these notes; some sources use a different convention.


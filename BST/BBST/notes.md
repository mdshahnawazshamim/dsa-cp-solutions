# Balanced Binary Search Tree (BBST) — Complete Notes

## 1. What is a BBST?

A **Balanced Binary Search Tree (BBST)** is a Binary Search Tree that maintains its height approximately logarithmic in the number of nodes, allowing efficient searching, insertion, and deletion.

If a Balanced Binary Search Tree has n nodes, then its height would be log₂(n)

A normal BST can become skewed if values are inserted in sorted order. A BBST uses balancing rules to prevent this from happening.

### Example

**Balanced BST:**

```text
          40
         /  \
       20    60
      / \    / \
     10 30  50 70
```

**Skewed BST:**

```text
10
  \
   20
     \
      30
        \
         40
```

For a balanced tree, the height is \(O(\log n)\). For a skewed tree, the height can be \(O(n)\).

## 2. Why Do We Need BBSTs?

In an ordinary BST, performance depends on the tree's shape.

| Operation | Balanced BST | Skewed BST |
|---|---:|---:|
| Search | O(log n) | O(n) |
| Insertion | O(log n) | O(n) |
| Deletion | O(log n) | O(n) |

BBSTs maintain efficient operations by restructuring the tree when necessary.

## 3. What Does Balanced Mean?

A tree is balanced when its height is controlled relative to the number of nodes.

Different BBSTs use different definitions and balancing rules.

For example:
- **AVL Tree:** Strictly controls the height difference between left and right subtrees at every node.
- **Red-Black Tree:** Uses node colors and structural rules to guarantee logarithmic height.
- **B-Tree:** A multiway balanced search tree commonly used in databases and storage systems.

A BBST does not necessarily have exactly equal numbers of nodes on both sides.

## 4. Types of Balanced Binary Search Trees

### 4.1 AVL Tree

An AVL tree is a self-balancing Binary Search Tree (BST) in which the height difference between the left and right subtrees of every node is at most one.

### Balance Factor (BF)

The balance factor of a node is calculated as:

**BF = Height of Left Subtree − Height of Right Subtree**

For every node in a valid AVL tree:

**BF = -1, 0, or +1**

- **BF = -1:** The right subtree is one level taller.
- **BF = 0:** Both subtrees have equal heights.
- **BF = +1:** The left subtree is one level taller.

### AVL Balance Condition

For every node:

**|Height of Left Subtree − Height of Right Subtree| ≤ 1**

If any node's balance factor becomes less than -1 or greater than +1 after insertion or deletion, the tree violates the AVL balance condition and requires rebalancing through rotations.

### 4.2 Red-Black Tree

A Red-Black Tree assigns each node a color: red or black. It follows specific coloring and path rules that ensure the height remains \(O(\log n)\).

Important properties:

1. Every node is red or black.
2. The root is black.
3. Null leaves are treated as black.
4. A red node cannot have a red child.
5. Every path from a node to its descendant null leaves contains the same number of black nodes.

Red-Black Trees are less strictly balanced than AVL trees but provide efficient updates.

### 4.3 Other Balanced Search Trees

- **Splay Tree:** Moves recently accessed nodes toward the root; operations have amortized logarithmic time.
- **Treap:** Combines BST ordering by key with heap ordering by priority; expected logarithmic height under suitable random priorities.
- **B-Tree:** Allows multiple keys and children per node, making it useful for databases and filesystems.

## 5. Rotations in BBSTs

Rotations restructure a tree while preserving the BST ordering property.

They are commonly used in AVL trees and Red-Black Trees.

### 5.1 Right Rotation

A right rotation is used when a subtree is too heavy on the left in the appropriate configuration.

Before:

```text
        30
       /
      20
     /
    10
```

After right rotation:

```text
       20
      /  \
     10   30
```

The node `20` becomes the new root of this subtree.

### 5.2 Left Rotation

A left rotation is the mirror image of a right rotation.

Before:

```text
    10
      \
       20
         \
          30
```

After left rotation:

```text
       20
      /  \
     10   30
```

### Why Are Rotations Important?

- They reduce excessive height in a subtree.
- They preserve the relative order of keys.
- They restore the balancing requirements of a self-balancing BST.

## 6. AVL Tree Imbalance Cases

AVL insertion can cause four common imbalance patterns.

### Case 1: LL (Left-Left)

A node is inserted into the left subtree of the left child.

```text
       30
      /
     20
    /
   10
```

**Fix:** One right rotation.

### Case 2: RR (Right-Right)

A node is inserted into the right subtree of the right child.

```text
   10
     \
      20
        \
         30
```

**Fix:** One left rotation.

### Case 3: LR (Left-Right)

A node is inserted into the right subtree of the left child.

```text
       30
      /
     10
       \
        20
```

**Fix:**
1. Left-rotate the left child.
2. Right-rotate the unbalanced node.

### Case 4: RL (Right-Left)

A node is inserted into the left subtree of the right child.

```text
   10
     \
      30
     /
    20
```

**Fix:**
1. Right-rotate the right child.
2. Left-rotate the unbalanced node.

**Memory trick:**

- LL → Right rotation
- RR → Left rotation
- LR → Left, then right
- RL → Right, then left

## 7. Time Complexity

For AVL trees and Red-Black Trees:

| Operation | Time Complexity |
|---|---:|
| Search | O(log n) |
| Insertion | O(log n) |
| Deletion | O(log n) |
| Minimum / Maximum | O(log n) |
| Full traversal | O(n) |

The first five operations depend on tree height, which remains logarithmic. A traversal visits every node, so it takes linear time.

## 8. AVL Tree vs Red-Black Tree

| Feature | AVL Tree | Red-Black Tree |
|---|---|---|
| Balancing | Strict | Less strict |
| Search | Often faster in practice for lookup-heavy workloads | Efficient |
| Updates | May require more rebalancing | Often fewer rotations |
| Extra information | Height or balance factor | Node color |
| Typical use | Lookup-heavy applications | General-purpose ordered maps and sets |

Both guarantee \(O(\log n)\) worst-case search, insertion, and deletion.

## 9. Applications of BBSTs

- Ordered sets and maps.
- Maintaining dynamically changing sorted data.
- Range queries and predecessor/successor searches.
- Scheduling systems and event management.
- Database and storage structures (including multiway trees such as B-Trees).
- Applications requiring predictable worst-case search time.

## 10. BBST vs Heap

| Feature | BBST | Binary Heap |
|---|---|---|
| Ordering | BST key ordering | Parent-child heap ordering |
| Search for arbitrary key | O(log n) in balanced trees | O(n) |
| Find minimum | O(log n) generally; O(1) if cached | O(1) in a min-heap |
| Sorted traversal | Yes, via inorder | No |
| Typical use | Ordered data and range queries | Priority queues |

## 11. Important Competitive Programming Points

1. A normal BST is not necessarily balanced.
2. AVL trees maintain a balance factor of -1, 0, or +1 at every node.
3. LL and RR cases require single rotations.
4. LR and RL cases require double rotations.
5. AVL and Red-Black Trees guarantee logarithmic worst-case height.
6. `std::set` and `std::map` in C++ provide ordered operations with logarithmic complexity, typically implemented using Red-Black Trees.
7. `std::unordered_set` and `std::unordered_map` are hash-table-based containers, not BBSTs.
8. A balanced tree still requires \(O(n)\) time to visit every node.

## 12. Practice Questions

1. Explain why a normal BST can have O(n) search time.
2. What is the balance factor of an AVL node?
3. Identify the rotation required for each sequence: `30, 20, 10`; `10, 20, 30`; `30, 10, 20`; `10, 30, 20`.
4. Explain the difference between AVL and Red-Black Trees.
5. Why does inorder traversal of a BST produce sorted keys?
6. Why is a heap not a replacement for a BBST when arbitrary keys must be searched?
7. Which C++ STL containers commonly use balanced search trees?

---

## Quick Revision

- **BBST:** Maintains logarithmic height.
- **AVL:** Strict height balancing.
- **Red-Black:** Color-based balancing rules.
- **LL:** Right rotation.
- **RR:** Left rotation.
- **LR:** Left rotation followed by right rotation.
- **RL:** Right rotation followed by left rotation.
- **Search / Insert / Delete:** O(log n) in AVL and Red-Black Trees.
- **Traversal:** O(n).

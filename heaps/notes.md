# Comprehensive Guide to Heaps in C++

Welcome to the complete guide on **Heaps** implemented in C++. This document is structured to serve as an in-depth reference for understanding heap data structures, their properties, implementations from scratch, standard library usages, and common algorithmic problem patterns.

---

## Table of Contents
1. [Introduction to Heaps](#1-introduction-to-heaps)
2. [Types of Heaps](#2-types-of-heaps)
3. [Array Representation of Binary Heap](#3-array-representation-of-binary-heap)
4. [Core Heap Operations](#4-core-heap-operations)
5. [C++ Implementation from Scratch](#5-c-implementation-from-scratch)
6. [C++ Standard Template Library (STL) Priority Queue](#6-c-standard-template-library-stl-priority-queue)
7. [Heap Sort Algorithm](#7-heap-sort-algorithm)
8. [Common Algorithmic Patterns & Problems](#8-common-algorithmic-patterns--problems)
9. [Complexity Summary](#9-complexity-summary)

---

## 1. Introduction to Heaps

A **Heap** is a specialized tree-based data structure that satisfies the **Heap Property**. It is a **Complete Binary Tree**, meaning every level of the tree is fully filled, except possibly the last level, which is filled from left to right.

### Key Characteristics:
* **Complete Binary Tree Property**: Prevents structural gaps and allows efficient array representation.
* **Heap Property**: Dictates the parent-child ordering relation.
* **Efficient Operations**: Insertion, deletion, and finding the minimum/maximum element can be performed efficiently in logarithmic or constant time.

---

## 2. Types of Heaps

### 1. Max-Heap
In a Max-Heap, the key present at the root node must be greater than or equal to the keys present at all of its children. This property must be recursively true for all sub-trees.

```text
        [90]
       /    \
    [80]    [70]
   /   \    /   \
 [40] [30] [10] [50]
```

### 2. Min-Heap
In a Min-Heap, the key present at the root node must be less than or equal to the keys present at all of its children. This property must be recursively true for all sub-trees.

```text
        [10]
       /    \
    [30]    [20]
   /   \    /   \
 [40] [50] [70] [80]
```

---

## 3. Array Representation of Binary Heap

Since a binary heap is a complete binary tree, it can be efficiently represented using a 1D array without requiring explicit pointer links.

For an element stored at **0-based index `i`**:
* **Parent Index**: `(i - 1) / 2`
* **Left Child Index**: `2 * i + 1`
* **Right Child Index**: `2 * i + 2`

For an element stored at **1-based index `i`**:
* **Parent Index**: `i / 2`
* **Left Child Index**: `2 * i`
* **Right Child Index**: `2 * i + 1`

```text
Tree View:
       10 (0)
      /      \
   20 (1)    30 (2)
  /    \
40 (3) 50 (4)

Array View:
+----+----+----+----+----+
| 10 | 20 | 30 | 40 | 50 |
+----+----+----+----+----+
  0    1    2    3    4   (Indices)
```

---

## 4. Core Heap Operations

### 1. Heapify (Down-Heap / Percolate Down)
Maintains the heap property after deleting the root element or building a heap. If a node violates the heap property, it is swapped with its larger (Max-Heap) or smaller (Min-Heap) child, continuing recursively down the tree.

* **Time Complexity**: $\mathcal{O}(\log N)$

### 2. Insertion (Up-Heap / Percolate Up)
1. Add the new element at the end of the array (maintaining the Complete Binary Tree property).
2. Compare the inserted element with its parent.
3. If it violates the heap property, swap it with its parent.
4. Repeat process upward until the heap property is restored.

* **Time Complexity**: $\mathcal{O}(\log N)$

### 3. Deletion (Extract Top)
1. Replace the root element (maximum or minimum) with the last element in the array.
2. Remove the last element from the array.
3. Call `heapify` on the root element to restore the heap property.

* **Time Complexity**: $\mathcal{O}(\log N)$

### 4. Build Heap
Converts an unsorted array into a heap.
* Starting from the last non-leaf node `(n/2 - 1)` down to the root `0`, perform `heapify`.
* **Time Complexity**: $\mathcal{O}(N)$ (Mathematically bounded by $\sum_{h=0}^{\log N} \frac{N}{2^{h+1}} \cdot O(h) = O(N)$)

---

## 5. C++ Implementation from Scratch

Below is a generic **Max-Heap** class implementation in C++ using `std::vector`.

```cpp
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

template <typename T>
class MaxHeap {
private:
    std::vector<T> heap;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    // Percolate down to fix heap property
    void heapifyDown(int i) {
        int maxIndex = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < heap.size() && heap[left] > heap[maxIndex]) {
            maxIndex = left;
        }

        if (right < heap.size() && heap[right] > heap[maxIndex]) {
            maxIndex = right;
        }

        if (i != maxIndex) {
            std::swap(heap[i], heap[maxIndex]);
            heapifyDown(maxIndex);
        }
    }

    // Percolate up to fix heap property
    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            std::swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

public:
    MaxHeap() = default;

    // Build Heap from an existing vector
    MaxHeap(const std::vector<T>& array) {
        heap = array;
        for (int i = (heap.size() / 2) - 1; i >= 0; --i) {
            heapifyDown(i);
        }
    }

    void insert(T key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    T getMax() const {
        if (heap.empty()) {
            throw std::underflow_error("Heap is empty!");
        }
        return heap[0];
    }

    T extractMax() {
        if (heap.empty()) {
            throw std::underflow_error("Heap is empty!");
        }
        T root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heapifyDown(0);
        }
        return root;
    }

    bool empty() const {
        return heap.empty();
    }

    size_t size() const {
        return heap.size();
    }
};

int main() {
    MaxHeap<int> h;
    h.insert(10);
    h.insert(20);
    h.insert(15);
    h.insert(30);
    h.insert(40);

    std::cout << "Max element: " << h.getMax() << std::endl; // Output: 40

    std::cout << "Extracted elements in descending order: ";
    while (!h.empty()) {
        std::cout << h.extractMax() << " "; // Output: 40 30 20 15 10
    }
    std::cout << std::endl;

    return 0;
}
```

---

## 6. C++ Standard Template Library (STL) Priority Queue

The C++ Standard Library provides `std::priority_queue` defined in `<queue>`.

### 1. Max-Heap (Default)
```cpp
#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> maxHeap;

    maxHeap.push(10);
    maxHeap.push(30);
    maxHeap.push(20);

    std::cout << "Top element: " << maxHeap.top() << std::endl; // 30
    maxHeap.pop();
    std::cout << "Next element: " << maxHeap.top() << std::endl; // 20

    return 0;
}
```

### 2. Min-Heap
```cpp
#include <iostream>
#include <queue>
#include <vector>

int main() {
    // Syntax: priority_queue<Type, Container, Comparator>
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    minHeap.push(10);
    minHeap.push(30);
    minHeap.push(20);

    std::cout << "Top element: " << minHeap.top() << std::endl; // 10
    minHeap.pop();
    std::cout << "Next element: " << minHeap.top() << std::endl; // 20

    return 0;
}
```

### 3. Custom Comparator Example
```cpp
#include <iostream>
#include <queue>
#include <vector>
#include <string>

struct Student {
    std::string name;
    int marks;

    Student(std::string n, int m) : name(n), marks(m) {}
};

// Custom Comparator (Higher marks gets higher priority)
struct CompareStudent {
    bool operator()(const Student& a, const Student& b) {
        return a.marks < b.marks; // For Min-Heap like ordering on marks, use >
    }
};

int main() {
    std::priority_queue<Student, std::vector<Student>, CompareStudent> pq;

    pq.push(Student("Alice", 85));
    pq.push(Student("Bob", 92));
    pq.push(Student("Charlie", 78));

    while (!pq.empty()) {
        Student topStudent = pq.top();
        std::cout << topStudent.name << ": " << topStudent.marks << std::endl;
        pq.pop();
    }

    return 0;
}
```

---

## 7. Heap Sort Algorithm

Heap Sort works by constructing a Max-Heap from an array and repeatedly extracting the maximum element to place it at the end of the array.

### Algorithm Steps:
1. Build a Max-Heap from the input array ($\mathcal{O}(N)$).
2. Swap the root (maximum element) with the last element of the heap.
3. Reduce heap size by 1.
4. Heapify the root element ($\mathcal{O}(\log N)$).
5. Repeat steps 2-4 until the heap size becomes 1.

```cpp
#include <iostream>
#include <vector>

void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // Step 1: Build Max-Heap
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    // Step 2: Extract elements one by one
    for (int i = n - 1; i > 0; --i) {
        std::swap(arr[0], arr[i]); // Move root to end
        heapify(arr, i, 0);        // Call heapify on reduced heap
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};

    heapSort(arr);

    std::cout << "Sorted array: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
```

---

## 8. Common Algorithmic Patterns & Problems

### Pattern 1: Top K Elements
Used when finding $K$ largest, smallest, or most frequent elements.
* **Approach**: Use a Min-Heap of size $K$ to find $K$ largest elements.

```cpp
#include <vector>
#include <queue>

// Find Kth Largest Element in an Array
int findKthLargest(std::vector<int>& nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    for (int num : nums) {
        minHeap.push(num);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    return minHeap.top();
}
```

### Pattern 2: Two Heaps Pattern
Used when processing streaming data where continuous median tracking is needed.
* **Approach**: Maintain a Max-Heap for the lower half and a Min-Heap for the upper half.

```cpp
#include <queue>

class MedianFinder {
    std::priority_queue<int> maxHeapLower; // Left side
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeapUpper; // Right side

public:
    void addNum(int num) {
        if (maxHeapLower.empty() || num <= maxHeapLower.top()) {
            maxHeapLower.push(num);
        } else {
            minHeapUpper.push(num);
        }

        // Rebalance heaps to maintain equal size property
        if (maxHeapLower.size() > minHeapUpper.size() + 1) {
            minHeapUpper.push(maxHeapLower.top());
            maxHeapLower.pop();
        } else if (minHeapUpper.size() > maxHeapLower.size()) {
            maxHeapLower.push(minHeapUpper.top());
            minHeapUpper.pop();
        }
    }

    double findMedian() {
        if (maxHeapLower.size() > minHeapUpper.size()) {
            return maxHeapLower.top();
        }
        return (maxHeapLower.top() + minHeapUpper.top()) / 2.0;
    }
};
```

---


# Intel-Subsidary-Assignment
---
#Data Structures – Tree Insertion Algorithms

This repository contains C++ implementations of Binary Search Tree (BST) insertion and Red-Black Tree insertion as part of a Data Structures and Algorithms assignment.

The aim of this project is to understand how different tree-based data structures handle insertion and how balancing affects performance.

##Binary Search Tree (BST) Insertion

The Binary Search Tree insertion algorithm inserts elements by maintaining the BST property:

Values smaller than the current node are inserted into the left subtree.

Values greater than or equal to the current node are inserted into the right subtree.

This implementation uses a recursive approach and demonstrates how BSTs can become unbalanced in the worst case.

Time Complexity:

Best/Average case: O(log n)

Worst case (skewed tree): O(n)

##Red-Black Tree Insertion

The Red-Black Tree insertion follows the standard algorithm described in Introduction to Algorithms (CLRS).
A new node is first inserted as in a normal BST and then recolored and rotated to maintain the red-black properties.

Red-Black Trees guarantee that the tree remains balanced, ensuring efficient operations.

Key Properties:

Each node is either red or black.

The root is always black.

No two red nodes appear consecutively.

All paths from a node to its leaf nodes contain the same number of black nodes.

Time Complexity:

Insertion: O(log n) in all cases.

# Depth-First Search (DFS) - Conceptual Guide

## What is DFS?
Depth-First Search is a graph traversal algorithm that explores as far as possible along each branch before backtracking.
It goes deep into the graph before exploring siblings at the same level.

## Key Characteristics:
- Uses a Stack (LIFO - Last In First Out) or Recursion
- Explores branch by branch (depth-first)
- Memory efficient for deep, narrow graphs
- Time Complexity: O(V + E)
- Space Complexity: O(h) where h is the height/depth

---

## DFS Example: Tree Traversal

### Initial Tree Structure:
```
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
```

**Starting vertex: 1**

---

## Step-by-Step DFS Execution:

### Step 1: Initialize
```
Stack: [1]
Visited: {1}
Output: []

          (1)  ← Current
        /   \
       2     3
      / \   / \
     4   5 6   7
```

---

### Step 2: Visit vertex 1
- Pop 1 from stack
- Process vertex 1
- Push unvisited children: 3, 2 (right to left)

```
Stack: [3, 2]
Visited: {1}
Output: [1]

          1
        /   \
      (2)   (3)  ← Added to stack (3 on top)
      / \   / \
     4   5 6   7
```

---

### Step 3: Visit vertex 2 (top of stack)
- Pop 2 from stack
- Process vertex 2
- Push unvisited children: 5, 4 (right to left)

```
Stack: [3, 5, 4]
Visited: {1, 2}
Output: [1, 2]

          1
        /   \
       2     3
      / \   / \
    (4) (5) 6   7  ← Added to stack (4 on top)
```

---

### Step 4: Visit vertex 4 (top of stack)
- Pop 4 from stack
- Process vertex 4
- No unvisited children

```
Stack: [3, 5]
Visited: {1, 2, 4}
Output: [1, 2, 4]

          1
        /   \
       2     3
      / \   / \
     4   5 6   7
```

---

### Step 5: Visit vertex 5 (top of stack)
- Pop 5 from stack
- Process vertex 5
- No unvisited children

```
Stack: [3]
Visited: {1, 2, 4, 5}
Output: [1, 2, 4, 5]

          1
        /   \
       2     3
      / \   / \
     4   5 6   7
```

---

### Step 6: Visit vertex 3 (top of stack)
- Pop 3 from stack
- Process vertex 3
- Push unvisited children: 7, 6 (right to left)

```
Stack: [7, 6]
Visited: {1, 2, 4, 5, 3}
Output: [1, 2, 4, 5, 3]

          1
        /   \
       2     3
      / \   / \
     4   5 (6) (7)  ← Added to stack (6 on top)
```

---

### Step 7: Visit vertex 6 (top of stack)
- Pop 6 from stack
- Process vertex 6
- No unvisited children

```
Stack: [7]
Visited: {1, 2, 4, 5, 3, 6}
Output: [1, 2, 4, 5, 3, 6]
```

---

### Step 8: Visit vertex 7 (top of stack)
- Pop 7 from stack
- Process vertex 7
- No unvisited children
- Stack is now empty

```
Stack: []
Visited: {1, 2, 4, 5, 3, 6, 7}
Output: [1, 2, 4, 5, 3, 6, 7]
```

---

## Final DFS Traversal Order:
```
1 → 2 → 4 → 5 → 3 → 6 → 7
```

### Path Visualization:
```
Depth exploration:
1 (root)
├─ 2 (left child)
│  ├─ 4 (left leaf)
│  └─ 5 (right leaf)
└─ 3 (right child)
   ├─ 6 (left leaf)
   └─ 7 (right leaf)
```

---

## DFS Algorithm (Pseudocode):

### Iterative Approach (using Stack):
```
DFS_Iterative(start_vertex):
    1. Create a stack S
    2. Push start_vertex into S
    3. Mark start_vertex as visited
    
    4. While S is not empty:
        a. current = Pop from S
        b. Process current (print/store)
        
        c. For each neighbor of current (in reverse order):
            i.  If neighbor not visited:
                - Mark neighbor as visited
                - Push neighbor into S
```

### Recursive Approach:
```
DFS_Recursive(vertex):
    1. Mark vertex as visited
    2. Process vertex (print/store)
    
    3. For each neighbor of vertex:
        a. If neighbor not visited:
            - DFS_Recursive(neighbor)
```

---

## DFS Traversal Types:

### 1. Pre-order (Root → Left → Right):
- Visit root first
- Then traverse left subtree
- Finally traverse right subtree
- **Example:** 1, 2, 4, 5, 3, 6, 7

### 2. In-order (Left → Root → Right):
- Traverse left subtree first
- Visit root
- Then traverse right subtree
- **Example:** 4, 2, 5, 1, 6, 3, 7

### 3. Post-order (Left → Right → Root):
- Traverse left subtree first
- Then traverse right subtree
- Finally visit root
- **Example:** 4, 5, 2, 6, 7, 3, 1

---

## Applications of DFS:

1. **Topological Sorting**: Ordering tasks with dependencies
2. **Cycle Detection**: Finding cycles in directed/undirected graphs
3. **Path Finding**: Finding paths between two vertices
4. **Connected Components**: Finding all connected components
5. **Maze Solving**: Finding way through mazes
6. **Backtracking Problems**: N-Queens, Sudoku solver
7. **Tree/Graph Traversals**: In-order, pre-order, post-order
8. **Strongly Connected Components**: Kosaraju's algorithm

---

## BFS vs DFS Comparison:

| Feature | BFS | DFS |
|---------|-----|-----|
| Data Structure | Queue (FIFO) | Stack (LIFO) or Recursion |
| Traversal | Level by level | Branch by branch |
| Shortest Path | Yes (unweighted) | No |
| Space | O(V) | O(h) where h=height |
| Memory | More (stores all nodes at level) | Less (stores path only) |
| Use Case | Shortest path | Topological sort, cycles |
| When to Use | Wide, shallow graphs | Deep, narrow graphs |
| Completeness | Complete | Complete (finite graphs) |

---

## Important Notes:

✓ DFS explores as deep as possible before backtracking
✓ Can use explicit stack or recursion (implicit stack)
✓ Memory efficient for deep graphs
✓ Does NOT guarantee shortest path
✓ Preferred for topological sorting and cycle detection
✓ Better for decision tree problems and backtracking
✓ Can get stuck in infinite loops if not careful (in infinite graphs)

# Minimum Cost Path in a Grid (0–1 BFS)

##  Intuition

Each cell in the grid contains a direction (`1`–`4`) that indicates the **preferred direction** of movement from that cell.

- If we move in the preferred direction → **cost = 0**
- If we move in any other direction → **cost = 1** (we change the direction)

So the problem reduces to:

> Find the **minimum cost path** from the top-left cell `(0,0)` to the bottom-right cell `(n−1, m−1)` where each move has a cost of either `0` or `1`.

Since all edge weights are only `0` or `1`, we can efficiently solve this problem using **0–1 BFS** instead of Dijkstra’s algorithm.

---

##  Approach

### Key Observations

- Each cell represents a **node** in a graph.
- From each cell, we can move in **4 directions** (up, right, down, left).
- Moving in the cell’s indicated direction costs `0`; otherwise, it costs `1`.

---

### Step-by-Step Solution

#### 1. Direction Mapping
- Use `dx` and `dy` arrays to represent movement in the four directions.
- Use a `dir[]` array to map direction indices to grid direction values.

#### 2. 0–1 BFS
- Use a `deque` instead of a priority queue.
- If the move cost is `0`, push the next cell to the **front** of the deque.
- If the move cost is `1`, push it to the **back**.

#### 3. Distance Array
- Maintain a `dist[][]` array to store the minimum cost to reach each cell.
- Initialize all distances with a large value (`INF`).

#### 4. Visited Array
- Maintain a `visited[][]` array to avoid re-processing already finalized cells.

#### 5. Traversal
- Start BFS from cell `(0,0)`.
- Relax edges based on their costs.
- Continue until all reachable cells are processed.

#### 6. Result
- The final answer is stored in `dist[n-1][m-1]`.



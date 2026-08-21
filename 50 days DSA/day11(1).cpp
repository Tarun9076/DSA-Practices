/*
===========================================================
              50 DAYS OF DSA
              PROBLEM: RAT IN A MAZE
===========================================================

Problem:
Given an n x n matrix representing a maze, find all possible
paths from the top-left cell (0,0) to the bottom-right cell
(n-1,n-1).

In the matrix:
    1 -> Open cell
    0 -> Blocked cell

The rat can move in four directions:

    D -> Down
    U -> Up
    L -> Left
    R -> Right

A cell cannot be visited more than once in the same path.

-----------------------------------------------------------
Example:

Input:

    1 0 0 0
    1 1 0 1
    1 1 0 0
    0 1 1 1

Possible paths:

    DDRDRR
    DRDDRR

-----------------------------------------------------------
Approach:
Use Backtracking + DFS.

Starting from (0,0):

1. Check whether the current cell is valid.
2. If the destination is reached, store the path.
3. Mark the current cell as visited.
4. Explore all four possible directions:
       Down
       Up
       Left
       Right
5. After exploring all directions, unmark the cell.
6. This allows the cell to be used in another possible path.

-----------------------------------------------------------
Why Do We Mark Cells as Visited?

Without marking visited cells, the rat could move in a
cycle.

For example:

    A -> B -> A -> B -> ...

Marking the current cell prevents revisiting it during
the current path.

-----------------------------------------------------------
Backtracking Pattern:

    Choose a cell
         ↓
    Mark as visited
         ↓
    Explore directions
         ↓
    Store solution if found
         ↓
    Unmark cell
         ↓
    Try another path

-----------------------------------------------------------
Validity Check:

A cell is invalid if:

    - It is outside the matrix.
    - It contains 0.
    - It has already been visited.

-----------------------------------------------------------
Key Concepts:
- Backtracking
- DFS
- Recursion
- Matrix Traversal
- Path Finding
- Visited State

-----------------------------------------------------------
Complexity:

Time Complexity:
O(4^(n²))

In the worst case, each cell can potentially explore
up to four directions.

Space Complexity:
O(n²)

The recursion depth and visited-state modification can
require O(n²) space in the worst case.

The output space is not included in the auxiliary space.

-----------------------------------------------------------
Key Learning:

Rat in a Maze is a classic example of combining
DFS with backtracking.

The main idea is:

    Explore a path
        ↓
    If it fails, backtrack
        ↓
    Try another path

The same backtracking pattern appears in problems such as
N-Queens, Sudoku, Permutations, Subsets and Maze problems.

===========================================================
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;


// DFS + Backtracking
void findPathHelper(
    vector<vector<int>>& mat,
    int r,
    int c,
    string path,
    vector<string>& ans
) {

    int n = mat.size();

    // Check whether the current cell is valid
    if (r < 0 || c < 0 ||
        r >= n || c >= n ||
        mat[r][c] == 0 ||
        mat[r][c] == -1) {

        return;
    }

    // Destination reached
    if (r == n - 1 && c == n - 1) {
        ans.push_back(path);
        return;
    }

    // Mark current cell as visited
    mat[r][c] = -1;

    // Move Down
    findPathHelper(
        mat,
        r + 1,
        c,
        path + 'D',
        ans
    );

    // Move Up
    findPathHelper(
        mat,
        r - 1,
        c,
        path + 'U',
        ans
    );

    // Move Left
    findPathHelper(
        mat,
        r,
        c - 1,
        path + 'L',
        ans
    );

    // Move Right
    findPathHelper(
        mat,
        r,
        c + 1,
        path + 'R',
        ans
    );

    // Backtrack:
    // Unmark the current cell so it can be used
    // in another possible path.
    mat[r][c] = 1;
}


// Find all possible paths
vector<string> findPath(vector<vector<int>>& mat) {

    vector<string> ans;

    // If the starting cell is blocked,
    // there is no possible path.
    if (mat.empty() || mat[0][0] == 0) {
        return ans;
    }

    string path = "";

    findPathHelper(
        mat,
        0,
        0,
        path,
        ans
    );

    return ans;
}


int main() {

    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> ans = findPath(mat);

    for (string path : ans) {
        cout << path << endl;
    }

    return 0;
}
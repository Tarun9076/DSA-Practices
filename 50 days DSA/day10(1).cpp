/*
===========================================================
              50 DAYS OF DSA - DAY 10
              PROBLEM: N-QUEENS
===========================================================

Problem: N-Queens

Problem Statement:
Given an integer n, place n queens on an n x n chessboard
such that no two queens attack each other.

Return all distinct valid board configurations.

-----------------------------------------------------------
Example:

Input:
n = 4

Output:
[
    [".Q..",
     "...Q",
     "Q...",
     "..Q."],

    ["..Q.",
     "Q...",
     "...Q",
     ".Q.."]
]

-----------------------------------------------------------
Approach:
Use Backtracking.

We place exactly one queen in each row.

For every row:
    1. Try every column.
    2. Check whether the position is safe.
    3. If safe, place the queen.
    4. Recursively solve the next row.
    5. Remove the queen (backtrack).
    6. Try the next column.

-----------------------------------------------------------
Safety Check:

A queen can attack another queen in three relevant
directions because we place queens row by row:

1. Same Column
   Check all previous rows in the same column.

2. Upper-Left Diagonal
   Move:
       row - 1
       col - 1

3. Upper-Right Diagonal
   Move:
       row - 1
       col + 1

We only need to check previous rows because the current
row is being processed from top to bottom.

-----------------------------------------------------------
Backtracking Pattern:

    Choose
      ↓
    Check
      ↓
    Explore
      ↓
    Undo
      ↓
    Try Next Choice

-----------------------------------------------------------
Base Case:

When:

    row == n

all n queens have been successfully placed.

The current board is therefore a valid solution.

-----------------------------------------------------------
Key Concepts:
- Backtracking
- Recursion
- Constraint Satisfaction
- Chessboard Traversal
- Decision Tree

-----------------------------------------------------------
Complexity:

Time Complexity:
Approximately O(N! * N)

The search space is exponential, with roughly N! possible
placements being explored in the worst case.

The additional N factor comes from checking whether a
position is safe.

Space Complexity:
O(N^2)

The board itself requires O(N^2) space.

The recursion depth is O(N).

-----------------------------------------------------------
Key Learning:

N-Queens demonstrates how backtracking can efficiently
explore a large search space by rejecting invalid choices
as early as possible.

The general pattern is:

    Choose -> Check -> Explore -> Undo

This pattern is useful in many constraint-based problems.

===========================================================
*/

class Solution {
public:

    // Check whether placing a queen at board[row][col]
    // is safe.
    bool isSafe(vector<string>& board, int row, int col, int n) {

        // Check the same column
        for (int i = 0; i < row; i++) {

            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1;
             i >= 0 && j >= 0;
             i--, j--) {

            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1;
             i >= 0 && j < n;
             i--, j++) {

            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }


    // Backtracking function
    void nQueens(
        vector<string>& board,
        int row,
        int n,
        vector<vector<string>>& ans
    ) {

        // All queens have been successfully placed
        if (row == n) {
            ans.push_back(board);
            return;
        }

        // Try placing a queen in every column
        for (int col = 0; col < n; col++) {

            // Check whether the position is safe
            if (isSafe(board, row, col, n)) {

                // Choose
                board[row][col] = 'Q';

                // Explore
                nQueens(
                    board,
                    row + 1,
                    n,
                    ans
                );

                // Undo the choice (Backtrack)
                board[row][col] = '.';
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {

        // Initialize empty board
        vector<string> board(
            n,
            string(n, '.')
        );

        vector<vector<string>> ans;

        // Start placing queens from row 0
        nQueens(
            board,
            0,
            n,
            ans
        );

        return ans;
    }
};
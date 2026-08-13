/*
===========================================================
              50 DAYS OF DSA - DAY 04
===========================================================

Problem: Spiral Matrix

Problem Statement:
Given an m x n matrix, return all elements of the matrix
in spiral order.

-----------------------------------------------------------
Example 1:

Input:
matrix = [[1,2,3],
          [4,5,6],
          [7,8,9]]

Output:
[1,2,3,6,9,8,7,4,5]

-----------------------------------------------------------
Example 2:

Input:
matrix = [[1,2,3,4],
          [5,6,7,8],
          [9,10,11,12]]

Output:
[1,2,3,4,8,12,11,10,9,5,6,7]

-----------------------------------------------------------
Constraints:
- m == matrix.length
- n == matrix[i].length
- 1 <= m, n <= 10
- -100 <= matrix[i][j] <= 100

-----------------------------------------------------------
Approach:
Use four boundaries to traverse the matrix layer by layer.

Boundaries:
- srow -> Starting row
- erow -> Ending row
- scol -> Starting column
- ecol -> Ending column

For each layer, traverse in four directions:

1. Left -> Right
   Traverse the top row.

2. Top -> Bottom
   Traverse the right column.

3. Right -> Left
   Traverse the bottom row.

4. Bottom -> Top
   Traverse the left column.

After completing one layer, move all four boundaries
inwards and process the next layer.

-----------------------------------------------------------
Important Edge Cases:

1. Single Row:
   Avoid traversing the same row twice.

2. Single Column:
   Avoid traversing the same column twice.

The conditions:
- if (srow == erow)
- if (scol == ecol)

prevent duplicate elements.

-----------------------------------------------------------
Key Concepts:
- Matrix Traversal
- Boundary Tracking
- Simulation
- 2D Arrays

-----------------------------------------------------------
Complexity:

Time Complexity  : O(m * n)

Every element of the matrix is visited exactly once.

Space Complexity : O(m * n)

The output vector stores all elements of the matrix.

Auxiliary Space : O(1)

Apart from the output vector, no additional data structure
is used.

-----------------------------------------------------------
Key Learning:

The main idea is to divide the matrix into layers and
traverse each layer in a fixed order:

        Left -> Right
        Top -> Bottom
        Right -> Left
        Bottom -> Top

By shrinking the four boundaries after every layer,
we can traverse the entire matrix without using a
visited array.

===========================================================
*/

class Solution {
public:

    vector<int> spiralOrder(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        int srow = 0;
        int erow = m - 1;

        int scol = 0;
        int ecol = n - 1;

        vector<int> ans;
        ans.reserve(m * n);

        while (srow <= erow && scol <= ecol) {

            // 1. Traverse top row: Left -> Right
            for (int j = scol; j <= ecol; j++) {
                ans.push_back(mat[srow][j]);
            }

            // 2. Traverse right column: Top -> Bottom
            for (int i = srow + 1; i <= erow; i++) {
                ans.push_back(mat[i][ecol]);
            }

            // 3. Traverse bottom row: Right -> Left
            // Avoid duplicate traversal when only one row remains
            if (srow != erow) {
                for (int j = ecol - 1; j >= scol; j--) {
                    ans.push_back(mat[erow][j]);
                }
            }

            // 4. Traverse left column: Bottom -> Top
            // Avoid duplicate traversal when only one column remains
            if (scol != ecol) {
                for (int i = erow - 1; i >= srow + 1; i--) {
                    ans.push_back(mat[i][scol]);
                }
            }

            // Move boundaries inward
            srow++;
            erow--;
            scol++;
            ecol--;
        }

        return ans;
    }
};
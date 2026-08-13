/*
===========================================================
              50 DAYS OF DSA - DAY 03
===========================================================

Problem: Search a 2D Matrix

Problem Statement:
Given an m x n integer matrix with the following properties:

1. Each row is sorted in non-decreasing order.
2. The first integer of each row is greater than the
   last integer of the previous row.

Given a target, return true if the target exists in the
matrix, otherwise return false.

The solution must have O(log(m * n)) time complexity.

-----------------------------------------------------------
Example 1:

Input:
matrix = [[1,3,5,7],
          [10,11,16,20],
          [23,30,34,60]]

target = 3

Output:
true

-----------------------------------------------------------
Example 2:

Input:
matrix = [[1,3,5,7],
          [10,11,16,20],
          [23,30,34,60]]

target = 13

Output:
false

-----------------------------------------------------------
Approach:
Use Binary Search in two stages.

1. Binary Search on Rows:
   Find the row where the target can possibly exist.

   Condition:
   matrix[midRow][0] <= target <= matrix[midRow][n-1]

2. Binary Search on the Selected Row:
   Once the possible row is found, perform a standard
   binary search within that row.

-----------------------------------------------------------
Key Concept:
- Binary Search
- 2D Matrix
- Divide and Conquer

-----------------------------------------------------------
Complexity:
Time Complexity:
O(log m + log n) = O(log(m * n))

Space Complexity:
O(1) auxiliary space

-----------------------------------------------------------
Key Learning:
The sorted structure of the matrix allows us to eliminate
entire rows before searching within a specific row.

Instead of checking every element, binary search reduces
the search space logarithmically.

===========================================================
*/

class Solution {
public:

    // Binary search within the selected row
    bool searchTar(const vector<vector<int>>& matrix,
                   int target,
                   int row) {

        int n = matrix[0].size();

        int st = 0;
        int end = n - 1;

        while (st <= end) {

            int mid = st + (end - st) / 2;

            if (target == matrix[row][mid]) {
                return true;
            }
            else if (target > matrix[row][mid]) {
                st = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        int stRow = 0;
        int endRow = m - 1;

        // Binary search to find the possible row
        while (stRow <= endRow) {

            int midRow = stRow + (endRow - stRow) / 2;

            // Target can exist in this row
            if (matrix[midRow][0] <= target &&
                matrix[midRow][n - 1] >= target) {

                return searchTar(matrix, target, midRow);
            }

            // Target is greater than the current row
            else if (target > matrix[midRow][n - 1]) {
                stRow = midRow + 1;
            }

            // Target is smaller than the current row
            else {
                endRow = midRow - 1;
            }
        }

        return false;
    }
};
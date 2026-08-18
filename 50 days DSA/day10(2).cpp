/*
===========================================================
              50 DAYS OF DSA - DAY 10
              PROBLEM: PERMUTATIONS
===========================================================

Problem: Permutations

Problem Statement:
Given an array nums containing distinct integers, return
all possible permutations of the array.

-----------------------------------------------------------
Example 1:

Input:
nums = [1,2,3]

Output:
[
    [1,2,3],
    [1,3,2],
    [2,1,3],
    [2,3,1],
    [3,1,2],
    [3,2,1]
]

-----------------------------------------------------------
Example 2:

Input:
nums = [0,1]

Output:
[
    [0,1],
    [1,0]
]

-----------------------------------------------------------
Approach:
Use Backtracking with In-place Swapping.

At every recursion level, the element at the current
index is fixed.

For every possible position:
    1. Swap the current element with nums[i].
    2. Recursively generate permutations for the next index.
    3. Swap back to restore the original array.

-----------------------------------------------------------
Example:

nums = [1,2,3]

At index 0:

    Swap 1 with 1 -> [1,2,3]
    Swap 1 with 2 -> [2,1,3]
    Swap 1 with 3 -> [3,2,1]

Each choice creates a different branch in the
recursion tree.

-----------------------------------------------------------
Backtracking Pattern:

    Choose
      ↓
    Swap
      ↓
    Explore
      ↓
    Undo Swap
      ↓
    Try Next Choice

The second swap restores the array to its previous state,
allowing the next permutation branch to be explored.

-----------------------------------------------------------
Base Case:

When:

    index == nums.size()

all positions have been fixed, so the current array
represents one complete permutation.

-----------------------------------------------------------
Key Concepts:
- Backtracking
- Recursion
- Swapping
- Permutations
- In-place Algorithm

-----------------------------------------------------------
Number of Permutations:

For n distinct elements:

    Total permutations = n!

For example:

    n = 3
    3! = 6

-----------------------------------------------------------
Complexity:

Time Complexity:
O(n * n!)

There are n! permutations, and storing each permutation
takes O(n) time.

Space Complexity:
O(n)

The recursion depth is O(n).

The output requires O(n * n!) space.

-----------------------------------------------------------
Key Learning:

Permutations can be generated efficiently using
backtracking and in-place swapping.

The important pattern is:

    Swap -> Recursion -> Swap Back

This avoids requiring an additional "visited" array.

===========================================================
*/

class Solution {
public:

    void getAllPermutations(
        vector<int>& nums,
        vector<vector<int>>& ans,
        int index
    ) {

        // Base case:
        // A complete permutation has been formed.
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        // Try placing every remaining element
        // at the current index.
        for (int i = index; i < nums.size(); i++) {

            // Choose
            swap(nums[index], nums[i]);

            // Explore
            getAllPermutations(
                nums,
                ans,
                index + 1
            );

            // Undo the choice (Backtrack)
            swap(nums[index], nums[i]);
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;

        getAllPermutations(
            nums,
            ans,
            0
        );

        return ans;
    }
};
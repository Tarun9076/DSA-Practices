/*
===========================================================
              50 DAYS OF DSA - DAY 09
              PROBLEM 2: SUBSETS II
===========================================================

Problem: 90. Subsets II

Problem Statement:
Given an integer array nums that may contain duplicates,
return all possible subsets (the power set).

The solution must not contain duplicate subsets.

-----------------------------------------------------------
Example 1:

Input:
nums = [1,2,2]

Output:
[[],[1],[1,2],[1,2,2],[2],[2,2]]

-----------------------------------------------------------
Example 2:

Input:
nums = [0]

Output:
[[],[0]]

-----------------------------------------------------------
Approach:
Use Recursion / Backtracking with Duplicate Handling.

The basic idea is the same as the normal Subsets problem:

For every element:

1. Include the current element.
2. Exclude the current element.

However, because the array may contain duplicates,
simply using the same approach would generate duplicate
subsets.

-----------------------------------------------------------
Step 1: Sort the Array

Sorting places duplicate values next to each other.

Example:

    [2,1,2]

becomes:

    [1,2,2]

This allows us to easily identify consecutive duplicates.

-----------------------------------------------------------
Step 2: Skip Duplicates

When taking the EXCLUDE branch, skip all consecutive
duplicate values.

Example:

    [1,2,2]

At the first 2, if we choose not to include it, we skip
the next duplicate 2 as well.

This prevents generating the same subset multiple times
at the same recursion level.

-----------------------------------------------------------
Important:

We only skip duplicates at the SAME recursion level.

We do NOT skip duplicates when moving deeper into the
recursion tree.

This is important because:

    [2,2]

is a valid subset and must be included in the answer.

-----------------------------------------------------------
Example:

nums = [1,2,2]

Possible unique subsets include:

[]
[1]
[2]
[2,2]
[1,2]
[1,2,2]

-----------------------------------------------------------
Duplicate Handling:

After including arr[i]:

    ans.push_back(arr[i]);

After returning:

    ans.pop_back();

For the exclude branch:

    int indx = i + 1;

    while (indx < arr.size() &&
           arr[indx] == arr[indx - 1]) {
        indx++;
    }

Then continue recursion from indx.

-----------------------------------------------------------
Key Concepts:
- Recursion
- Backtracking
- Sorting
- Duplicate Handling
- Decision Tree

-----------------------------------------------------------
Complexity:

Time Complexity:
O(n * 2^n) in the worst case.

Space Complexity:
O(n) auxiliary recursion space.

The output can require O(n * 2^n) space.

-----------------------------------------------------------
Key Learning:

For subsets with duplicates:

    Sort the array
           ↓
    Include current element
           ↓
    Undo the choice
           ↓
    Skip duplicate values
           ↓
    Explore the exclude branch

The important idea is:

"Skip duplicates at the same recursion level,
but allow them across different recursion levels."

===========================================================
*/

class Solution {
public:

    void returnAllSubsets(
        vector<int>& arr,
        vector<int>& ans,
        int i,
        vector<vector<int>>& allSubsets
    ) {

        // Base case
        if (i == arr.size()) {
            allSubsets.push_back(ans);
            return;
        }

        // Include current element
        ans.push_back(arr[i]);

        returnAllSubsets(
            arr,
            ans,
            i + 1,
            allSubsets
        );

        // Undo the choice
        ans.pop_back();

        // Skip consecutive duplicate values
        int indx = i + 1;

        while (indx < arr.size() &&
               arr[indx] == arr[indx - 1]) {
            indx++;
        }

        // Exclude current element and all its duplicates
        returnAllSubsets(
            arr,
            ans,
            indx,
            allSubsets
        );
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        // Sort so duplicates become adjacent
        sort(nums.begin(), nums.end());

        vector<vector<int>> allSubsets;
        vector<int> ans;

        returnAllSubsets(
            nums,
            ans,
            0,
            allSubsets
        );

        return allSubsets;
    }
};
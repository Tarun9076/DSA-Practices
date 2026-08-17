/*
===========================================================
              50 DAYS OF DSA - DAY 09
              PROBLEM 1: SUBSETS
===========================================================

Problem: 78. Subsets

Problem Statement:
Given an integer array nums containing unique elements,
return all possible subsets (the power set).

The solution must not contain duplicate subsets.

-----------------------------------------------------------
Example 1:

Input:
nums = [1,2,3]

Output:
[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

-----------------------------------------------------------
Example 2:

Input:
nums = [0]

Output:
[[],[0]]

-----------------------------------------------------------
Approach:
Use Recursion / Backtracking.

For every element, there are two choices:

1. Include the current element.
2. Exclude the current element.

The recursion explores both possibilities.

Example:

nums = [1,2]

                    []
                  /    \
               [1]      []
              /   \    /  \
          [1,2]  [1] [2]  []

Every path from the root to a leaf represents one subset.

-----------------------------------------------------------
Backtracking Pattern:

    1. Choose
    2. Explore
    3. Undo the choice
    4. Explore the next possibility

For including an element:

    ans.push_back(arr[i]);

After the recursive call:

    ans.pop_back();

This removes the element so that the exclude branch
can be explored.

-----------------------------------------------------------
Base Case:

When i reaches the end of the array:

    if (i == arr.size())

The current subset is complete, so add it to the
result.

-----------------------------------------------------------
Key Concepts:
- Recursion
- Backtracking
- Decision Tree
- Power Set

-----------------------------------------------------------
Number of Subsets:

For n elements, every element has two choices:

    Include / Exclude

Therefore:

    Total subsets = 2^n

-----------------------------------------------------------
Complexity:

Time Complexity:
O(n * 2^n)

There are 2^n subsets and copying each subset can take
up to O(n) time.

Space Complexity:
O(n) auxiliary recursion space.

The output itself requires O(n * 2^n) space.

-----------------------------------------------------------
Key Learning:

The fundamental backtracking pattern for subsets is:

        Include
           |
        Explore
           |
         Undo
           |
        Exclude
           |
        Explore

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

        // Exclude current element
        returnAllSubsets(
            arr,
            ans,
            i + 1,
            allSubsets
        );
    }

    vector<vector<int>> subsets(vector<int>& nums) {

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
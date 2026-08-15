/*
===========================================================
              50 DAYS OF DSA - DAY 07
===========================================================

Problem: 3Sum

Problem Statement:
Given an integer array nums, return all unique triplets
[nums[i], nums[j], nums[k]] such that:

    nums[i] + nums[j] + nums[k] == 0

The solution must not contain duplicate triplets.

-----------------------------------------------------------
Example 1:

Input:
nums = [-1,0,1,2,-1,-4]

Output:
[[-1,-1,2],[-1,0,1]]

Explanation:
The valid distinct triplets are:

[-1,-1,2]
-1 + (-1) + 2 = 0

[-1,0,1]
-1 + 0 + 1 = 0

-----------------------------------------------------------
Example 2:

Input:
nums = [0,1,1]

Output:
[]

-----------------------------------------------------------
Example 3:

Input:
nums = [0,0,0]

Output:
[[0,0,0]]

-----------------------------------------------------------
Constraints:
- 3 <= nums.length <= 3000
- -10^5 <= nums[i] <= 10^5

-----------------------------------------------------------
Approach:
Use Sorting + Two Pointers.

Step 1: Sort the array.

Example:

    [-1,0,1,2,-1,-4]

becomes:

    [-4,-1,-1,0,1,2]

Sorting allows us to efficiently move the two pointers
and handle duplicate values.

-----------------------------------------------------------
Step 2: Fix One Element

For every index i, consider nums[i] as the first element
of the triplet.

Then use two pointers:

    j = i + 1
    k = n - 1

We need:

    nums[i] + nums[j] + nums[k] == 0

-----------------------------------------------------------
Step 3: Move the Pointers

If:

    sum < 0

The sum is too small, so increase j to get a larger value.

If:

    sum > 0

The sum is too large, so decrease k to get a smaller value.

If:

    sum == 0

A valid triplet is found.

Add it to the answer and move both pointers.

-----------------------------------------------------------
Step 4: Handle Duplicates

To ensure that the answer contains only unique triplets:

1. Skip duplicate values for i.

    if (i > 0 && nums[i] == nums[i - 1])

2. After finding a valid triplet, skip duplicate values
   for both j and k.

This prevents duplicate triplets from being added.

-----------------------------------------------------------
Key Concepts:
- Sorting
- Two Pointers
- Duplicate Handling
- Array Traversal

-----------------------------------------------------------
Complexity:

Time Complexity:
O(n log n) for sorting
+
O(n^2) for the two-pointer traversal

Overall:

O(n^2)

Space Complexity:
O(1) auxiliary space

The output vector is not counted as auxiliary space.

-----------------------------------------------------------
Key Learning:

The main idea is to reduce the 3Sum problem to multiple
2Sum problems.

After fixing nums[i], the remaining problem becomes:

    nums[j] + nums[k] = -nums[i]

Sorting allows the two pointers to efficiently find the
required pair while also making duplicate handling easier.

===========================================================
*/

class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> ans;

        // Sort the array
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {

            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = n - 1;

            // Two-pointer approach
            while (j < k) {

                int sum = nums[i] + nums[j] + nums[k];

                if (sum < 0) {
                    // Need a larger sum
                    j++;
                }
                else if (sum > 0) {
                    // Need a smaller sum
                    k--;
                }
                else {

                    // Found a valid triplet
                    ans.push_back({
                        nums[i],
                        nums[j],
                        nums[k]
                    });

                    j++;
                    k--;

                    // Skip duplicate values for j
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }

                    // Skip duplicate values for k
                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }
            }
        }

        return ans;
    }
};
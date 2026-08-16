/*
===========================================================
              50 DAYS OF DSA - DAY 08
===========================================================

Problem: 4Sum

Problem Statement:
Given an array nums of n integers and an integer target,
return all unique quadruplets:

    [nums[a], nums[b], nums[c], nums[d]]

such that:

    nums[a] + nums[b] + nums[c] + nums[d] == target

The four indices must be distinct, and the result must
not contain duplicate quadruplets.

-----------------------------------------------------------
Example 1:

Input:
nums = [1,0,-1,0,-2,2]
target = 0

Output:
[[-2,-1,1,2],
 [-2,0,0,2],
 [-1,0,0,1]]

-----------------------------------------------------------
Example 2:

Input:
nums = [2,2,2,2,2]
target = 8

Output:
[[2,2,2,2]]

-----------------------------------------------------------
Constraints:
- 1 <= nums.length <= 200
- -10^9 <= nums[i] <= 10^9
- -10^9 <= target <= 10^9

-----------------------------------------------------------
Approach:
Use Sorting + Two Pointers.

The approach is an extension of the 3Sum technique.

Step 1: Sort the array.

Sorting helps us:
- Use the two-pointer technique.
- Move pointers based on the current sum.
- Handle duplicate values easily.

-----------------------------------------------------------
Step 2: Fix the First Element

Use a loop with index i.

    nums[i]

Skip duplicate values of nums[i] to avoid duplicate
quadruplets.

-----------------------------------------------------------
Step 3: Fix the Second Element

Use another loop with index j.

    nums[j]

Now two elements are fixed:

    nums[i] + nums[j]

The remaining problem becomes finding two numbers such that:

    nums[p] + nums[q]
        = target - nums[i] - nums[j]

-----------------------------------------------------------
Step 4: Use Two Pointers

Initialize:

    p = j + 1
    q = n - 1

Calculate:

    sum = nums[i] + nums[j] + nums[p] + nums[q]

If:

    sum < target
        -> move p forward

If:

    sum > target
        -> move q backward

If:

    sum == target
        -> store the quadruplet
        -> move both pointers
        -> skip duplicates

-----------------------------------------------------------
Duplicate Handling:

Skip duplicate values for:

1. i
   if (i > 0 && nums[i] == nums[i - 1])

2. j
   if (j > i + 1 && nums[j] == nums[j - 1])

3. p
   Skip repeated values after finding a valid quadruplet.

4. q
   Skip repeated values after finding a valid quadruplet.

This ensures that the result contains only unique
quadruplets.

-----------------------------------------------------------
Important:
Use long long for calculating the sum.

Since nums[i] can be as large as 10^9, adding four
integers can exceed the range of a 32-bit int.

Therefore:

    long long sum

is used to prevent integer overflow.

-----------------------------------------------------------
Key Concepts:
- Sorting
- Two Pointers
- Nested Loops
- Duplicate Handling
- Integer Overflow
- 2Sum / 3Sum / 4Sum Pattern

-----------------------------------------------------------
Complexity:

Time Complexity:
O(n log n) -> Sorting
O(n^3)      -> Three levels of searching

Overall:

O(n^3)

Space Complexity:
O(1) auxiliary space

The output vector is not counted as auxiliary space.

-----------------------------------------------------------
Key Learning:

4Sum can be solved by extending the same idea used in
3Sum.

The pattern is:

    4Sum
      ↓
    Fix first element
      ↓
    Fix second element
      ↓
    Solve remaining 2Sum using Two Pointers

This demonstrates how complex problems can often be
reduced to simpler known patterns.

===========================================================
*/

class Solution {
public:

    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();
        vector<vector<int>> ans;

        // Sort the array
        sort(nums.begin(), nums.end());

        // Fix the first element
        for (int i = 0; i < n - 3; i++) {

            // Skip duplicates for i
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Fix the second element
            for (int j = i + 1; j < n - 2; j++) {

                // Skip duplicates for j
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                // Two pointers
                int p = j + 1;
                int q = n - 1;

                while (p < q) {

                    // Use long long to prevent integer overflow
                    long long sum = (long long)nums[i]
                                  + nums[j]
                                  + nums[p]
                                  + nums[q];

                    if (sum < target) {
                        p++;
                    }
                    else if (sum > target) {
                        q--;
                    }
                    else {

                        // Found a valid quadruplet
                        ans.push_back({
                            nums[i],
                            nums[j],
                            nums[p],
                            nums[q]
                        });

                        p++;
                        q--;

                        // Skip duplicate values for p
                        while (p < q && nums[p] == nums[p - 1])
                            p++;

                        // Skip duplicate values for q
                        while (p < q && nums[q] == nums[q + 1])
                            q--;
                    }
                }
            }
        }

        return ans;
    }
};
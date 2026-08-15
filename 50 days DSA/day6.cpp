/*
===========================================================
              50 DAYS OF DSA - DAY 06
===========================================================

Problem: Subarray Sum Equals K

Problem Statement:
Given an array of integers nums and an integer k, return
the total number of subarrays whose sum is equal to k.

A subarray is a contiguous and non-empty sequence of
elements within an array.

-----------------------------------------------------------
Example 1:

Input:
nums = [1,1,1]
k = 2

Output:
2

Explanation:
The two subarrays are:

[1,1] -> sum = 2
[1,1] -> sum = 2

-----------------------------------------------------------
Example 2:

Input:
nums = [1,2,3]
k = 3

Output:
2

Explanation:
The two subarrays are:

[1,2] -> sum = 3
[3]    -> sum = 3

-----------------------------------------------------------
Constraints:
- 1 <= nums.length <= 2 * 10^4
- -1000 <= nums[i] <= 1000
- -10^7 <= k <= 10^7

-----------------------------------------------------------
Approach:
Use Prefix Sum + Hash Map.

Let the current prefix sum be:

    prefixSum

Suppose an earlier prefix sum was:

    previousSum

The sum of the subarray between them is:

    prefixSum - previousSum

We want this sum to be k:

    prefixSum - previousSum = k

Therefore:

    previousSum = prefixSum - k

So, for every element:

1. Add the current element to prefixSum.
2. Check whether prefixSum - k exists in the hash map.
3. If it exists, add its frequency to the answer.
4. Store the current prefixSum in the hash map.

-----------------------------------------------------------
Why Do We Initialize:

    m[0] = 1

This represents an empty prefix before the array starts.

For example:

nums = [3]
k = 3

Current prefixSum = 3

We need:

prefixSum - k = 3 - 3 = 0

Since 0 exists in the map initially, we count the
subarray [3].

Therefore, m[0] = 1 automatically handles subarrays
whose sum starts from index 0.

-----------------------------------------------------------
Example:

nums = [1,1,1]
k = 2

Prefix sums:

Index:       0   1   2
nums:        1   1   1
prefixSum:   1   2   3

At prefixSum = 2:

    2 - 2 = 0

0 exists -> count = 1

At prefixSum = 3:

    3 - 2 = 1

1 has appeared once -> count = 2

Answer = 2

-----------------------------------------------------------
Key Concepts:
- Prefix Sum
- Hash Map
- Frequency Counting
- Subarray Problems

-----------------------------------------------------------
Complexity:

Time Complexity  : O(n)

Each element is processed once.

Space Complexity : O(n)

The hash map can store up to O(n) different prefix sums.

-----------------------------------------------------------
Key Learning:

The important observation is that instead of checking every
possible subarray, we can use prefix sums to convert the
problem into finding previously seen prefix sums.

The Hash Map stores the frequency of each prefix sum, allowing
us to count all valid subarrays in O(n) time.

===========================================================
*/

class Solution {
public:

    int subarraySum(vector<int>& nums, int k) {

        int count = 0;
        int prefixSum = 0;

        // Stores the frequency of each prefix sum
        unordered_map<int, int> m;

        // Empty prefix before the array starts
        m[0] = 1;

        for (int num : nums) {

            // Calculate current prefix sum
            prefixSum += num;

            // Check if a previous prefix sum exists
            // such that currentSum - previousSum = k
            int required = prefixSum - k;

            if (m.find(required) != m.end()) {
                count += m[required];
            }

            // Store the current prefix sum
            m[prefixSum]++;
        }

        return count;
    }
};
/*
===========================================================
              50 DAYS OF DSA - DAY 05
===========================================================

Problem: Find the Duplicate Number

Problem Statement:
Given an array nums containing n + 1 integers where each
integer is in the range [1, n].

There is exactly one repeated number. The repeated number
may appear two or more times.

Return the repeated number.

Constraints:
- The array must not be modified.
- Only O(1) extra space can be used.
- Expected time complexity: O(n).

-----------------------------------------------------------
Example 1:

Input:
nums = [1,3,4,2,2]

Output:
2

-----------------------------------------------------------
Example 2:

Input:
nums = [3,1,3,4,2]

Output:
3

-----------------------------------------------------------
Example 3:

Input:
nums = [3,3,3,3,3]

Output:
3

-----------------------------------------------------------
Approach:
Use Floyd's Cycle Detection Algorithm
(Tortoise and Hare Algorithm).

The important observation is that the array can be treated
like a linked list.

For every index i:

    i -> nums[i]

Since every value is in the range [1, n], every value can
be treated as a valid next index.

Because one number is repeated, two different indices point
to the same value. This creates a cycle in the sequence.

Example:

    nums = [1,3,4,2,2]

    0 -> 1 -> 3 -> 2 -> 4
                   ^         |
                   |_________|

The duplicate number is the entry point of the cycle.

-----------------------------------------------------------
Phase 1: Detect the Cycle

Use two pointers:

Slow pointer:
    Moves one step at a time.

Fast pointer:
    Moves two steps at a time.

    slow = nums[slow]
    fast = nums[nums[fast]]

They will eventually meet inside the cycle.

-----------------------------------------------------------
Phase 2: Find the Duplicate

Reset slow to the beginning:

    slow = nums[0]

Then move both pointers one step at a time:

    slow = nums[slow]
    fast = nums[fast]

The point where they meet is the duplicate number.

-----------------------------------------------------------
Why Does a Duplicate Create a Cycle?

There are n + 1 elements but only n possible values
(1 through n).

Therefore, by the Pigeonhole Principle, at least one
value must be repeated.

That repeated value causes multiple positions to point
to the same next node, which creates a cycle.

-----------------------------------------------------------
Key Concepts:
- Floyd's Cycle Detection
- Tortoise and Hare Algorithm
- Fast and Slow Pointers
- Pigeonhole Principle
- Functional Graph

-----------------------------------------------------------
Complexity:

Time Complexity  : O(n)

Space Complexity : O(1)

The array is not modified and no additional data structure
is used.

-----------------------------------------------------------
Key Learning:

The main insight is to recognize that an array can sometimes
be interpreted as a linked list.

By treating nums[i] as the next node, the duplicate number
becomes the entry point of a cycle, allowing Floyd's Cycle
Detection Algorithm to find it using constant extra space.

===========================================================
*/

class Solution {
public:

    int findDuplicate(vector<int>& nums) {

        // Phase 1: Detect the cycle

        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];

        } while (slow != fast);


        // Phase 2: Find the entrance of the cycle

        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
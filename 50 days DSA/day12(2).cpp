 /*
===========================================================
              50 DAYS OF DSA - DAY 13
              PROBLEM: PALINDROME PARTITIONING
===========================================================

Problem:
Given a string s, partition s such that every substring
of the partition is a palindrome.

Return all possible palindrome partitioning of s.

-----------------------------------------------------------
Example 1:

Input:
s = "aab"

Output:
[
    ["a","a","b"],
    ["aa","b"]
]

-----------------------------------------------------------
Example 2:

Input:
s = "a"

Output:
[
    ["a"]
]

-----------------------------------------------------------
Approach:
Use Recursion + Backtracking.

Starting from the beginning of the string, try every
possible prefix as the next partition.

For every possible substring:

    1. Check whether it is a palindrome.
    2. If it is a palindrome, add it to the current
       partition.
    3. Recursively partition the remaining string.
    4. Remove the current substring after recursion
       to explore the next possibility.

-----------------------------------------------------------
Backtracking Pattern:

    Choose substring
          ↓
    Check palindrome
          ↓
       Explore
          ↓
      Undo choice
          ↓
    Try next substring

-----------------------------------------------------------
Example:

s = "aab"

Possible prefixes:

    "a"   -> Palindrome
    "aa"  -> Palindrome
    "aab" -> Not a palindrome

For "a":

    Remaining string = "ab"

For "aa":

    Remaining string = "b"

This produces:

    ["a","a","b"]
    ["aa","b"]

-----------------------------------------------------------
Palindrome Check:

A substring is a palindrome if it reads the same
from both directions.

Use two pointers:

    left  -> beginning
    right -> end

Compare characters while:

    left < right

-----------------------------------------------------------
Base Case:

When the entire string has been partitioned:

    start == s.length()

the current partition is a valid solution.

-----------------------------------------------------------
Key Concepts:
- Backtracking
- Recursion
- String Manipulation
- Palindrome
- Partitioning
- Two Pointers

-----------------------------------------------------------
Complexity:

Time Complexity:
Exponential in the worst case.

There can be O(2^n) possible partitions, and checking
palindromes adds additional work.

Space Complexity:
O(n) auxiliary space for recursion and the current
partition.

The output space is not included.

-----------------------------------------------------------
Key Learning:

This problem demonstrates how backtracking can be used
to generate all valid partitions while applying a
condition to every choice.

The general pattern is:

    Choose -> Validate -> Explore -> Undo

===========================================================
*/

class Solution {
public:

    // Check whether s[left...right] is a palindrome
    bool isPalindrome(const string& s, int left, int right) {

        while (left < right) {

            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }


    void getAllPartitions(
        const string& s,
        int start,
        vector<string>& partitions,
        vector<vector<string>>& ans
    ) {

        // Entire string has been partitioned
        if (start == s.length()) {
            ans.push_back(partitions);
            return;
        }

        // Try every possible substring starting at 'start'
        for (int end = start; end < s.length(); end++) {

            // Only consider palindromic substrings
            if (isPalindrome(s, start, end)) {

                // Choose
                partitions.push_back(
                    s.substr(start, end - start + 1)
                );

                // Explore
                getAllPartitions(
                    s,
                    end + 1,
                    partitions,
                    ans
                );

                // Undo the choice (Backtrack)
                partitions.pop_back();
            }
        }
    }


    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> partitions;

        getAllPartitions(
            s,
            0,
            partitions,
            ans
        );

        return ans;
    }
};
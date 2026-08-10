/*
===========================================================
              50 DAYS OF DSA - DAY 02
===========================================================

Problem: Reverse Words in a String

Problem Statement:
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters.
Words may be separated by multiple spaces.

The returned string should:
- Have the words in reverse order.
- Contain only a single space between words.
- Have no leading or trailing spaces.

-----------------------------------------------------------
Example 1:
Input:
s = "the sky is blue"

Output:
"blue is sky the"

-----------------------------------------------------------
Example 2:
Input:
s = "  hello world  "

Output:
"world hello"

-----------------------------------------------------------
Example 3:
Input:
s = "a good   example"

Output:
"example good a"

-----------------------------------------------------------
Constraints:
- 1 <= s.length <= 10^4
- s contains English letters, digits and spaces.
- There is at least one word in s.

-----------------------------------------------------------
Approach:
This solution uses an in-place approach with O(1) extra space.

Step 1: Remove extra spaces
--------------------------------
Use two pointers:
- i -> reads the original string.
- j -> writes the cleaned string.

While traversing the string:
- Skip leading spaces.
- Copy each word to the front of the string.
- Add only one space between words.
- Remove the final extra space.

After this step:

"  a good   example  "

becomes:

"a good example"

Step 2: Reverse the complete string
------------------------------------
Reverse the entire cleaned string.

"a good example"

becomes:

"elpmaxe doog a"

Step 3: Reverse each individual word
-------------------------------------
Traverse the reversed string and reverse every word
individually.

"elpmaxe doog a"

becomes:

"example good a"

This gives the required result.

-----------------------------------------------------------
Key Concepts:
- Two Pointers
- In-place String Manipulation
- String Reversal
- Space Optimization

-----------------------------------------------------------
Complexity:
Time Complexity  : O(n)
Space Complexity : O(1)

Each character is processed a constant number of times.

-----------------------------------------------------------
Key Learning:
The important idea in this problem is that we can reverse
the words without using an additional array or vector.

The trick is:

1. Remove unnecessary spaces.
2. Reverse the complete string.
3. Reverse every individual word.

This allows the problem to be solved in-place using
constant extra space.

-----------------------------------------------------------
Follow-up:
Since the string is mutable in C++, the problem can be
solved in-place with O(1) extra space.

===========================================================
*/

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = 0, j = 0;

        // Remove extra spaces and shift words to the front
        while (i < n) {

            // Skip spaces
            while (i < n && s[i] == ' ')
                i++;

            // Copy the current word
            while (i < n && s[i] != ' ') {
                s[j++] = s[i++];
            }

            // Add a single space between words
            if (i < n)
                s[j++] = ' ';
        }

        // Remove trailing space
        if (j > 0 && s[j - 1] == ' ')
            j--;

        s.resize(j);

        // Reverse the complete string
        reverse(s.begin(), s.end());

        // Reverse each individual word
        int start = 0;

        for (int i = 0; i <= s.length(); i++) {

            if (i == s.length() || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }

        return s;
    }
};
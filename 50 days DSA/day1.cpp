/*
===========================================================
              50 DAYS OF DSA - DAY 01
===========================================================

Problem: Permutation in String

Problem Statement:
Given two strings s1 and s2, return true if s2 contains
a permutation of s1 as a substring. Otherwise, return false.

In other words, check whether any substring of s2 is an
anagram/permutation of s1.

-----------------------------------------------------------
Example 1:
Input:
s1 = "ab"
s2 = "eidbaooo"

Output:
true

Explanation:
The substring "ba" is a permutation of "ab".

-----------------------------------------------------------
Example 2:
Input:
s1 = "ab"
s2 = "eidboaoo"

Output:
false

-----------------------------------------------------------
Constraints:
- 1 <= s1.length, s2.length <= 10^4
- s1 and s2 consist of lowercase English letters.

-----------------------------------------------------------
Approach:
1. Create a frequency array of size 26 for s1.
2. Traverse s2 using a window of size s1.length().
3. Create a frequency array for the current window.
4. Compare the frequency arrays.
5. If both arrays are equal, the current window is a
   permutation of s1, so return true.
6. If no matching window is found, return false.

-----------------------------------------------------------
Key Concept:
- Frequency Array
- Sliding Window
- String / Anagram Matching

-----------------------------------------------------------
Complexity:
Time Complexity  : O(26 * n) ≈ O(n)
Space Complexity : O(26) ≈ O(1)

-----------------------------------------------------------
Key Learning:
Instead of generating all possible permutations of s1,
we can compare character frequencies to determine whether
a substring of s2 is a permutation of s1.

===========================================================
*/

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isFreqSame(int freq1[],int freq2[]){
        for (int i=0 ; i<26 ; i++){
            if(freq1[i]!=freq2[i]){
                return false ;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int freq1[26]={0};
        for (char ch :s1){
            freq1[ch-'a']++;
        }     

        int windSize  = s1.length();
        for (int i = 0 ;i<s2.length();i++){
            int windIndx=0,Indx=i;
            int freq2[26]={0};
            while (windIndx < windSize && Indx < s2.length()){
                freq2[s2[Indx]-'a']++;
                windIndx++,Indx++;
            }

            if (isFreqSame(freq1,freq2)){
                return true;
            }
        }
        return false;
    }
};
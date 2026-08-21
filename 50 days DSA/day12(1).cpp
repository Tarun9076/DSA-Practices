/*
===========================================================
              DSA - MERGE SORT
===========================================================

Problem:
Given an unsorted array of integers, sort the array in
ascending order using the Merge Sort algorithm.

-----------------------------------------------------------
Example:

Input:
[12, 31, 35, 8, 32, 17]

Output:
[8, 12, 17, 31, 32, 35]

-----------------------------------------------------------
Approach:
Merge Sort uses the Divide and Conquer technique.

The algorithm works in three main steps:

1. Divide:
   Split the array into two halves.

2. Conquer:
   Recursively sort both halves.

3. Merge:
   Merge the two sorted halves into a single sorted array.

-----------------------------------------------------------
Example:

                [12,31,35,8,32,17]
                       /       \
              [12,31,35]     [8,32,17]
               /     \         /     \
            [12,31]  [35]   [8,32]  [17]
             /  \             /  \
           [12] [31]        [8]  [32]

After sorting and merging:

                [8,12,17,31,32,35]

-----------------------------------------------------------
Merge Process:

Two pointers are used:

    i -> Beginning of the left sorted half
    j -> Beginning of the right sorted half

Compare:

    arr[i] <= arr[j]

The smaller element is placed into the temporary array.

After one half is exhausted, copy the remaining elements
from the other half.

Finally, copy the temporary array back into the original
array.

-----------------------------------------------------------
Key Concepts:
- Divide and Conquer
- Recursion
- Sorting
- Two Pointers
- Merging Sorted Arrays

-----------------------------------------------------------
Complexity:

Time Complexity:
O(n log n)

The array is divided into log(n) levels and each level
requires O(n) work to merge.

Space Complexity:
O(n)

A temporary array is used during the merging process.

-----------------------------------------------------------
Important Property:

Merge Sort is a Stable Sorting Algorithm.

If two elements have the same value, their relative order
is preserved because we use:

    arr[i] <= arr[j]

instead of:

    arr[i] < arr[j]

-----------------------------------------------------------
Key Learning:

Merge Sort demonstrates the power of Divide and Conquer:

    Divide
      ↓
    Recursively Sort
      ↓
    Merge

Instead of sorting the entire array at once, we repeatedly
divide it into smaller problems and combine the sorted
results.

===========================================================
*/

#include <iostream>
#include <vector>

using namespace std;


// Merge two sorted portions:
// [start ... mid] and [mid + 1 ... end]
void merge(
    vector<int>& arr,
    int start,
    int mid,
    int end
) {

    vector<int> temp;

    int i = start;
    int j = mid + 1;

    // Compare elements from both sorted halves
    while (i <= mid && j <= end) {

        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Copy remaining elements from the left half
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // Copy remaining elements from the right half
    while (j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy sorted elements back into the original array
    for (int k = 0; k < temp.size(); k++) {
        arr[start + k] = temp[k];
    }
}


// Merge Sort using Divide and Conquer
void mergeSort(
    vector<int>& arr,
    int start,
    int end
) {

    // Base case:
    // A single element is already sorted.
    if (start >= end) {
        return;
    }

    // Find the middle index safely
    int mid = start + (end - start) / 2;

    // Sort the left half
    mergeSort(
        arr,
        start,
        mid
    );

    // Sort the right half
    mergeSort(
        arr,
        mid + 1,
        end
    );

    // Merge the two sorted halves
    merge(
        arr,
        start,
        mid,
        end
    );
}


int main() {

    vector<int> arr = {
        12, 31, 35, 8, 32, 17
    };

    mergeSort(
        arr,
        0,
        arr.size() - 1
    );

    cout << "Sorted Array: ";

    for (int val : arr) {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}
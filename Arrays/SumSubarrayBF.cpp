// This program calculates the maximum sum of a subarray using a brute-force approach.

#include<iostream>
using namespace std;

int main(){
    int a[]={1,2,3,4,5,6,7};
    int Max_Sum=INT_MIN;  //Initailiizing the maximum sum to the minimum integer value to ensure that any sum calculated will be greater than this initial value.
    for (int st = 0;st<(sizeof(a)/sizeof(a[0]));st++){  //Running the loop from starting index to the end of the array
        int currsum=0;               //to store the current sum of the subarray
        for(int end=st;end<(sizeof(a)/sizeof(a[0]));end++){  //running the loop for the subarray starting from the current starting index to the end of the array
            currsum+=a[end];
            Max_Sum=max(Max_Sum,currsum);  //for checking the maximum sun of the subarray and updating the maximum sum if the current sum is greater than the maximum sum
        }
    }
    cout<<"Maximum sum of the subarray is :"<<Max_Sum<<endl;
    return 0;
}

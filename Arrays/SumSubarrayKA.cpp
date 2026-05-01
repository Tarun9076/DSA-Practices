// This program calculates the maximum sum of a subarray using Kadane's algorithm.
#include<iostream>
using namespace std;

int main(){
    int a[]={3,-4,5,4,-1,7,-8};
    int Max_Sum=INT_MIN;
    for (int st = 0;st<(sizeof(a)/sizeof(a[0]));st++){  
        int currsum=0 ;
        currsum =currsum + (a[st]);                   
        Max_Sum=max(Max_Sum,currsum);
        if (currsum < 0){
            currsum = 0;
        }
    }
    cout<<"Maximum sum of the subarray is :"<<Max_Sum<<endl;
    return 0;
}
#include<iostream>
using namespace std;
int main()
{
    int a[]={1,4,5,6,8,3,4,5};
    int start=0 ; // Initialize start index
    int end=sizeof(a)/sizeof(a[0])-1; // Calculate the end index based on the size of the array
    cout << sizeof(a) << " "; 
    cout << sizeof(a[0]) << " ";
    while (start<end){
        swap(a[start],a[end]);
        start++;
        end--;
    }
    for (int i =0;i<sizeof(a)/sizeof(a[0]);i++){
        cout << a[i] << " "; 
    }
    return 0;
}
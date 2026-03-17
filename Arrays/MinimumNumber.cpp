//Prograsm to find the minimum number among three numbers
#include<iostream>
using namespace std;
int main()
{
    int  a[] = {10,9,2,4,1,5,6,7,8,3};
    int b=sizeof(a)/sizeof(a[0]); // Calculate the number of elements in the array
    int minimum=INT_MAX; // Initialize minimum to the largest possible integer value
    for (int i = 0; i<b; i++){
        if(a[i]<minimum){
            minimum=a[i]; // Update minimum if a smaller value is found
        }
    }
    cout << "The minimum number is: " << minimum << endl;

}
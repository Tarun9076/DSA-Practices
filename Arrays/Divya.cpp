#include<iostream>
using namespace std;
int main(){
    int n=6;
    int arr[5]={4,7,6,2,3};
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if (arr[j]== arr[j+1]){
                int temp=arr[j+1];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

            }

        }
    }
    cout<<"Sorted array : "<<arr;
}

#include<iostream>
#include<vector>
using namespace std;

int binarysearch(vector<int> arr,int target){
    int st=0;
    int end=arr.size()-1;
    while (st<=end){
        int mid = st+(end-st)/2;
        if (target==arr[mid]){
            return mid;
        }
        else if (target>arr[mid]){
            st=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr ={1,2,3,4,5,9};
    int target =9;
    int result = binarysearch(arr,target);
    if (result==-1){
        cout<<"element not found"<<endl;
    }
    else{
        cout<<"element found at index: "<<result<<endl;
    }
}


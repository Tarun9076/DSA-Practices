#include<iostream>
#include<vector>
using namespace std;

int binarysearch(int st , int end, vector<int> arr , int target){
    if (st>end){
        return -1;
    }
    int mid = st+(end-st)/2;
    if (target==arr[mid]){
        return mid;
    }
    else if (target>arr[mid]){
        return binarysearch(mid+1,end,arr,target);
    }
    else{
        return binarysearch(st,mid-1,arr,target);
    }
    
}

int main(){
    vector<int> arr ={1,2,3,4,5,9};
    int target =9;
    int result = binarysearch(0,arr.size()-1,arr,target);
    if (result==-1){
        cout<<"element not found"<<endl;
    }
    else{
        cout<<"element found at index: "<<result<<endl;
    }
}

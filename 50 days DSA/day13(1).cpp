#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int st, int end){
    int indec=st-1, pivot=arr[end];
    for(int i=st; i<end; i++){
        if(arr[i]<pivot){
            indec++;
            swap(arr[indec], arr[i]);
        }
    }
    indec++;
    swap(arr[indec], arr[end]);
    return indec;
}

void quickSort(vector<int>& arr, int st, int end){
    if(st<end){
        int pivIndex=partition(arr, st, end);
        quickSort(arr,st, pivIndex-1);
        quickSort(arr, pivIndex+1, end);
    }
}

    

int main() {

    vector<int> arr = {5,2,6,4,1,3};

    quickSort(arr, 0, arr.size()-1);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }

    return 0 ;
}
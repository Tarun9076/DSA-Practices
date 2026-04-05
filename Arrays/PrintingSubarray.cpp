#include<iostream>
using namespace std;
int main(){
    int a[]={1,2,3,4,5,};
    int size=sizeof(a)/sizeof(a[0]);
    for (int st=0;st<size;st++){
        for(int end=st;end<size;end++){
            for(int i=st;i<=end;i++){
                cout<<a[i];
            } 
            cout<<" ";  
        }
        cout<<endl;
    }
    
}
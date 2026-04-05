#include<iostream>
using namespace std;
int main(){
    int a[]={1,2,3,4,5,6,7};
    int prd=0;
    for (int i = 0;i<(sizeof(a)/sizeof(a[0]));i++){
        prd*=a[i]; 
    }
    cout<<"product of the array element is :"<<prd<<endl;
    return 0;
}

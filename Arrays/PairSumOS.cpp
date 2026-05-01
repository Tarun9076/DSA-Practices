#include<iostreAM>
#include<vector>
using namespace std;

int main(){
    int a[]={2,7,11,15};
    int target = 9;
    int i=0;
    int j=(sizeof(a)/sizeof(a[0]))-1;
    while(i<j){
        int ps = a[i]+a[j];
        if(ps==target){
            cout <<"Pair found at index : "<<i<<" and "<<j<<endl;
            break;
        }
        else if(ps<target){
            i++;
        }
        else{
            j--;
        }
    }
    
}
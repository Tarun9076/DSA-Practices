#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums ={2,2,1,1,2,2,9,9,9,9,9};
    int freq = 0 , ans = 0;
    for (int val : nums){
        if (freq == 0){
            ans = val;
        }else if (ans == val){
            freq ++;
        }else {
            freq--;
        }
        
    }
    cout<<"The majority element id : "<<ans<<endl;
}


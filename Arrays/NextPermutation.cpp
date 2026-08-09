//code to find the next permutation of a given array of integers

class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int piv = -1 , n  =a.size();
        // To find Pivot
        for(int i = n-2 ; i>=0; i--){
            if (a[i]<a[i+1]){
                piv = i;
            break;
            }
        }
        //if next permutation is not  possible then arranging the array in lowest possible order
        if (piv == - 1){
            int i = 0 , j = n-1 ;
            while (i<j){
                swap(a[i++],a[j--]);
                
            }
            return;
        }  
        // To Find right most greater element than pivot element
        for (int i = n-1 ; i > piv ; i--){
            if (a[i]>a[piv]){
                swap(a[i],a[piv]);
                break;
            }
        } 
        //To reverse the remaining array 
        int i = piv + 1 ;
        int j = n-1;
        while (i<=j){
            swap(a[i++],a[j--]);

        } 
    }
};
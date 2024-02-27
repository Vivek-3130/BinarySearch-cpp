#include<bits/stdc++.h>
using namespace std;

//Brute will be O(N), as we will compare each and every number one by one

//Here we will be shrinking the search space and choose the lowest among the roated and sorted part
//TC:- O(logn)
int findMinimumInRotated(int arr[] , int n){
    int ans = INT_MAX;
    int low = 0;
    int high = n -1;
    int mid;

    while(low <= high){
        mid = (low + high)/2;

        // If the search space is already sorted
        // then always arr[low] will be the smallest value in taht search space

        if(arr[low] <= arr[high]){
            ans = min(ans,arr[low]);
            break;
        }

        if(arr[low] <= arr[mid]){
            ans = min(ans, arr[low]);
            low = mid + 1; //as we have to iterate further also, in the next half
        }
        else{
            high = mid -1;
            ans = min (ans , arr[mid]);
        }
    }
    return ans;
}

int main(){
    int arr[]={4,5,6,7,0,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int index = findMinimumInRotated(arr, n); //for iterative
    cout<<"The minimum value in the rotated array is "<<index;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int numberOfRotation(int arr[] , int n){
    int low = 0;
    int high = n -1;
    int ans = INT_MAX;
    int mid;
    int index = -1;
    while(low <= high){
        mid = (low + high)/2;

        // If the search space is already sorted
        // then always arr[low] will be the smallest value in that search space

        if(arr[low] <= arr[high]){
            if(arr[low] < ans){
                index = low;
                ans = arr[low];
            }
            break;
        }

        if(arr[low] <= arr[mid]){
            if(arr[low] < ans){
                index = low;
                ans = arr[low];
            }
            low = mid + 1; //as we have to iterate further also, in the next half
        }
        else{
            high = mid -1;
            if(arr[mid] < ans){
                index = mid;
                ans = arr[mid];
            }
        }
    }
    return index;

}

int main(){
    int arr[]={4,5,6,7,0,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int index = numberOfRotation(arr, n); //for iterative
    cout<<"The number of rotation in the given array is: "<<index;
    return 0;
}

// As here where ever is the lowest element is present ,that index
//is the number of rotation.
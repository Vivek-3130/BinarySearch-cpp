#include<iostream>
using namespace std;

//Brute Force: O(N)
// int peakElement(int nums[], int n){
//     if (n == 1) return 0; // Only one element, it's a peak by definition

//     for (int i = 0; i < n; i++) {
//         if (i == 0) {
//             if (nums[i] > nums[i + 1]) return nums[i]; // Return the peak value instead of index
//         } else if (i == n - 1) {
//             if (nums[i] > nums[i - 1]) return nums[i]; // Return the peak value instead of index
//         } else {
//             if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) return nums[i]; // Return the peak value instead of index
//         }
//     }
//     return -1; // No peak found
// }

//Optimised:O(logn)
int peakElement(int nums[] , int n){

    if (n == 1) return 0;

    if(nums[0] > nums[1]) return 0;

    if(nums[n-1] > nums[n-2]) return n-1;

    int low = 1, high = n-2;
    int mid;
    while(low <= high){
        mid =(high + low) / 2;

        if(nums[mid] > nums[mid - 1] &&  nums[mid] > nums[mid + 1]) return mid;

        else if(nums[mid] > nums[mid - 1]) low = mid + 1; //elimination of right half

        else high = mid - 1; //elimination of left half

    } 
    return -1; //as return type is integer we have to return something
}

int main(){
    int arr[]={1,5,1,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    int peakEle= peakElement(arr,n);

    if(peakEle != -1){
        cout<<"The no of peak value is: "<<peakEle;
    }
    else{
        cout<<"There is no peak element";
    }
    return 0;
}

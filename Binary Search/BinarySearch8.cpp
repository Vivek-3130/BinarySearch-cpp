#include<bits/stdc++.h>
using namespace std;
//Duplicate Numbers
//Brute will be linear search we i will compare each and every number with the key value and the then return the index.
//Time Complexity will be O(N)

//Here we will be shrinking the search space as in duplicate low,mid and high may occur same
//TC:- O(logn)
bool searchInRotatedArrayWithDuplicates(int arr[] , int n , int x){
    int low = 0, high = n -1;
    int  mid;
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid] == x) return true;

        //If arr[low]==arr[mid]==arr[high] then shrink the search space
        if(arr[low]==arr[mid] && arr[mid]==arr[high]){
            low= low + 1;
            high = high - 1;
            continue;
            //might possible next is also the same

        }

        // left sorted check
        if(arr[low] <= arr[mid]){
            if(arr[low] <= x && x <= arr[mid]){
                //eliminate the right half
                high = mid -1;
            }
            else
               low = mid + 1;
        }
        //right is sorted
        else{
            if(arr[mid] <= x && x <= arr[high]){
                //eliminate the left half
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return false;
    
}

int main(){
    int arr[]={3,1,2,3,3,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    int key;
    cin>>key;
    
    int index = searchInRotatedArrayWithDuplicates(arr, n, key); //for iterative
    cout<<"The Value Is Present Or Not: "<<index;
    return 0;
}
// BinarySearch1
#include<bits/stdc++.h>
using namespace std;

//Iteratve SOlution using while loop: - 2^8 times it will be divided and there for O(log2n), as we are dividing it 8 tyms
// int binarySearch(int arr[], int n , int key){
//     sort(arr, arr + n);
//     int low = 0;
//     int high = n-1;
//     int mid;
//     while(low <= high){
//         mid = low + (high - low)/2;
//         if(arr[mid] == key){
//             return mid;
//         }
//         if(arr[mid] > key){
//             high = mid -1;
//         }
//         else{
//             low = mid + 1;
//         }
//     }
//     return -1; //if the element is not found
// }

// Recursive approach
int binarySearch(int arr[], int low, int high, int key){
    
    if(low > high){  //Base case
        return -1;
    }
    int mid = low + (high - low)/2;

    if(arr[mid] == key){
        return mid;
    }

    else if(key > arr[mid])
    {
        return binarySearch(arr,mid+1,high,key);
    }
    else
    {
        return binarySearch(arr,low,mid-1,key);
    }


}

int main(){
    int arr[]={1,2,3,5,8,9,56,75,411,485};
    int n = sizeof(arr)/sizeof(arr[0]);

    int key;
    cin>>key;
    
    // int index = binarySearch(arr, n, key); //for iterative
    int index = binarySearch(arr,0, n-1, key); //for recursive
    if (index != -1) {
        cout << "The element is found at index: " << index;
    } else {
        cout << "The element is not found";
    }
    return 0;
}
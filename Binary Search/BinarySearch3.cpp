#include<bits/stdc++.h>
using namespace std;


//STL Upper Bound => upper_bound(arr.begin(),arr.end(),n);
//Normal array ==> upper_bound(arr,arr+n) or lower_bound(arr + i, arr + j);
//This will return an iterator pointing to that index, then subtract the iterator and lowerbound we will be getting the index
//TC => O(log2n)

int upperBound(int arr[],int n, int ub){
    int low = 0,high = n-1;
    int ans = n; //if not found then this is the hypothetical value which we got
    int mid;
    while(low <= high){
        mid = (low + high)/2;
        if(arr[mid] > ub){
            ans = mid;
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    int arr[]={2,3,6,7,8,8,11,11,11,12};
    int n = sizeof(arr)/sizeof(arr[0]);

    int key;
    cin>>key;
    
    int index = upperBound(arr, n, key); //for iterative
    if (index < n) {
        cout << "The upper bound element is found at index: " << index;
    } else {
        cout << "The element is found at: "<<n;
    }
    return 0;
}
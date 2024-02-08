#include<bits/stdc++.h>
using namespace std;


//STL Lower Bound => lower_bound(arr.begin(),arr.end(),n);
//Normal array ==> lower_bound(arr,arr+n) or lower_bound(arr + i, arr + j);
//This will return an iterator pointing to that index, then subtract the iterator and lowerbound we will be getting the index
//TC => O(log2n)

int lowestBound(int arr[],int n, int lb){
    int low = 0,high = n-1;
    int ans = n; //if not found then this is the hypothetical value which we got
    int mid;
    while(low<=high){
        mid = (low+high)/2;

        if(arr[mid] >= lb){
            ans = mid;
            high = mid -1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

int main(){
    int arr[]={1,2,3,3,7,8,9,9,9,11};
    int n = sizeof(arr)/sizeof(arr[0]);

    int key;
    cin>>key;
    
    int index = lowestBound(arr, n, key); //for iterative
    if (index != -1) {
        cout << "The lowest bound element is found at index: " << index;
    } else {
        cout << "The element is found at: "<<n;
    }
    return 0;
}
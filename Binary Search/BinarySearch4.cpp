#include<bits/stdc++.h>
using namespace std;

int searchPositionandInsertion(int arr[],int n, int m){
    int low = 0,high = n-1;
    int ans = n; 
    int mid;
    while(low <= high){
        mid = (low + high)/2;
        
    }
    return ans;
}

int main(){
    int arr[]={1,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    int key;
    cin>>key;
    
    int index = searchPositionandInsertion(arr, n, key); //for iterative
    if (index < n) {
        cout << "The element is found at index: " << index;
    } else {
        cout << "The element is going to be inserted at index : "<<n;
    }
    return 0;
}
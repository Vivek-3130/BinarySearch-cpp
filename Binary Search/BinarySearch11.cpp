#include <iostream>
using namespace std;

//Brute Force:- O(N)
// int singleElementInSortedArray(int arr[], int n) {
//     if (n == 1) {
//         return arr[0];
//     }

//     // Handle edge cases efficiently using XOR:
//     if (arr[0] != arr[1]) {
//         return arr[0];
//     }

//     for (int i = 1; i < n - 1; i++) {
//         if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1]) {
//             return arr[i];
//         }
//     }

//     // Last element case if not handled in the loop:
//     if (arr[n - 2] != arr[n - 1]) {
//         return arr[n - 1];
//     }

//     return -1; // Handle the case where no single element exists (all elements are duplicates)
// }

//Optimized:O(log2n) ,as we are eleminating left and right half apart not just a single half
int singleElementInSortedArray(int arr[], int n){
    if (n == 1) {
        return arr[0];
    }
// Handle first element if not handles in loop:
    if(arr[0]!= arr[1]) return arr[0];
// Last element case if not handled in the loop:
    if (arr[n - 2] != arr[n - 1]) return arr[n - 1];

    int start = 1, end = n - 2;

//Applying Binary Search
    while(start <= end){
                int mid = (start + end)/2;
                
                //As both element on the left and right are different
                if(arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) return arr[mid];
    
                //eleminate left half
                //Uisng even and odd indexing to elemimate the left or right half
                if((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1])){
                    start = mid + 1;
                }
                else{
                    end = mid - 1;    //eleminated the right half
                }
            }
        return -1;
}

int main() {
    int arr[] = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int number = singleElementInSortedArray(arr, n);

    if (number != -1) {
        cout << "The Number Occuring Once is: " << number << endl;
    } else {
        cout << "No single element exists in the array (all elements are duplicates)." << endl;
    }

    return 0;
}

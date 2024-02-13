#include <iostream>
#include <vector>
using namespace std;


int numberFloorAndCeil(int arr[], int n, int m, bool findCeil) {
    int low = 0, high = n - 1;
    int ans = n; 
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == m) {
            ans = mid;
            return ans; // If element is found, return its index
        }
        else if (arr[mid] < m) {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return findCeil ? ans : ans - 1; // If finding ceil, return ans; if finding floor, return ans - 1
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int key;
    cin >> key;
    
    int floorIndex = numberFloorAndCeil(arr, n, key, false);
    int ceilIndex = numberFloorAndCeil(arr, n, key, true);
    
    if (floorIndex < n) {
        cout << "Floor of " << key << " is found at index: " << floorIndex << endl;
    } else {
        cout << "Floor of " << key << " is going to be inserted at index : " << n << endl;
    }
    
    if (ceilIndex < n) {
        cout << "Ceiling of " << key << " is found at index: " << ceilIndex << endl;
    } else {
        cout << "Ceiling of " << key << " is going to be inserted at index : " << n << endl;
    }
    
    return 0;
}



// pair<int, int> findFloorCeiling(vector<int>& a, int n, int x) {
//     int floor = -1, ceiling = -1;
//     int low = 0, high = n - 1;

//     // Finding floor
//     while (low <= high) {
//         int mid = low + (high - low) / 2;
//         if (a[mid] == x) {
//             floor = a[mid];
//             break;
//         } else if (a[mid] < x) {
//             floor = a[mid];
//             low = mid + 1;
//         } else {
//             high = mid - 1;
//         }
//     }

//     // Finding ceiling
//     low = 0;
//     high = n - 1;
//     while (low <= high) {
//         int mid = low + (high - low) / 2;
//         if (a[mid] == x) {
//             ceiling = a[mid];
//             break;
//         } else if (a[mid] < x) {
//             low = mid + 1;
//         } else {
//             ceiling = a[mid];
//             high = mid - 1;
//         }
//     }

//     return {floor, ceiling};
// }

// int main() {
//     int n = 6, x = 5;
//     vector<int> a = {3, 4, 7, 8, 8, 10};
    
//     pair<int, int> result = findFloorCeiling(a, n, x);
//     cout << "Floor of " << x << ": " << result.first << endl;
//     cout << "Ceiling of " << x << ": " << result.second << endl;

//     return 0;
// }

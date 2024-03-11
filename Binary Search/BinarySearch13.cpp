#include<iostream>
#include <cmath>
using namespace std;
// Brute Force : O(n)
// int sqrtSearch(int n){
//     if (n < 0)
//         return -1; // Square root is not defined for negative numbers
//     if (n == 0)
//         return 0;
//     for(int i = 1; i <= n; i++){
//         if (i * i == n)
//             return i;
//         if (i * i > n)
//             return floor(sqrt(n));
//     }
//     return -1;
// }

// Optimised Method:O(logn)
int sqrtSearch(int n){
    if (n < 0)
        return -1; // Square root is not defined for negative numbers
    if (n == 0)
        return 0;

    int low = 1 , high = n;
    int ans = 1;
    int mid;
    while(low <= high){
        mid = ( low + high) / 2;
        if(mid * mid <= n){
            ans = mid;
            low = mid + 1;
        }
        else high = mid -1;
    }
    return ans;  // we can also return high
}


int main() {
    int number = 99;
    int result = sqrtSearch(number);
    if (result != -1)
        cout << "Square root of " << number << " is: " << result << endl;
    else
        cout << "Square root not found within the range" <<endl;
    return 0;
}
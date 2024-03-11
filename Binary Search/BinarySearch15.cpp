#include <iostream>
#include <vector>
#include<cmath>
#include <algorithm>
using namespace std;

//Brute Force : O(N log M):-N is the number of piles and M is the maximum size of a pile.
// Function to calculate the number of hours needed for Koko to eat bananas
// int kokoEatingSpeed(vector<int>& piles, int H) {
//     int maxSpeed = *max_element(piles.begin(), piles.end());
//     int minHours = INT_MAX;

//     for (int speed = 1; speed <= maxSpeed; speed++) {
//         int hours = 0;
//         for (int pile : piles)
//             hours += (pile + speed - 1) / speed;
//         if (hours <= H)
//             minHours = min(minHours, hours);
//     }

//     return minHours;
// }
 
// Optimised Method:O(N * log M), where N is the number of piles and M is the maximum size of a pile.
// int calculateTotalHours(vector<int> &v, int hourly){
//     int totalH=0;
//     int n = v.size();
//     for(int i =0 ;i<n;i++){
//         totalH += ceil((double)v[i]/(double)hourly);
//     }
//     return totalH;
// }

// int kokoEatingSpeed(vector<int>& arr, int h){
//     int low = 1, high = *max_element(arr.begin(), arr.end());
//     int ans = INT_MAX;
//     int mid;
//     while(low<=high){
//         mid = (low+high)/2;
//         int totalH=calculateTotalHours(arr,mid);
//         if(totalH <= h){
//             high = mid -1;
//         }
//         else{
//             low = mid + 1;
//         }
//     }
//     return low;
// }

// -------------------------OR----------------------------
int kokoEatingSpeed(vector<int>& piles, int H) {
    int left = 1;
    int right = *max_element(piles.begin(), piles.end()) + 1; // upper bound is exclusive
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        int hours = 0;
        for (int pile : piles)
            hours += (pile + mid - 1) / mid;
            // hours += ceil(static_cast<double>(pile) / mid);
        if (hours <= H)
            right = mid;
        else
            left = mid + 1;
    }
    
    return left;
}


int main() {
    //TO apply bs on answers we should know the range
    // Example usage
    //The max would be the biggest element the highest range
    vector<int> piles = {3, 6, 7, 11};
    int H = 8;
    cout << "Koko needs to eat at least " << kokoEatingSpeed(piles, H) << " bananas per hour." << endl;
    return 0;
}

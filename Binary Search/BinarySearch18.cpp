#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sumOfWeight(vector<int> &weight) {
    int sum = 0;
    int n = weight.size();
    for(int i = 0; i < n; i++) {
        sum = sum + weight[i];
    }
    return sum;
}

int noOfDays(vector<int> &weight, int cap) {
    int days = 1;
    int currentCap = 0;
    for(int i = 0; i < weight.size(); i++) {
        if(currentCap + weight[i] <= cap) {
            currentCap += weight[i];
        } else {       //jese hi capacity se upr jaye turant second day shift krdo
            days++;
            currentCap = weight[i];
        }
    }
    return days;
}

// Brute Foce: O(N^2)
int leastWeightCapacity(vector<int>& weight, int days) {
    int totalWeight = sumOfWeight(weight);
    int leastWeight = totalWeight; // Initialize leastWeight to totalWeight
    
    for (int cap = 1; cap <= totalWeight; cap++) {
        int requiredDays = noOfDays(weight, cap);
        if (requiredDays <= days) {
            leastWeight = min(leastWeight, cap); // Update leastWeight if a better solution is found
        }
    }
     
    return leastWeight;
}
  
// Optimised Soln: log2(sum - max + 1)*O(N)
// int leastWeightCapacity(vector<int>& weight, int days){
//     int low = *max_element(weight.begin(),weight.end());
//     int high = sumOfWeight(weight);
//     int mid;
//     while(low < high){
//         mid = (low + high)/2;
//         int requiredDays=noOfDays(weight,mid);
//         if(requiredDays<=days){
//             high = mid - 1;
//         }
//         else{
//             low = mid + 1;
//         }
//     }
//     return low;
// }

int main() {
    vector<int> weight = {1,2,3,4,5,6,7,8,9,10};
    int days = 5; // Change the number of days here
  
    int leastWeight = leastWeightCapacity(weight, days);

    cout << "Least weight required per day is " << leastWeight;

    return 0;
}

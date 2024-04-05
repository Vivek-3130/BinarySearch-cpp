#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int possible(vector<int> &arr, int day, int m, int k) {
  int cnt = 0;
  int noOfBouquets = 0;

  for (int i = 0; i < arr.size(); i++) { // Iterate through all elements (including last)
    if (arr[i] <= day) cnt++;
    else {
      noOfBouquets += (cnt / k); // Add bouquets formed till now
      cnt = 0; // Reset count for next consecutive flowers
    }
  }

  // Add bouquets formed from the last consecutive flowers (if any)
  noOfBouquets += (cnt / k);

  if (noOfBouquets >= m) return 1;
  return 0; // Indicate failure if not enough bouquets
}

// Brute force: O((high - low +1)*N);
// int minimumBouquets(vector<int> &arr, int m, int k) {
//   int n = arr.size();
//   int low = *min_element(arr.begin(), arr.end());
//   int high = *max_element(arr.begin(), arr.end());

//   // If no of flowers are insufficient
//   if (m * k > n) return -1;

//   for (int i = low; i < high; i++) {
//     if (possible(arr, i, m, k) == 1) return i;
//   }
//   return -1; // Indicate no day found if loop completes
// }


//Optimised Solution :  (O(log N))
int minimumBouquets(vector<int> &arr, int m, int k){
    int n = arr.size();

    if (m * k > n) return -1;

    int low = *min_element(arr.begin(), arr.end());
    int high = *max_element(arr.begin(), arr.end());
    int ans = high;
    int mid; 
    while(low<=high){
        mid = (low+high)/2;
        if(possible(arr,mid,m,k) == 1){
            ans = mid;
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;   //or ans
     
}

int main() {
  // Example usage
  vector<int> bloomDays = {7, 7, 7, 7, 13, 11, 12, 7};
  int m = 2;
  int k = 3;
  
  int minDay = minimumBouquets(bloomDays, m, k);

  if (minDay == -1) {
    cout << "No feasible day found to prepare " << m << " bouquets with " << k << " flowers each." << endl;
  } else {
    cout << "Bouquets need to be prepared in " << minDay << " days." << endl;
  }

  return 0;
}

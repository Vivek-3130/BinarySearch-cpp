#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// int maxMinDistanceBruteForce(vector<int>& stalls, int cows) {
//     int n = stalls.size();
//     int maxMinDistance = 0;

//     // Try all possible combinations of placing cows
//     for (int i = 0; i < cows; ++i) {
//         int minDistance = INT_MAX;
//         for (int j = i + 1; j < n; ++j) {
//             minDistance = min(minDistance, stalls[j] - stalls[i]);
//         }
//         maxMinDistance = max(maxMinDistance, minDistance);
//     }

//     return maxMinDistance;
// }

// int main() {
//     vector<int> stalls = {0, 3, 4, 7, 10, 9};
//     int cows = 4;

//     int result = maxMinDistanceBruteForce(stalls, cows);
//     cout << "Maximum minimum distance with brute force: " << result << endl;

//     return 0;
// }


bool canPlaceCows(vector<int>& stalls, int cows, int minDistance) {
    int count = 1;
    int lastPlaced = stalls[0];

    for (int i = 1; i < stalls.size(); ++i) {
        if (stalls[i] - lastPlaced >= minDistance) {
            count++;
            lastPlaced = stalls[i];
            if (count == cows)
                return true;
        }
    }

    return false;
}

int maxMinDistanceOptimized(vector<int>& stalls, int cows) {
    sort(stalls.begin(), stalls.end());

    int low = 1;
    int high = stalls.back() - stalls.front();
    int maxMinDistance = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPlaceCows(stalls, cows, mid)) {
            maxMinDistance = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return maxMinDistance;
}

int main() {
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int cows = 4;

    int result = maxMinDistanceOptimized(stalls, cows);
    cout << "Maximum possible minimum distance with optimized solution: " << result << endl;

    return 0;
}

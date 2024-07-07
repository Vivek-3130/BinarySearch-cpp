#include <iostream>
#include <vector>
#include <algorithm> // for lower_bound
using namespace std;

// Brute force: O(rows * cols)
// int rowWithMaxOnes(vector<vector<int>>& matrix){
//     int maxRowIndex = -1;
//     int maxCount = 0;
//     int rows = matrix.size();
//     int cols = matrix[0].size();

//     for (int i = 0; i < rows; i++) {
//         int count = 0;
//         for (int j = 0; j < cols; j++) {
//             if (matrix[i][j] == 1) {
//                 count++;
//             }
//         }
//         if (count > maxCount) {
//             maxCount = count;  //new max count assigned
//             maxRowIndex = i;  // index with max ones
//         }
//     }

//     return maxRowIndex;
// }

// Optimised Solution:  O(rows * log(cols)), used lower bound to find the first occurrence of 1 in a single row
int rowWithMaxOnes(vector<vector<int>> &matrix){
    int maxRowIndex = -1;
    int maxCount = 0;
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
        // Use lower_bound to find the first 1 in the row
        auto it = lower_bound(matrix[i].begin(), matrix[i].end(), 1);
        int count = distance(it, matrix[i].end());
        // Calculate the count of 1s in the current row as the distance from the iterator to the end of the row.
        // lower bound aayega 0 pr and uska distance to the end ofrow is 4-0=4

        if (count > maxCount) {   //4>3
            maxCount = count;   //4
            maxRowIndex = i;   //2
        }
    }

    return maxRowIndex;
}
int main() {
    vector<vector<int>> matrix = {
        {0, 0, 0, 1},
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };

    int result = rowWithMaxOnes(matrix);

    if (result != -1) {
        cout << "Row with maximum number of 1s is: " << result << endl;
    } else {
        cout << "No 1s found in the matrix." << endl;
    }

    return 0;
}
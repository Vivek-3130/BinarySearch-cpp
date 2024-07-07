#include <iostream>
#include <vector>
using namespace std;

// Brute Force :- O(n*m)
// pair<int, int> searchIn2DMatrix(vector<vector<int>> &matrix, int k){
//     int rows = matrix.size();
//     int cols = matrix[0].size();
//     for (int i = 0; i < rows; i++) {
//     for (int j = 0; j < cols; j++) {
//       if (matrix[i][j] == k) { 
//         return make_pair(i, j); // Return pair of indices
//       }
//     }
//   }

//   return make_pair(-1, -1); // Target not found, return default pair

// }

// Better Solution:- O(log n * m)
pair<int, int> searchIn2DMatrix(vector<vector<int>> &matrix, int k) {
  int rows = matrix.size();
  int cols = matrix[0].size();
  int i = 0, j = cols - 1;

  while (i < rows && j >= 0) {
    if (matrix[i][j] == k) {
      return make_pair(i, j);
    } else if (matrix[i][j] < k) {
      i++; // Move down the column
    } else {
      j--; // Move left in the row
    }
  }

  return make_pair(-1, -1); // Target not found
}

int main() {
    vector<vector<int>> matrix = {
        {3, 4, 7, 9},
        {12, 13, 16, 18},
        {20, 21, 23, 29}
    };
    int k = 29;
    pair<int, int> indices = searchIn2DMatrix(matrix,k);

    if (indices.first != -1) {
        cout <<"Target found at: (" << indices.first << ", " << indices.second << ")" << endl;
    } else {
        cout << "Target not found in the matrix." << endl;
    }

    return 0;
}
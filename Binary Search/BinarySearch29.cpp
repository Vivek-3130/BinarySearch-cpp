#include <iostream>
#include <vector>
using namespace std;

// Brute force: O(n*m)
// pair<int, int> findPeak(vector<vector<int>> &matrix)
// {
//     int n = matrix.size();
//     int m = matrix[0].size();
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             bool isPeak = true;
//             if (i > 0 && matrix[i][j] <= matrix[i - 1][j])
//                 isPeak = false;
//             if (i < n - 1 && matrix[i][j] <= matrix[i + 1][j])
//                 isPeak = false;
//             if (j > 0 && matrix[i][j] <= matrix[i][j - 1])
//                 isPeak = false;
//             if (j < m - 1 && matrix[i][j] <= matrix[i][j + 1])
//                 isPeak = false;
//             if (isPeak)
//                 return make_pair(i, j);
//         }
//     }
//     return make_pair(-1, -1);
// }

// Optimised solution:O(nlogm)
// Function to find the maximum element in a column
int findMaxInColumn(const vector<vector<int>> &matrix, int col, int &maxRow) {
    int numRows = matrix.size();
    int maxValue = matrix[0][col];
    maxRow = 0;
    for (int i = 1; i < numRows; i++) {
        if (matrix[i][col] > maxValue) {
            maxValue = matrix[i][col];
            maxRow = i;
        }
    }
    return maxValue;
}

// Recursive function to find the peak element
pair<int, int> findPeakUtil(const vector<vector<int>> &matrix, int startCol, int endCol) {
    int midCol = startCol + (endCol - startCol) / 2;
    int maxRow;
    int maxValue = findMaxInColumn(matrix, midCol, maxRow);

    // Check if the middle column max is a peak element
    bool leftIsSmaller = (midCol == 0 || matrix[maxRow][midCol] >= matrix[maxRow][midCol - 1]);
    bool rightIsSmaller = (midCol == matrix[0].size() - 1 || matrix[maxRow][midCol] >= matrix[maxRow][midCol + 1]);

    if (leftIsSmaller && rightIsSmaller) {
        return make_pair(maxRow, midCol);
    } else if (midCol > 0 && matrix[maxRow][midCol - 1] > matrix[maxRow][midCol]) {
        return findPeakUtil(matrix, startCol, midCol - 1);
    } else {
        return findPeakUtil(matrix, midCol + 1, endCol);
    }
}

pair<int, int> findPeak(const vector<vector<int>> &matrix) {
    return findPeakUtil(matrix, 0, matrix[0].size() - 1);
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 5, 1, 4, 5},
        {2, 9, 3, 2, 3, 2},
        {1, 7, 6, 0, 1, 3},
        {3, 6, 2, 3, 7, 2},
    };

    pair<int, int> peak_indices = findPeak(matrix);

    if (peak_indices.first == -1)
    {
        cout << "No peak element found in the matrix." << endl;
    }
    else
    {
        cout << "Peak element at: (" << peak_indices.first << ", " << peak_indices.second << ")" << endl;
    }

    return 0;
}

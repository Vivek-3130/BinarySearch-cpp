#include <iostream>
#include <vector>
using namespace std;


// Optimised Solution:- O(r+c)
pair<int, int> searchIn2DMatrix(vector<vector<int>> &matrix, int k){
    int r = matrix.size();
    int c = matrix[0].size();
    int n = 0 ,m  = c - 1;
    while(n < r && m >= 0){
        if(matrix[n][m] == k) return make_pair(n,m);

        else if(matrix[n][m] > k) m--;

        else n++;
    }
    return make_pair(-1,-1);
// time complexity of the code?
    


}

// Here every single row and column is sorted, not like in zig zag format.
int main() {
    vector<vector<int>> matrix = {
        {1,  4,  7,  11, 15},
        {2,  5,  8,  12, 19},
        {3,  6,  9,  16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int k = 14;
    pair<int, int> indices = searchIn2DMatrix(matrix,k);

    if (indices.first != -1) {
        cout <<"Target found at: (" << indices.first << ", " << indices.second << ")" << endl;
    } else {
        cout << "Target not found in the matrix." << endl;
    }

    return 0;
}

/*

#include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    int low = 0, high = n - 1;

    // Perform the steps:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return true;
        else if (target > nums[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

bool searchElement(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
        bool flag =  binarySearch(matrix[i], target);
        if (flag) return true;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = 
    {
    {1, 4, 7, 11, 15},
    {2, 5, 8, 12, 19},
    {3, 6, 9, 16, 22},
    {10, 13, 14, 17, 24},
    {18, 21, 23, 26, 30}
    };
    searchElement(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
}

*/
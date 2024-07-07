#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int findKthElement(vector<int> &a, vector<int> &b, int k){
    int n1 = a.size();
    int n2 = b.size();
    int n = (n1 + n2);
    if(n1 > n2) return findKthElement(b,a,k);  //swap krna padega as nhi to baar baar yhi hoga
    int low = max(0, k - n2);
    /*This ensures that we don't take fewer elements than possible from the first array when considering the k-th element.
     If we need at least k elements to reach the k-th element,
     we might need to take all k elements from the first array,
     especially if the second array doesn't have enough elements (n2 < k).
     */
    int  high = min(k, n1);
    /*
    This ensures that we don't take more elements than available in the first array.
    If k is greater than the number of elements in the first array (n1),
    we can't take more than n1 elements from the first array.
    */ 

//Logic**
/*
The k-th element in the combined sorted array of a and b will be
at position k-1 (0-based index). The strategy is to find the right partition between the two arrays such that:

The left side of the partition contains k elements.
The left part of both arrays combined is less than or equal
to the right part of both arrays combined.
*/ 
    int left = k; // no of element to be reside on each side after the symmetry-> allway K will be on the left side max element
    // Binary Search
    while( low <= high){
        int mid1 = (low + high)/2;
        int mid2 = left - mid1; // for the partitioning
        int l1 = INT_MIN , l2 = INT_MIN; //what if nothing is present there for the comparison.
        int r1= INT_MAX , r2 = INT_MAX;
        // if we see mid1 is pointing to r1 and mid to is pointing to r2
        if(mid1 < n1) r1 = a[mid1]; //then only it will take the element from the arr1 i.e mid1
        if(mid2 < n2) r2 = b[mid2];
        if(mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if(mid2 - 1 >= 0) l2 = b[mid2 - 1];

        if(l1 <= r2 && l2 <= r1) {
            return max(l1, l2);  // l2 will be the kth element
        }
        else if( l1 > r2) high = mid1 - 1; //which means its not sorted
        else low = mid1 + 1;
    }

    throw invalid_argument("Input arrays are not sorted or k is out of bounds.");
}

int main() {
    vector<int> nums1 = {2, 3, 6, 7, 9};
    vector<int> nums2 = {1, 4, 8, 10};
    int k = 5;
    try {
        cout << "The " << k << "-th element is: " << findKthElement(nums1, nums2, k) << endl;
    } catch (const invalid_argument &e) {
        cout << e.what() << endl;
    }
    return 0;
}
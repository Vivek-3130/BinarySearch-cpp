#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Brute Solution : O((n + m)log(n + m)) :- merge + sort + finding the median(constant tym)
// double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//     vector<int> merged(nums1.begin(), nums1.end());
//     merged.insert(merged.end(), nums2.begin(), nums2.end());

//     sort(merged.begin(), merged.end());

//     int n = merged.size();
//     if (n % 2 == 0) {
//         return (merged[n/2 - 1] + merged[n/2]) / 2.0;
//     } else {
//         return merged[n/2];
//     }
// }

//  Better Solution:O((n1+n2)), not using the extra space for merging the two array
// double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
// {
//     int n1 = nums1.size();
//     int n2 = nums2.size();
//     int i = 0; // for element increment in the nums1 array
//     int j = 0; // for element increment in the nums2 array
//     int n = (n1 + n2);
//     int ind2 = n / 2; //the index for the second median element.
//     int ind1 = ind2 - 1; // index for the first median element (only relevant if the total size is even).
//     int cnt = 0; // the current position in the merged sequence.
//     int ind1Element = -1, ind2Element = - 1;

//     while (i < n1 && j < n2)
//     {
//         if (nums1[i] < nums2[j])
//         {
//             if (cnt == ind1) //as apne to cnt kese bhi 4 chaiye agr 10 number h
//                 ind1Element = nums1[i];  //pehla index yha store ho jayega 4 
//             if (cnt == ind2)
//                 ind2Element = nums1[i]; //jese hi index 5 milega usko second Index Element me store kr lenge
//             cnt++; // counting the element in the array to get the 2 middle element
//             i++;   // incrementing the value in nums1 array
//         }
//         else
//         {  //yha reverse of first condition as index khi bhi ho skte hai
//             if (cnt == ind1)
//                 ind1Element = nums2[j];
//             if (cnt == ind2)
//                 ind2Element = nums2[j];
//             cnt++; // counting the element in the array to get the 2 middle element
//             j++;   // incrementing the value in nums2 array
//         }
//     }

//     // for the elements that are left beside do the same for them
//     while (i < n1)
//     {
//         if (cnt == ind1)
//             ind1Element = nums1[i];
//         if (cnt == ind2)
//             ind2Element = nums1[i];
//         cnt++; // counting the element in the array to get the 2 middle element
//         i++;   // incrementing the value in nums1 array
//     }

//     while (j < n2)
//     {
//         if (cnt == ind1)
//             ind1Element = nums2[j];
//         if (cnt == ind2)
//             ind2Element = nums2[j];
//         cnt++; // counting the element in the array to get the 2 middle element
//         j++;   // incrementing the value in nums2 array
//     }
//     if (n % 2 == 1){   // 9 / 2
//         return ind2Element;
//     }
//     else{      // 4 + 5 / 2   -> if no is even
//         return (double)((double)(ind1Element + ind2Element)) / 2.0;
//     }
// }

// Optimised Solution: O(log(min(n, m)))
double findMedianSortedArrays(vector<int> &a, vector<int> &b){
    int n1 = a.size();
    int n2 = b.size();
    int n = (n1 + n2);
    if(n1 > n2) return findMedianSortedArrays(b,a);  //swap krna padega as nhi to baar baar yhi hoga
    int low = 0 , high = n1;  // a high would be the maximum that a left side can have
    int left = ( n1 + n2 + 1)/2; // no of element to be reside on each side after the symmetry
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
            if( n % 2 == 1) return max(l1, l2);
            return (double)(max(l1,l2) + min(r1,r2))/2.0;
        }
        else if( l1 > r2) high = mid1 - 1; //which means its not sorted
        else low = mid1 + 1;
    }
    throw invalid_argument("Input arrays are not sorted.");
}
    
int main()
{
    vector<int> nums1 = {1, 3 ,5 , 7};
    vector<int> nums2 = {2, 4};
    try {
        cout << "Median is: " << findMedianSortedArrays(nums1, nums2) << endl;
    } catch (const invalid_argument &e) {
        cout << e.what() << endl;
    }
    return 0;
}
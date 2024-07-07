#include <bits/stdc++.h>
using namespace std;


// Brute force method: (k*n) + n its a quadratic in time thats why this will give the tle
// long double minimiseMaxDistance(vector<int> &arr, int k) {
//     int n = arr.size(); //size of array.
//     vector<int> howMany(n - 1, 0); //size according to the ampty spaces between two gas staion in the given array

//     //Pick and place k gas stations:
//     for (int gasStations = 1; gasStations <= k; gasStations++) {
//         //Find the maximum section
//         //and insert the gas station:
//         long double maxSection = -1;
//         int maxInd = -1;
//         for (int i = 0; i < n - 1; i++) {
//             long double diff = arr[i + 1] - arr[i];
//             long double sectionLength = diff / (long double)(howMany[i] + 1); //here in howmany[0] + 1 , it means only one gas staion is being inserted
//             if (sectionLength > maxSection) {
//                 maxSection = sectionLength;
//                 maxInd = i;
//             }
//         }
//         //insert the current gas station:
//         howMany[maxInd]++;
//     }

//     //Find the maximum distance i.e. the answer:
//     long double maxAns = -1;
//     for (int i = 0; i < n - 1; i++) {
//         long double diff = arr[i + 1] - arr[i];
//         long double sectionLength = diff / (long double)(howMany[i] + 1);
//         maxAns = max(maxAns, sectionLength);
//     }
//     return maxAns;
//     //Here we are just returning the maximum length between toew gas staion
// }

// Better Solution we can do it using priority queue: tree based structuring
// In priority queue when we do pq.top() it return the maximum value present in the priority queue rather than the top most element
// In priority queue when we do pq.pop() it deletes the maximum element
// Push : it is based on the O(logN) TC, Pop,Top : O(1) TC
// --HowMany As the Priority Queue in the beginning storing the spaces with the indexex in increasing order--
// |_(12,0)_|
// |_(6,2)_|
// |_(4,1)_|

// In the first gp
// |_(12,0)_|
// |_(6,2)_|
// |_(4,1)_|

// howmany vector =  |_0_|_0_|_0_|
// indexing vector=  0___1___2___ 
// Tc : (NlogN + KlogN)

// long double minimiseMaxDistance(vector<int> &arr, int k) {
//     int n = arr.size(); //size of array.
//     vector<int> howMany(n - 1, 0); //size according to the ampty spaces between two gas staion in the given array
//     priority_queue<pair<long double , int>> pq;
//     // here pq is conating thesection length and the index
//     for(int i = 0; i < n-1; i++){
//         pq.push({arr[i+1] - arr[i] , i});
//     }
//     for (int gasStations = 1; gasStations <= k; gasStations++){
//         auto tp = pq.top(); pq.pop(); //max element fteched and then the max element popped out
//         int secInd = tp.second; //here we got the index
//         howMany[secInd]++;

//         // here we alculted the new section length and the differenec in the new values

//         long double initialDiff = arr[secInd + 1] -arr[secInd];
//         long double newSecLec=n = initialDiff / (long double)(howMany[secInd] + 1);
        
//         // Yha pr baad me nayi section length and jis index pr present hai vo insert kr diya
//         pq.push({newSecLec , secInd});
//     }

//     return pq.top().first;  //s hume max distance chahiye jo sbse badi value hai priority queue
// }

// Optimised Solution Using Binary Search:
// Here we have to take the conditio diffeently as the values are in the form of long double
// here there will be no low <= high , rather it will say that
// high - low > 10^-6, so that it could cater the given input
// and also  using the mid + 1 or mid - 1 for low and high we will be using
// we will be using low = mid and high = mid

int numberOfGasStationsRequired(long double dist, vector<int> &arr){
    int cnt = 0;  //initially no of gas station
    for (int i = 1; i < arr.size(); i++) {
        int numberInBetween = ceil((arr[i] - arr[i - 1]) / dist) - 1;
        cnt += numberInBetween;
    }
    return cnt;
}



long double minimiseMaxDistance(vector<int> &arr, int k){
    int n = arr.size();
    //As we have to minimise the distance so the last range will be the maximum distance
    // Here rather using teh i++ we will be doing i + 10^-6 as we have long double included
    //0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1
    //the distance should be inside the that much,that could be easily inserted not too insert infinite number to get the maximum distance
    //like if we choose the distance to be 0 we need infinite number of 1, as well as if we choose the 0.1 then the difference of 1.5 - 1 = 0.5 ,hence the max will be 0.5 not 0.1
    //So we will start including the values that are greater than or euqla to 0.5 to 1
    long double low = 0;
    long double high = 0;
    for(int i = 0 ; i < n -1; i++){
        //to get the high as the maximum distance so taht we can slowly minimiz the seraching range
        high = max(high, (long double)(arr[i+1] - arr[i]));
    }
    long double diff = 1e-6;
    while(high - low > diff){
        long double mid = (low + high)/(2.0);
        int cnt = numberOfGasStationsRequired(mid, arr);
        if(cnt > k){  //when the value is too low and we are requiring many values to cater the need
            low = mid;
        }
        else{
            high = mid;
        }
    }
    return high;

}

int main()
{
    vector<int> arr = {1,2,3,4,5};
    int k = 4;
    long double ans = minimiseMaxDistance(arr, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}

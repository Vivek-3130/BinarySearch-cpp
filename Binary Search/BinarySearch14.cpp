#include<iostream>
#include<cmath>
using namespace std;

//Brute force: O(M*log2N) as we break
int sqrtRootNumber(int k, int n){
     return pow(k, n);
     
    //  ------OR------
     
    //  int result = 1;
    //  for (int i = 0; i < n; ++i) {
    //      result *= k;
    //  }
    //  return result;
}

// int nthRoot(int n, int m){
//     for(int i=1; i<=m; i++){
//         if(sqrtRootNumber(i,n) == m) return i;

//         else if(sqrtRootNumber(i,n) > m) break;
//     }
//     return -1;
// }


// Optimised Method: O(log2M)*log2N
int nthRoot(int n , int m){
    int low = 1;
    int high = m;
    int mid;
    while(low <= high){ 
        mid = low + (high - low) / 2;
        if(sqrtRootNumber(mid,n) == m) return mid;

        else if(sqrtRootNumber(mid,n) > m) high = mid -1;

        else low = mid + 1;
    }
    return -1;
}


int main() {
    int n,m;
    cin >> n >>m;

    int result = nthRoot(n,m);
    if (result != -1)
        cout << "Square root of " << n << " & " << m <<" is: "<< result << endl;
    else
        cout << "Nth Square root not found with in the range" <<endl;
    return 0;
}
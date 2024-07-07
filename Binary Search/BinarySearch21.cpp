#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // For accumulate function
using namespace std;
// Problem on min(max) or max(min)

// Brute Force: O(sum - max +1)*N, for sorting and computation
// even if want to acclocate one page i have to choose the maximum pages book to
// so that i can allocate each and every book
// Function to check if current allocation is possible
int isValidAllocation(const vector<int>& books, int m, int maxPages) {
    int students = 1;
    int pagesRead = 0;

    for (int i = 0; i < books.size(); ++i) {
        if (pagesRead + books[i] <= maxPages) {  //as yha pr agr assume krte hai ki 71 hi max ja skta hai allocation isiliye kiya hia ye
            pagesRead += books[i];
        } else {
            students++; //jump to next student, as hold nhi hua to next student pr chale gyae
            pagesRead = books[i]; //then from here restart again and allocate the books where ever we stopped
        }
    }

    return students;  //jese hi sari books allocate hogyi sbhi bacho me send true
}

// int minPages(vector<int> &books, int m){
//     int n = books.size();
//     if(m > n) return -1;

//     //as range will start from the maximum no of page book as
//     //as sbhi book 46pages,24ages,  ki allocate ho sake

//     // Find the maximum number of pages in any book
//     int maxPages = *max_element(books.begin(), books.end());
//     //here we will be getting the maxPage i.e 49 as it is the biggest

//     for (int pages = maxPages; pages <= accumulate(books.begin(), books.end(), 0); ++pages) {
//         if (isValidAllocation(books, m, pages) == m) {
//             return pages;
//         }
//     }
//     return -1;
// }

// Optimized sol:O(log2M)
int minPages(vector<int> &books, int m){
    int n = books.size();
    if(m > n) return -1;
    int low = *max_element(books.begin(),books.end());
    int high = accumulate(books.begin(),books.end(),0);
    int mid; 
    // sari book 1 bache ko denge to sum vali value hogi aur low hamara max hoga of the array
    while(low <= high){
        mid = (high + low)/2;
        if(isValidAllocation(books,m,mid) > m){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
}


int main() {
   vector<int> nums = {25,46,28,49,24}; // Example array
   int students = 4 ; // Example k value

   int allocatedBook = minPages(nums, students);
   cout << "The minimum number of maximum pages to be allocated is : " << allocatedBook << endl;

   return 0;
}

// 852. Peak Index in a Mountain Array

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        // Approach 1 (8ms)
        /*
        int index = 0;
        int max_val = -1;
        for(int i = 0; i < A.size(); i++) {
            if(max_val < A[i]) index = i; max_val = A[i];
        }
        return index;
        */
        // Approach 2 (8ms)
        // Start from index 1 and return when there is a dip
        for(int i = 1; i < A.size(); i++) {
            if(A[i-1] > A[i]) return i-1;
        }

        // Approach 3
        // Adding cout hack brought down execution time to 4ms

        // Approach 4
        // Use binary search tree
        // The time is still 4ms
        int l = 0, r = A.size() - 1, mid;
        while(l < r) {
            mid = (l + r) / 2;
            if(A[mid + 1] > A[mid]) {
                l = mid;
            } else if (A[mid - 1] > A[mid]) {
                r = mid;
            } else return mid;
        }
    }
};

int main() {
    std::vector<int> arr = {0, 2, 1, 0};
    Solution s;
    std::cout << s.peakIndexInMountainArray(arr) << std::endl;
}
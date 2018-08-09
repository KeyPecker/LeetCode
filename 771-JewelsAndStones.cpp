#include <string>
#include <iostream>
#include <set>
using namespace std;

// Use the following code to get really good perf
/*
const auto ___ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
*/


class Solution {
public:
    // J contains all characters that are jewels
    // S contains stones and jewels.
    // Using J, calculate all the number of jewels
    // present in S
    int numJewelsInStones(string J, string S) {
        int num_jewels = 0;
        // add J to a set
        std::set<char> set_for_j;
        for(auto iter = J.begin(); iter != J.end(); iter++) {
            set_for_j.insert(*iter);
        }
        // for each element in S,
        // check if it a jewel or not by finding it in set_for_j
        // if it is present, increment num_jewels
        for(auto iter = S.begin(); iter != S.end(); iter++) {
            if(set_for_j.find(*iter) != set_for_j.end()) num_jewels++;
        }
        return num_jewels;
    }
};

class Solution2 {
public:
    // Lets optimize the previous version of code more
    // In the problem, it is given that the values of
    // J are unique. Which means, we can use a static bit array
    // to flag if a character is present or not.
    // We use character as index and true/false as value
    // When we compare characters in S with characters in J,
    // we use S[index] as index to J as in,
    // num_jewels += if(J[S[index]] == true) ? 1 : 0;
    int numJewelsInStones(string J, string S) {
        int num_jewels = 0;
        bool hash_j[256];
        for(auto iter = J.begin(); iter != J.end(); iter++) {
            hash_j[*iter] = true;
        }
        for(auto iter = S.begin(); iter != S.end(); iter++) {
            num_jewels += hash_j[*iter] ? 1 : 0;
        }
        return num_jewels;
    }
};

int main() {
    Solution2 s;
    std::cout << s.numJewelsInStones("aA", "aAAbbbbbb") << std::endl;
}
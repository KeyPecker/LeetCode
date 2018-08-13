// 728. Self Dividing Numbers

// Couldn't solve

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    bool isSelfDivide(int val) {
        bool is_self_divide = true;
        bool is_changed = false;
        int num = val;
        int start = 10000;
        while(val / start != 0) {
            start = start / 10;
        }
        for(int i = start; i > 0; i = i / 10) {
            if(num / i > 0) {
                std::cout << num << " " << num / i << std::endl;
                int mod_factor = num / i;
                is_self_divide = is_self_divide && ((val % mod_factor) == 0);
                is_changed = true;
                num = num % i;
            }
            if(num / i == 0) {
                is_self_divide = false;
            }
        }
        return is_self_divide && is_changed;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ret;
        for(int i = left; i <= right; i++) {
            if(isSelfDivide(i)) ret.push_back(i);
        }
        return ret;
    }
};

int main() {
    Solution s;
    auto ret = s.selfDividingNumbers(128, 129);
    for(auto iter = ret.begin(); iter != ret.end(); iter++) {
        std::cout << *iter << std::endl;
    }
}
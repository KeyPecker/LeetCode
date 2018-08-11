// 461. Hamming Distance

#include <iostream>

class Solution {
 public:
  int hammingDistance(int x, int y) {
    int xor_val = x ^ y;
    int num_diff = 0;
    // initial solution
    /* version 1
        for(int i = 0; i < 32; i++) {
            num_diff += (xor_val & (1 << i)) == (1 << i) ? 1 : 0;
        }
    */

    /* version 2
        while(xor_val > 0) {
            num_diff += (xor_val & 1);
            xor_val = xor_val >> 1;
        }
    */
    // final version
    //
    // removing comparision operator
    // in while statement improved performance
    // from 4ms to 0ms
    //
    while (xor_val) {
      num_diff += (xor_val & 1);
      xor_val = xor_val >> 1;
    }
    return num_diff;
  }
};

int main() {
  Solution s;
  std::cout << s.hammingDistance(1, 4) << std::endl;
}
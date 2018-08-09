#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int horizontal = 0;
        int vertical = 0;

        for(size_t i = 0; i < moves.size(); i++) {
            if('U' == moves[i]) vertical++;
            if('D' == moves[i]) vertical--;
            if('L' == moves[i]) horizontal++;
            if('R' == moves[i]) horizontal--;
        }
        return vertical == 0 && horizontal == 0;
    }
};

int main() {
    Solution s;
    std::cout << s.judgeCircle("UD") << std::endl;
}
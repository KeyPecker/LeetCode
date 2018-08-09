// 709 To Lower Case 

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // Upper case alphas start from 65dec(A) to 90dec(Z)
    // To convert to lower case, you have to add 32dec to 
    string toLowerCase(string str) {
       for(int i=0;i<str.size();i++) {
           str[i] = (str[i] >= 'A' && str[i] <= 'Z') ? str[i] + ' ' : str[i]; // 32
       }
       return str;
    }
};

int main(int argc, char* argv[]) {
    if(argc != 2) {
        return 0;
    }
    std::string str = argv[1];
    Solution s;
    std::cout << s.toLowerCase(str) << std::endl;
}
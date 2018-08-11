// 804. Unique Morse Code Words

#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

std::unordered_map<char, string> morse_translation_table = {
    {'a', ".-"},   {'b', "-..."}, {'c', "-.-."}, {'d', "-.."},  {'e', "."},
    {'f', "..-."}, {'g', "--."},  {'h', "...."}, {'i', ".."},   {'j', ".---"},
    {'k', "-.-"},  {'l', ".-.."}, {'m', "--"},   {'n', "-."},   {'o', "---"},
    {'p', ".--."}, {'q', "--.-"}, {'r', ".-."},  {'s', "..."},  {'t', "-"},
    {'u', "..-"},  {'v', "...-"}, {'w', ".--"},  {'x', "-..-"}, {'y', "-.--"},
    {'z', "--.."}};

class Solution {
 public:
  int uniqueMorseRepresentations(vector<string>& s) {
    std::set<string> hash_table;
    for (auto iter_vec = s.begin(); iter_vec != s.end(); iter_vec++) {
      string tmp;
      for (auto iter_str = iter_vec->begin(); iter_str != iter_vec->end();
           iter_str++) {
        tmp += morse_translation_table[*iter_str];
      }
      hash_table.insert(tmp);
    }
    return hash_table.size();
  }
};

// as you are using characters as index, instead of creating a hash table
// The performance did not go up.
// Changing std::set to std::unordered_set did not change the performance
class Solution2 {
 private:
  string morse_map[26] = {".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",
                          "....", "..",   ".---", "-.-",  ".-..", "--",   "-.",
                          "---",  ".--.", "--.-", ".-.",  "...",  "-",    "..-",
                          "...-", ".--",  "-..-", "-.--", "--.."};

 public:
  int uniqueMorseRepresentations(vector<string>& s) {
    std::set<string> hash_table;
    for (auto iter_vec = s.begin(); iter_vec != s.end(); iter_vec++) {
      string tmp;
      for (auto iter_str = iter_vec->begin(); iter_str != iter_vec->end();
           iter_str++) {
        tmp += morse_map[*iter_str - 'a'];
      }
      hash_table.insert(tmp);
    }
    return hash_table.size();
  }
};

int main() {
  std::vector<string> v_str = {"gin", "zen", "gig", "msg"};
  Solution2 s;
  std::cout << s.uniqueMorseRepresentations(v_str) << std::endl;
}
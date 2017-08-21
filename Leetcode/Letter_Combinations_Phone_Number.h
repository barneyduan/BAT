#ifndef LETTER_COMBINATIONS_PHONE_NUMBER_H__
#define LETTER_COMBINATIONS_PHONE_NUMBER_H__

#include <string>
#include <vector>
#include <map>

using namespace std;



vector<string> letterCombinations(string digits) {
  if (ditgits.empty()) {
    return vector<string>();
  }
  static const vector<string> v = {"", "", "abc", "def", "ghi",
                                   "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    res.push_back(""); // add a seed for the initial case
    int size = digits.size();
    for (int i = 0; i < size; i ++) {
      int num = digits[i] - '0';
      if (num < 0 || num > 9) {
        break;
      }
      string val = v[num];
      if (val.empty()) {
        continue;
      }
      vector<string> temp;
      for (int j = 0; j < val.size(); ++ j) {
        for (int k = 0; k < res.size(); ++ k) {
          temp.push_back(res[k] + val[j]);
        }
      }
      res.swap(temp);
    }
  return res;
}

#endif
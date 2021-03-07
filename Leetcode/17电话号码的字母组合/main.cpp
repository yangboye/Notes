// 题目: https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  unordered_map<char, string> dct; // 存储电话按键对应的字母
  vector<string> result;  // 存储结果
  string path;    // 存储路径

  void backtrack(string digits, int cur) {
    if (path.size() == digits.size()) {
      result.push_back(path);
      return;
    }
    for (int i = 0; i < dct[digits[cur]].size(); ++i) {
      path.push_back(dct[digits[cur]][i]);
      backtrack(digits, cur + 1);
      path.pop_back();
    }
  }

  vector<string> letterCombinations(string digits) {
    dct['2'] = "abc";
    dct['3'] = "def";
    dct['4'] = "ghi";
    dct['5'] = "jkl";
    dct['6'] = "mno";
    dct['7'] = "pqrs";
    dct['8'] = "tuv";
    dct['9'] = "wxyz";
    if (digits.empty()) return result;
    backtrack(digits, 0);
    return result;
  }
};

int main() {

  getchar();
  return 0;
}
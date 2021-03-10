// 题目：https://leetcode-cn.com/problems/basic-calculator/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  int calculate(string s) {
    stack<int> ops; // 当前符号
    ops.push(1);    // 1：‘+’，-1：‘-’
    int sign = 1;
    int result = 0;
    int len = s.length();
    int i = 0;
    while (i < len) {
      if (s[i] == ' ') {
        i++;
      } else if (s[i] == '+') {
        sign = ops.top();
        i++;
      } else if (s[i] == '-') {
        sign = -ops.top();
        i++;
      } else if (s[i] == '(') {
        ops.push(sign);   // 保存当前符号
        i++;
      } else if (s[i] == ')') {
        ops.pop();
        ++i;
      } else {  // 数字
        int64_t num = 0;
        while (i < len && s[i] >= '0' && s[i] <= '9') {
          num = num * 10 + s[i] - '0';
          ++i;
        }
        result += sign * num;
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  cout << s.calculate("1+2-(3+4)");
  getchar();
  return 0;
}
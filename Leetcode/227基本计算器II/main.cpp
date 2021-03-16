// 题目：https://leetcode-cn.com/problems/basic-calculator-ii/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  int calculate(string s) {
    int len = s.size();
    if (len <= 0) return 0;
    stack<int> num; // 数字
    stack<char> opt;    // 运算符
    for (int i = 0; i < len; ++i) {
      if (s[i] == ' ') {    // 是空格，忽略
        continue;
      } else if ((s[i] == '+') || (s[i] == '-') || (s[i] == '*') || (s[i] == '/')) { // 是运算符
        opt.push(s[i]);
      } else {    // 是数字，但位数可能大于1
        int cur_sum = 0;
        while (i < len && s[i] >= '0' && s[i] <= '9') {
          cur_sum = cur_sum * 10 + s[i] - '0';
          ++i;
        }
        --i;    // 回退

        if (!opt.empty() && opt.top() == '-') {
          opt.pop();
          opt.push('+');
          cur_sum = -cur_sum;
        }

        num.push(cur_sum);
        if ((num.size() >= 2) && (!opt.empty()) && (opt.top() == '*' || opt.top() == '/')) {
          int parm2 = num.top();
          num.pop();
          int parm1 = num.top();
          num.pop();
          int temp;
          if (opt.top() == '*') {
            temp = parm1 * parm2;
          } else {
            temp = parm1 / parm2;
          }
          num.push(temp);
          opt.pop();
        }
      }
    }
    while (!opt.empty()) {
      int parm2 = num.top();
      num.pop();
      int parm1 = num.top();
      num.pop();
      if (opt.top() == '+') {
        num.push(parm1 + parm2);
      } else {
        num.push(parm1 - parm2);
      }
      opt.pop();
    }
    return num.top();
  }
};

int main() {
  Solution s;
  cout << s.calculate("1-1+1");
  getchar();
  return 0;
}
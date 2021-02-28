// ÌâÄ¿Á´½Ó: https://leetcode-cn.com/problems/valid-parentheses/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> record;
    int len = s.length();
    for (int i = 0; i < len; ++i) {
      if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
        record.push(s[i]);
      } else{
        if (record.empty()) return false;
        switch (s[i]) {
          case ')':
            if (record.top() != '(') return false;
            break;
          case ']':
            if (record.top() != '[') return false;
            break;
          case '}':
            if (record.top() != '{') return false;
            break;
          default:
            break;
        }
        record.pop();
      }
    }
    return record.empty();
  }
};

int main() {
  Solution s;
  string str = "()";
  cout << s.isValid(str);
  getchar();
}
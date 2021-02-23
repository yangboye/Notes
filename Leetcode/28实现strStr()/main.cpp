// 题目名称: 实现strStr() 
// 题目链接：https://leetcode-cn.com/problems/implement-strstr/

// Note: 这里要注意的是size()返回的类型为size_t(unsigned int)，如果为负数，则越界了。

#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    if (needle.size() == 0) { // needle是空字符串的情况
      return 0;
    }

    for (int i = 0; i < (int)(haystack.size()) - (int)(needle.size()) + 1; ++i) {
      int j = 0;
      for (; j < needle.size(); ++j) {
        if (haystack[i + j] != needle[j]) {
          break;
        }
      }
      if (j == needle.size()) {
        return i;
      }
    }

    return -1;
  }
};

int main() {
  Solution s;
  string haystack = "a";
  string needle = "bba";

  cout << s.strStr(haystack, needle) << endl;
  getchar();
  return 0;
}
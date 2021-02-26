// 题目名称: 实现strStr() 
// 题目链接：https://leetcode-cn.com/problems/implement-strstr/

// Note: 这里要注意的是size()返回的类型为size_t(unsigned int)，如果为负数，则越界了。

#include<string>
#include<iostream>
using namespace std;

//class Solution {
//public:
//  int strStr(string haystack, string needle) {
//    if (needle.size() == 0) { // needle是空字符串的情况
//      return 0;
//    }
//
//    for (int i = 0; i < (int)(haystack.size()) - (int)(needle.size()) + 1; ++i) {
//      int j = 0;
//      for (; j < needle.size(); ++j) {
//        if (haystack[i + j] != needle[j]) {
//          break;
//        }
//      }
//      if (j == needle.size()) {
//        return i;
//      }
//    }
//
//    return -1;
//  }
//};

//class Solution { // 使用KMP算法
//public:
//  int* getNext(const string& s) {  // 获取next数组
//    int len = s.length();
//    int* next = new int[len];
//    next[0] = -1;
//    int j = 0;
//    int k = -1;
//    while (j < len - 1) {
//      if (k == -1 || s[j] == s[k]) {
//        next[++j] = ++k;
//      } else {
//        k = next[k];
//      }
//    }
//    return next;
//  }
//
//  int strStr(string haystack, string needle) {
//    int sub_len = needle.length();
//    if (sub_len == 0) {
//      return 0;
//    }
//
//    int* next = getNext(needle);  // next数组
//    for (int i = 0; i < sub_len; ++i) {
//      cout << next[i] << " ";
//    }
//    cout << endl; 
//    int i = 0;    // 主串的位置
//    int j = 0;    // 模式串的位置
//    while (i < haystack.length() && j < needle.length()) {
//      if (j == -1 || haystack[i] == needle[j]) {
//        ++i;
//        ++j;
//      } else {
//        j = next[j];  // j回到指定位置
//      }
//    }
//    if (j == needle.length()) {
//      return i - j;
//    } else {
//      return -1;
//    }
//  }
//};

class Solution {
public:
  void getNext(int* next, const string& p) {
    int len = p.length();
    next[0] = -1;
    int j = 0;
    int k = -1;

    while (j < len - 1) {
      if (k == -1 || p[j] == p[k]) {
        j++;
        k++;
        if (p[j] == p[k]) {
          next[j] = next[k];
        } else {
          next[j] = k;
        }
      } else {
        k = next[k];
      }
    }
  }

  int kmp(const string& t, const string& p) {
    int len_t = t.length();
    int len_p = p.length();
    int i = 0;  // 主串的位置
    int j = 0;  // 模式串的位置
    int* next = new int[len_p];

    //getNext(next, p);  // 获取next数组
    getNext(next, p);  // 获取next数组

    for (int i = 0; i < len_p; ++i) {
      cout << next[i] << " ";
    }
    cout << endl;

    while (i < len_t && j < len_p) {
      if (j == -1 || t[i] == p[j]) {
        i++;
        j++;
      } else {
        j = next[j];
      }
    }

    if (j == len_p) {
      return i - j;
    } else {
      return -1;
    }
  }

  int strStr(string haystack, string needle) {
    return kmp(haystack, needle);
  }
};


class Solution2 {
public:
  void getNext(int* next, const string& s) {
    int j = -1;
    next[0] = j;
    for (int i = 1; i < s.size(); i++) { // 注意i从1开始
      while (j >= 0 && s[i] != s[j + 1]) { // 前后缀不相同了
        j = next[j]; // 向前回溯
      }
      if (s[i] == s[j + 1]) { // 找到相同的前后缀
        j++;
      }
      next[i] = j; // 将j（前缀的长度）赋给next[i]
    }
  }
  int strStr(string haystack, string needle) {
    if (needle.size() == 0) {
      return 0;
    }
    int* next = new int[needle.size()];
    getNext(next, needle);

    cout << "第二种: ";
    for (int i = 0; i < needle.size(); ++i) {
      cout << next[i] << " ";
    }
    cout << endl;

    int j = -1; // // 因为next数组里记录的起始位置为-1
    for (int i = 0; i < haystack.size(); i++) { // 注意i就从0开始
      while (j >= 0 && haystack[i] != needle[j + 1]) { // 不匹配
        j = next[j]; // j 寻找之前匹配的位置
      }
      if (haystack[i] == needle[j + 1]) { // 匹配，j和i同时向后移动 
        j++;
      }
      if (j == (needle.size() - 1)) { // 文本串s里出现了模式串t
        return (i - needle.size() + 1);
      }
    }
    return -1;
  }
};

int main() {
  Solution s;
  Solution2 s2;
  string haystack = "aabaabaafa";
  string needle = "ababaaababaa";

  cout << s.strStr(haystack, needle) << endl;
  cout << s2.strStr(haystack, needle) << endl;
  getchar();
  return 0;
}
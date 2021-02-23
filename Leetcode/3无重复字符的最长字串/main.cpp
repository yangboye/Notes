// ÌâÄ¿Á´½Ó£ºhttps://leetcode-cn.com/problems/longest-substring-without-repeating-characters/

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int res = 0;
    int i = 0;
    int dct[256] = { 0 };
    int sub_len = 0;
    int len = s.length();
    for (int j = 0; j < len; ++j) {
      ++dct[s[j]];
      while (dct[s[j]] > 1) {
        dct[s[i++]]--;
      }
      sub_len = j - i + 1;
      res = res < sub_len ? sub_len : res;
    }
    return res;
  }
};
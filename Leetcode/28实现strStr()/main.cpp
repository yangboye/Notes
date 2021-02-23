// ��Ŀ����: ʵ��strStr() 
// ��Ŀ���ӣ�https://leetcode-cn.com/problems/implement-strstr/

// Note: ����Ҫע�����size()���ص�����Ϊsize_t(unsigned int)�����Ϊ��������Խ���ˡ�

#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    if (needle.size() == 0) { // needle�ǿ��ַ��������
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
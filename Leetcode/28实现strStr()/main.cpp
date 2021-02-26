// ��Ŀ����: ʵ��strStr() 
// ��Ŀ���ӣ�https://leetcode-cn.com/problems/implement-strstr/

// Note: ����Ҫע�����size()���ص�����Ϊsize_t(unsigned int)�����Ϊ��������Խ���ˡ�

#include<string>
#include<iostream>
using namespace std;

//class Solution {
//public:
//  int strStr(string haystack, string needle) {
//    if (needle.size() == 0) { // needle�ǿ��ַ��������
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

//class Solution { // ʹ��KMP�㷨
//public:
//  int* getNext(const string& s) {  // ��ȡnext����
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
//    int* next = getNext(needle);  // next����
//    for (int i = 0; i < sub_len; ++i) {
//      cout << next[i] << " ";
//    }
//    cout << endl; 
//    int i = 0;    // ������λ��
//    int j = 0;    // ģʽ����λ��
//    while (i < haystack.length() && j < needle.length()) {
//      if (j == -1 || haystack[i] == needle[j]) {
//        ++i;
//        ++j;
//      } else {
//        j = next[j];  // j�ص�ָ��λ��
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
    int i = 0;  // ������λ��
    int j = 0;  // ģʽ����λ��
    int* next = new int[len_p];

    //getNext(next, p);  // ��ȡnext����
    getNext(next, p);  // ��ȡnext����

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
    for (int i = 1; i < s.size(); i++) { // ע��i��1��ʼ
      while (j >= 0 && s[i] != s[j + 1]) { // ǰ��׺����ͬ��
        j = next[j]; // ��ǰ����
      }
      if (s[i] == s[j + 1]) { // �ҵ���ͬ��ǰ��׺
        j++;
      }
      next[i] = j; // ��j��ǰ׺�ĳ��ȣ�����next[i]
    }
  }
  int strStr(string haystack, string needle) {
    if (needle.size() == 0) {
      return 0;
    }
    int* next = new int[needle.size()];
    getNext(next, needle);

    cout << "�ڶ���: ";
    for (int i = 0; i < needle.size(); ++i) {
      cout << next[i] << " ";
    }
    cout << endl;

    int j = -1; // // ��Ϊnext�������¼����ʼλ��Ϊ-1
    for (int i = 0; i < haystack.size(); i++) { // ע��i�ʹ�0��ʼ
      while (j >= 0 && haystack[i] != needle[j + 1]) { // ��ƥ��
        j = next[j]; // j Ѱ��֮ǰƥ���λ��
      }
      if (haystack[i] == needle[j + 1]) { // ƥ�䣬j��iͬʱ����ƶ� 
        j++;
      }
      if (j == (needle.size() - 1)) { // �ı���s�������ģʽ��t
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
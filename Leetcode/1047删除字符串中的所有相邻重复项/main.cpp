// ÌâÄ¿£º https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

//class Solution {
//public:
//  string removeDuplicates(string S) {
//    int len = S.length();
//    if (len <= 1) return S;
//    stack<char> st;
//    st.push(S[0]);
//    for (int i = 1; i < len; ++i) {
//      if ((!st.empty()) && (S[i] == st.top())) {
//        st.pop();
//      } else {
//        st.push(S[i]);
//      }
//    }
//    string result = "";
//    while (!st.empty()) {
//      result = st.top() + result;
//      st.pop();
//    }
//    return result;
//  }
//};

class Solution {
public:
  string removeDuplicates(string S) {
    string stk;
    for (char ch : S) {
      if (!stk.empty() && stk.back() == ch) {
        stk.pop_back();
      } else {
        stk.push_back(ch);
      }
    }
    return stk;
  }
};

int main() {
  Solution s;
  string str = "abbaca";
  cout << s.removeDuplicates(str);
  return 0;
}
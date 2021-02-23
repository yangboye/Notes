// 题目链接：https://leetcode-cn.com/problems/minimum-size-subarray-sum/

#include<iostream>
#include<vector>

using namespace std;

// 暴力
//class Solution {
//public:
//  int minSubArrayLen(int target, vector<int>& nums) {
//    int res = INT_MAX;
//    int len = nums.size();
//    for (int i = 0; i < len; ++i) {
//      int sum = 0;
//      for (int j = i; j < len; ++j) {
//        sum += nums[j];
//        if (sum >= target) {
//          int temp = j - i + 1;
//          res = res > temp ? temp : res;
//          break;
//        }
//      }
//    }
//    return res == INT_MAX ? 0 : res;
//  }
//};

// 滑动窗口
class Solution {
public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int res = INT_MAX;
    int i = 0;  // 窗口起始位置
    int sub_len = 0;
    int len = nums.size();
    int sum = 0;
    for (int j = 0; j < len; ++j) {
      sum += nums[j];
      while (sum >= target) {
        sub_len = j - i + 1;
        res = res > sub_len ? sub_len : res;
        sum -= nums[i++]; // 更新窗口起始位置
      }
    }
    return res == INT_MAX ? 0 : res;
  }
};


int main() {
  int target = 7;
  vector<int> nums = { 2,3,1,2,4,3 };
  Solution s;
  cout << s.minSubArrayLen(target, nums);
  getchar();
  return 0;
}


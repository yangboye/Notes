// 题目名称: 子集
// 题目链接：https://leetcode-cn.com/problems/subsets/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    res.push_back(vector<int>());
    for (int i = 0; i < nums.size(); ++i) {
      int all = res.size();
      for (int j = 0; j < all; ++j) {
        vector<int> tmp(res.at(j));
        tmp.push_back(nums[i]);
        res.push_back(tmp);
      }
    }
    return res;
  }
};

int main() {
  vector<int> nums = { 1, 2, 3 };
  Solution s;
  auto res = s.subsets(nums);

  return 0;
}
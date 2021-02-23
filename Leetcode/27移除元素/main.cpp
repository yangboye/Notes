// 题目名称: 移除元素
// 题目链接：https://leetcode-cn.com/problems/remove-element/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    if (nums.empty()) {
      return 0;
    }
    int len = nums.size();
    int j = 0;
    for (int i = 0; i < len; ++i) {
      if (nums[i] != val) {
        nums[j] = nums[i];
        j++;
      }
    }
    return j;
  }
};

int main() {
  vector<int> nums = { 0,1,2,2,3,0,4,2 };
  Solution s;
  int len = s.removeElement(nums, 2);
  cout << "Length: " << len << endl;
  for (int i = 0; i < len; ++i) {
    cout << nums[i] << " ";
  }
  getchar();
  return 0;
}
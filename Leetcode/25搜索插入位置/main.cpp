// 题目名称: 搜索插入位置
// 题目链接：https://leetcode-cn.com/problems/search-insert-position/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int len = nums.size();

    if ((target < nums[0]) || (0 == len)) {
      return 0;
    }

    if ((target > nums[len-1])) {
      return len;
    }

    int low = 0;
    int high = len - 1;
    int mid = (low + high + 1) / 2;
    while (low <= high) {
      if (target == nums[mid]) {
        return mid;
      }
      if (target > nums[mid]) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
      mid = (low + high + 1) / 2;
    }
    return mid;
  }
};

int main() {
  vector<int> nums = { 1,3,5,6 };
  Solution s;
  cout << s.searchInsert(nums, 4);

  return 0;
}
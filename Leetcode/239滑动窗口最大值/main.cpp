// 题目: https://leetcode-cn.com/problems/sliding-window-maximum/

#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>

using namespace std;

//class Solution {    // 暴力
//public:
//  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//    int len = nums.size();
//
//    if (len <= k) {
//      return { *max_element(nums.begin(), nums.end()) };
//    }
//    
//    vector<int> result;
//    int cur_max_idx = max_element(nums.begin(), nums.begin() + k) - nums.begin(); // 第一个窗口内的最大值位置
//    result.push_back(nums[cur_max_idx]);
//
//    for (int i = 1; i <= len - k; ++i) {
//      if (cur_max_idx == i - 1) { // 上一个窗口的最大值位置在窗口的第0个位置
//        cur_max_idx = max_element(nums.begin() + i, nums.begin() + i + k) - nums.begin(); // 当前窗口内的最大值位置
//      } else {
//        if (nums[cur_max_idx] < nums[i + k - 1]) {  // 更新最大值的位置
//          cur_max_idx = i + k - 1;
//        }
//        //cur_max_idx = nums[cur_max_idx] > nums[i + k - 1] ? cur_max_idx : i + k - 1;
//      }
//      result.push_back(nums[cur_max_idx]);
//    }
//    return result;
//  }
//};

class Solution {
public:
  class MyQueue { // 单调队列(此处为单调递减队列，队头为最大元素)
  public:
    void push(int val) {
      while (!deque_.empty() && deque_.back() < val) {  // 保证放入元素后，队列仍然单调递减
        deque_.pop_back();
      }
      deque_.push_back(val);
    }

    void pop(int val) {
      if (!deque_.empty() && deque_.front() == val) { // 每次要弹出的时候，比较要弹出的值是否为当前窗口的最大值
        deque_.pop_front();
      }
    }

    int front() { // 队头元素，为当前窗口的最大元素
      return deque_.front();
    }
  private:
    deque<int> deque_;
  };

  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int len = nums.size();
    MyQueue que;
    vector<int> result;

    for (int i = 0; i < k; ++i) {
      que.push(nums[i]);
    }
    result.push_back(que.front());

    for (int i = 1; i <= len - k; ++i) {
      que.pop(nums[i - 1]);
      que.push(nums[i + k - 1]);
      result.push_back(que.front());
    }
    return result;
  }
};

struct tmp1 {
  bool operator()(int a, int b) {
    return a < b;
  }
};

int main() {
  vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
  priority_queue<int, vector<int>, tmp1> a(nums.begin(), nums.end());
  while (!a.empty()) {
    cout << a.top() << " ";
    a.pop();
  }
  cout << endl;


  //Solution s;
  //vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
  //int k = 3;
  //auto res = s.maxSlidingWindow(nums, k);

  //for (auto& n : res) {
  //  cout << n << " ";
  //}
  //cout << endl;
  getchar();
}
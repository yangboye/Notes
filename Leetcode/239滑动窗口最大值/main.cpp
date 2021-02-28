// ��Ŀ: https://leetcode-cn.com/problems/sliding-window-maximum/

#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>

using namespace std;

//class Solution {    // ����
//public:
//  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//    int len = nums.size();
//
//    if (len <= k) {
//      return { *max_element(nums.begin(), nums.end()) };
//    }
//    
//    vector<int> result;
//    int cur_max_idx = max_element(nums.begin(), nums.begin() + k) - nums.begin(); // ��һ�������ڵ����ֵλ��
//    result.push_back(nums[cur_max_idx]);
//
//    for (int i = 1; i <= len - k; ++i) {
//      if (cur_max_idx == i - 1) { // ��һ�����ڵ����ֵλ���ڴ��ڵĵ�0��λ��
//        cur_max_idx = max_element(nums.begin() + i, nums.begin() + i + k) - nums.begin(); // ��ǰ�����ڵ����ֵλ��
//      } else {
//        if (nums[cur_max_idx] < nums[i + k - 1]) {  // �������ֵ��λ��
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
  class MyQueue { // ��������(�˴�Ϊ�����ݼ����У���ͷΪ���Ԫ��)
  public:
    void push(int val) {
      while (!deque_.empty() && deque_.back() < val) {  // ��֤����Ԫ�غ󣬶�����Ȼ�����ݼ�
        deque_.pop_back();
      }
      deque_.push_back(val);
    }

    void pop(int val) {
      if (!deque_.empty() && deque_.front() == val) { // ÿ��Ҫ������ʱ�򣬱Ƚ�Ҫ������ֵ�Ƿ�Ϊ��ǰ���ڵ����ֵ
        deque_.pop_front();
      }
    }

    int front() { // ��ͷԪ�أ�Ϊ��ǰ���ڵ����Ԫ��
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
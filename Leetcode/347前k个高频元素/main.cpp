// ÌâÄ¿: https://leetcode-cn.com/problems/top-k-frequent-elements/

#include <iostream>
#include <vector>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution {
public:
  struct cmp {
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
      return lhs.second > rhs.second;
    }
  };

  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> dct;
    for (auto& num : nums) {
      dct[num]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pri_que;
    for (auto& n : dct) {
      pri_que.push(n);
      if (pri_que.size() > k) {
        pri_que.pop();
      }
    }
    vector<int> result(k);
    for (int i = k - 1; i >= 0; i--) {
      result[i] = pri_que.top().first;
      pri_que.pop();
    }
    return result;
  }
};

int main() {
  Solution s;
  vector<int> nums = { 1,1,1,2,2,3 };
  auto res = s.topKFrequent(nums, 2);
  return 0;
}
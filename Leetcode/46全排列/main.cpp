// ÌâÄ¿£º https://leetcode-cn.com/problems/permutations/

#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> result;
  void backtrack(vector<int>& path, const vector<int>& nums) {
    if (path.size() == nums.size()) {
      result.push_back(path);
      return;
    }
    for (auto& n : nums) {
      if (find(path.begin(), path.end(), n) != path.end()) {
        continue;
      }
      path.push_back(n);
      backtrack(path, nums);
      path.pop_back();
    }
  }
  vector<vector<int>> permute(vector<int>& nums) {
    if (nums.empty()) return result;
    vector<int> path;
    backtrack(path, nums);
    return result;
  }
};

int main() {
  vector<int> nums = { 1,2,3 };
  Solution s;
  s.permute(nums);
  cout << "end" << endl;
  getchar();
  return 0;
}
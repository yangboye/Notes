// 动态规划背包问题入门：https://mp.weixin.qq.com/s?__biz=MzUxNjY5NTYxNA==&mid=2247486598&idx=1&sn=dd7d0530dd7a5caef7ce70cc3d6eee3f&scene=21#wechat_redirect

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// dp为一维数组
void BagProblem(const vector<int>& weight, const vector<int>& value, const int bag_weight, vector<int>& dp) {
  for (int i = 0; i < weight.size(); ++i) { // 遍历物品
    for (int j = bag_weight; j >= weight[i]; --j) { // 遍历背包容量
      dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
  }
}


// dp为二维数组
void BagProblem(const vector<int>& weight, const vector<int>& value, const int bag_weight, vector<vector<int>>& dp) {
  // 初始化
  for (int j = bag_weight; j >= weight[0]; j--) { // 从后往前
    dp[0][j] = dp[0][j - weight[0]] + value[0];
  }

  for (int i = 1; i < weight.size(); ++i) { // 物品0在上面已经初始化了
    for (int j = 0; j <= bag_weight; ++j) {
      if (j < weight[i]) {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
      }
    }
  }

}

int main() {
  vector<int> weight = { 1,3,4 }; // weight[i]: 第i个物品的重量
  vector<int> value = { 15,20,30 }; // value[i]: 第i个物品的价值
  int bag_weight = 4; // 背包的最大容量
  // dp2d[i][j]:从下标[1..i]的物品里任取，放进容量为j的背包的最大价值总和
  vector<vector<int>> dp2d(weight.size(), vector<int>(bag_weight + 1, 0));
  BagProblem(weight, value, bag_weight, dp2d);
  for (int i = 0; i < dp2d.size(); ++i) {
    for (int j = 0; j < dp2d[0].size(); ++j) {
      cout << dp2d[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  // dp[j]: 容量为j的背包，所背的物品价值可以最大为dp[j]
  vector<int> dp(bag_weight + 1, 0);
  BagProblem(weight, value, bag_weight, dp);
  for (const int n : dp) {
    cout << n << " ";
  }

  getchar();
  return 0;
}
// ��̬�滮�����������ţ�https://mp.weixin.qq.com/s?__biz=MzUxNjY5NTYxNA==&mid=2247486598&idx=1&sn=dd7d0530dd7a5caef7ce70cc3d6eee3f&scene=21#wechat_redirect

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// dpΪһά����
void BagProblem(const vector<int>& weight, const vector<int>& value, const int bag_weight, vector<int>& dp) {
  for (int i = 0; i < weight.size(); ++i) { // ������Ʒ
    for (int j = bag_weight; j >= weight[i]; --j) { // ������������
      dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
  }
}


// dpΪ��ά����
void BagProblem(const vector<int>& weight, const vector<int>& value, const int bag_weight, vector<vector<int>>& dp) {
  // ��ʼ��
  for (int j = bag_weight; j >= weight[0]; j--) { // �Ӻ���ǰ
    dp[0][j] = dp[0][j - weight[0]] + value[0];
  }

  for (int i = 1; i < weight.size(); ++i) { // ��Ʒ0�������Ѿ���ʼ����
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
  vector<int> weight = { 1,3,4 }; // weight[i]: ��i����Ʒ������
  vector<int> value = { 15,20,30 }; // value[i]: ��i����Ʒ�ļ�ֵ
  int bag_weight = 4; // �������������
  // dp2d[i][j]:���±�[1..i]����Ʒ����ȡ���Ž�����Ϊj�ı���������ֵ�ܺ�
  vector<vector<int>> dp2d(weight.size(), vector<int>(bag_weight + 1, 0));
  BagProblem(weight, value, bag_weight, dp2d);
  for (int i = 0; i < dp2d.size(); ++i) {
    for (int j = 0; j < dp2d[0].size(); ++j) {
      cout << dp2d[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  // dp[j]: ����Ϊj�ı�������������Ʒ��ֵ�������Ϊdp[j]
  vector<int> dp(bag_weight + 1, 0);
  BagProblem(weight, value, bag_weight, dp);
  for (const int n : dp) {
    cout << n << " ";
  }

  getchar();
  return 0;
}
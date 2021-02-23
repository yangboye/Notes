// ��Ŀ���ӣ�https://leetcode-cn.com/problems/spiral-matrix-ii/
// ����˼·: https://mp.weixin.qq.com/s/KTPhaeqxbMK9CxHUUgFDmg

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0));
    int loop = n / 2; // Ҫѭ����Ȧ��
    int start_x = 0, start_y = 0; // ��ǰȦ����ʼ������
    int mid = n / 2;  // �м�λ�õ����꣬���n���������������
    int num = 1;
    int offset = 1; // �߽糤��
    int i, j;

    while (loop--) {
      i = start_x;
      j = start_y;
      // ������
      for (; j < start_y + n - offset; ++j) {
        res[i][j] = num++;
      }
      // ���ϵ���
      for (; i < start_x + n - offset; ++i) {
        res[i][j] = num++;
      }
      // ���ҵ���
      for (; j > start_y; --j) {
        res[i][j] = num++;
      }
      // ���µ���
      for (; i > start_x; --i) {
        res[i][j] = num++;
      }
      // ����Ȧ���������
      start_x++;
      start_y++;

      // ���±߽糤��
      offset += 2;
    }
    // ���һ���������
    if (n % 2) {
      res[mid][mid] = num;
    }
    return res;
  }
};
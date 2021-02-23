// 题目链接：https://leetcode-cn.com/problems/spiral-matrix-ii/
// 解题思路: https://mp.weixin.qq.com/s/KTPhaeqxbMK9CxHUUgFDmg

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0));
    int loop = n / 2; // 要循环的圈数
    int start_x = 0, start_y = 0; // 当前圈的起始点坐标
    int mid = n / 2;  // 中间位置的坐标，如果n是奇数，单独填充
    int num = 1;
    int offset = 1; // 边界长度
    int i, j;

    while (loop--) {
      i = start_x;
      j = start_y;
      // 从左到右
      for (; j < start_y + n - offset; ++j) {
        res[i][j] = num++;
      }
      // 从上到下
      for (; i < start_x + n - offset; ++i) {
        res[i][j] = num++;
      }
      // 从右到左
      for (; j > start_y; --j) {
        res[i][j] = num++;
      }
      // 从下到上
      for (; i > start_x; --i) {
        res[i][j] = num++;
      }
      // 更新圈的起点坐标
      start_x++;
      start_y++;

      // 更新边界长度
      offset += 2;
    }
    // 最后一个单独填充
    if (n % 2) {
      res[mid][mid] = num;
    }
    return res;
  }
};
#include <vector>
using namespace std;

// 更简单的做法: 

class Solution {
public:
  bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; ++i) {
      int j = 0;
      int idx = i;
      int start = matrix[idx][j];
      while (idx + 1 < m && j + 1 < n) {
        ++idx;
        ++j;
        if (matrix[idx][j] != start) {
          return false;
        }
      }
    }

    for (int j = 1; j < n; ++j) {
      int i = 0;
      int idx = j;
      int start = matrix[i][idx];
      while (i + 1 < m && idx + 1 < n) {
        ++i;
        ++idx;
        if (matrix[i][idx] != start) {
          return false;
        }
      }
    }

    return true;
  }
};

int main() {
  return 0;
}
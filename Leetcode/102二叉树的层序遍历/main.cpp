// ÌâÄ¿: https://leetcode-cn.com/problems/binary-tree-level-order-traversal/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (root == nullptr) return result;
    queue<TreeNode*> que;
    TreeNode* node;
    que.push(root);
    while (!que.empty()) {
      int level_cnt = que.size();
      result.push_back({});
      for (int i = 0; i < level_cnt; ++i) {
        node = que.front();
        que.pop();
        result.back().push_back(node->val);
        if (node->left) que.push(node->left);
        if (node->right) que.push(node->right);
      }
    } // while
    return result;
  }
};
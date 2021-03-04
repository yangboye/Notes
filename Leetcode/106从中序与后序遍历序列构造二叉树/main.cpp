// ��Ŀ���ӣ�https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

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
  unordered_map<int, int> inorder_index;  // �������� <�����ֵ, �±�>
  // ����λ�� [left, right)
  TreeNode* build(int leftin,             /*������ʼλ��*/
                  int rightin,            /*�������λ��*/
                  int leftpost,           /*������ʼλ��*/
                  int rightpost,          /*�������λ��*/
                  vector<int>& inorder,   /*��������*/
                  vector<int>& postorder  /*��������*/
  ) {
    if (leftin >= rightin) return nullptr;
    TreeNode* root = new TreeNode(postorder[rightpost - 1]);    // �����
    // Ѱ�Ҹ�����������е�λ��
    // int rootin = leftin;
    // while(rootin < rightin && inorder[rootin] != postorder[rightpost - 1]) rootin++;
    // ʹ�ù�ϣ������������ڵ��������е�λ��  
    int rootin = inorder_index[postorder[rightpost - 1]];
    int left = rootin - leftin; // �������������ĳ���
    root->left = build(leftin, rootin, leftpost, leftpost + left, inorder, postorder);
    root->right = build(rootin + 1, rightin, leftpost + left, rightpost - 1, inorder, postorder);
    return root;
  }
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    for (int i = 0; i < inorder.size(); ++i) {
      inorder_index[inorder[i]] = i;
    }
    return build(0, inorder.size(), 0, postorder.size(), inorder, postorder);
  }
};

void pre_traversal(TreeNode* root) {
  if (root == nullptr) return;
  cout << root->val << " ";
  pre_traversal(root->left);
  pre_traversal(root->right);
}

int main() {
  Solution s;
  vector<int> inorder = { 9,3,15,20,7 };
  vector<int> postorder = { 9,15,7,20,3 };
  TreeNode* root = s.buildTree(inorder, postorder);
  pre_traversal(root);
  return 0;
}
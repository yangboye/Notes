# Leetcode刷题记录

参考：

- https://github.com/youngyangyang04/leetcode-master

## 数组

| 题号 |                             题目                             |                             实现                             |                             参考                             |          备注          |
| :--: | :----------------------------------------------------------: | :----------------------------------------------------------: | :----------------------------------------------------------: | :--------------------: |
| 209  | [长度最小的子数组](https://leetcode-cn.com/problems/minimum-size-subarray-sum/) | [C++](https://github.com/yangboye/Notes/blob/master/Leetcode/209%E9%95%BF%E5%BA%A6%E6%9C%80%E5%B0%8F%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84/main.cpp) | [数组：滑动窗口拯救了你](https://mp.weixin.qq.com/s/UrZynlqi4QpyLlLhBPglyg) |        滑动窗口        |
|  3   | [无重复字符的最长字串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/) | [C++](https://github.com/yangboye/Notes/blob/master/Leetcode/3%E6%97%A0%E9%87%8D%E5%A4%8D%E5%AD%97%E7%AC%A6%E7%9A%84%E6%9C%80%E9%95%BF%E5%AD%97%E4%B8%B2/main.cpp) | [字符串最长子串难？滑动窗口拯救你](https://mp.weixin.qq.com/s?__biz=Mzg4MDU1NzU0NA==&mid=2247485221&idx=1&sn=54b2f4ab6b5b3e55a38b58c09410e0a7&chksm=cf722ba2f805a2b4178daaee48b5a550da09d2a170763db0400c84dc1c746563e49201eda102&scene=132#wechat_redirect) |        滑动窗口        |
|  25  | [搜索插入位置](https://leetcode-cn.com/problems/search-insert-position/) | [C++](https://github.com/yangboye/Notes/blob/master/Leetcode/25%E6%90%9C%E7%B4%A2%E6%8F%92%E5%85%A5%E4%BD%8D%E7%BD%AE/main.cpp) | [数组：每次遇到二分法，都是一看就会，一写就废](https://mp.weixin.qq.com/s?__biz=MzUxNjY5NTYxNA==&mid=2247484289&idx=1&sn=929fee0ac9f308a863a4fc4e2e44506e&scene=21#wechat_redirect) | 二分法、循环不变量原则 |
|  59  | [螺旋矩阵 II](https://leetcode-cn.com/problems/spiral-matrix-ii/) | [C++](https://github.com/yangboye/Notes/blob/master/Leetcode/59%E8%9E%BA%E6%97%8B%E7%9F%A9%E9%98%B5%20II/main.cpp) | [数组：这个循环可以转懵很多人！](https://mp.weixin.qq.com/s/KTPhaeqxbMK9CxHUUgFDmg) |     循环不变量原则     |
|  27  | [移除元素](https://leetcode-cn.com/problems/remove-element/) | [C++](https://github.com/yangboye/Notes/blob/master/Leetcode/27%E7%A7%BB%E9%99%A4%E5%85%83%E7%B4%A0/main.cpp) | [数组：就移除个元素很难么？](https://mp.weixin.qq.com/s?__biz=MzUxNjY5NTYxNA==&mid=2247484304&idx=1&sn=ad2e11d171f74ad772fd23b10142e3f3&scene=21#wechat_redirect) |        快慢指针        |



## 链表

| 题号 |                             题目                             | 实现 |                             参考                             |   备注   |
| :--: | :----------------------------------------------------------: | :--: | :----------------------------------------------------------: | :------: |
| 141  | [环形链表](https://leetcode-cn.com/problems/linked-list-cycle/) |      | [详解为什么用一步两步快慢指针？三步四步可以吗](https://leetcode-cn.com/problems/linked-list-cycle/solution/xiang-jie-wei-shi-yao-yong-yi-bu-liang-b-i6xo/) | 快慢指针 |
| 142  | [环形链表 II](https://leetcode-cn.com/problems/linked-list-cycle-ii/) |      | [详解为什么用一步两步快慢指针？三步四步可以吗](https://leetcode-cn.com/problems/linked-list-cycle/solution/xiang-jie-wei-shi-yao-yong-yi-bu-liang-b-i6xo/) | 快慢指针 |
| 206  | [反转链表](https://leetcode-cn.com/problems/reverse-linked-list/) |      | [链表：听说过两天反转链表又写不出来了？](https://mp.weixin.qq.com/s/pnvVP-0ZM7epB8y3w_Njwg) |          |
|      |                                                              |      |                                                              |          |
|      |                                                              |      |                                                              |          |





## 哈希表



## 字符串

kmp算法参考博客(第一篇对应的是最长字串的形式，第二个是位置的形式)：

- [字符串匹配的KMP算法](http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html)
- [KMP算法详解-彻底清楚了(转载+部分原创)](https://www.cnblogs.com/dusf/p/kmp.html)
- [kmp算法 next[]数组的两种求法](https://www.jianshu.com/p/2ac684ab44c8)

## 栈与队列



## 树

### 二叉树的遍历

二叉树的存储结构:

```c++
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* _left, TreeNode* _right): val(x), left(_left), right(_right) {}
};
```

N叉树的存储结构：

```c++
struct Node{
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val): val(_val) {}
    Node(int _val, vector<Node*> _children):val(_val), children(_children) {}
};
```

#### 前序遍历

- 递归：

  ```c++
  void traversal(TreeNode* node, vector<int>& vec) {
      if(node == nullptr) return;
      vec.push_back(node->val);		// T
      traversal(node->left, vec);		// L
      traversal(node->right, vec);	// R
  }
  
  vector<int> preorderTraversal(TreeNode* root) {
      vector<int> result;
      traversal(root, result);
      return result;
  }
  ```

- 迭代:

  ```c++
  vector<int> preorderTraversal(TreeNode* root) {
      vector<int> result;
      if(root == nullptr) return result;
      stack<TreeNode*> st;
      st.push(root);
      while(!st.empty()) {
          TreeNode* node = st.top();
          st.pop();
          if(node == nullptr) continue;
          result.push_back(node->val);	// T
          // 栈的性质，先放入右子树，再放入左子树
          st.push(node->right);			// R
          st.push(node->left);			// T
      }
      return result;
  }
  ```

#### 中序遍历

- 递归:

  ```c++
  void traversal(TreeNode* node, vector<int>& vec) {
      if(node == nullptr) return;
      traversal(node->left, vec);		// L
      vec.push_back(node->val);		// T
      traversal(node->right, vec);	// R
  }
  
  vector<int> inorderTraversal(TreeNode* root) {
      vector<int> result;
      traversal(root, result);
      return result;
  }
  ```

- 迭代:

  ```c++
  vector<int> inorderTraversal(TreeNode* root) {
      vector<int> result;
      if(root == nullptr) return result;
      stack<TreeNode*> st;
      TreeNode* cur = root;
      while(cur || !st.empty()) {
          while(cur) {	// 访问所有左子树 L
              st.push(cur);
              cur = cur->left;
          }
          // 已经到了最左下角
          cur = st.top();
          st.pop();
          result.push_back(cur->val);	// T
          cur = cur->right;	// R
      }
      return result;
  }
  ```

#### 后序遍历

- 递归:

  ```c++
  void traversal(TreeNode* node, vector<int>& vec) {
      if(node == nullptr) return;
      traversal(node->left, vec);		// L
      traversal(node->right, vec);	// R
      vec.push_back(node->val);		// T
  }
  
  vector<int> postorderTraversal(TreeNode* root) {
      vector<int> result;
      traversal(root, result);
      return result;
  }
  ```

- 迭代:

  ```c++
  // 后序遍历的迭代方法与前序遍历类似，访问TRL，然后逆序得到LRT即为后序
  vector<int> postorderTraversal(TreeNode* root) {
      vector<int> result;
      if(root == nullptr) return result;
      stack<TreeNode*> st;
      st.push(root);
      while(!st.empty()) {
          TreeNode* node = st.top();
          st.pop();
          if(node == nullptr) continue;
          result.push_back(node->val);	// T
          // 先访问R，再访问L
          st.push(node->left);	// L
          st.push(node->right);	// R
      }
      // 上面得到的result中的是TRL，逆序得到LRT
      reverse(result.begin(), result.end());
      return result;
  }
  ```

#### 层次遍历

- 迭代:

  ```c++
  // 使用队列
  vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> result;
      if(root == nullptr) return result;
      queue<int> que;
      que.push(root);
      while(!que.empty()) {
          int level_cnt = que.size();	// 当前层的结点个数
          vector<int> temp;			// 当前层的所有节点
          for(int i = 0; i < level_cnt; ++i) {
              TreeNode* node = que.front();
              que.pop();
              temp.push_back(node->val);
              if(node->left) que.push(node->left);
              if(node->right) que.push(node->right);
          }
          result.push_back(temp);
      }
      return result;
  }
  ```

#### 相关的题目

| 题号 |                             题目                             | 实现 |                             参考                             |                             备注                             |
| :--: | :----------------------------------------------------------: | :--: | :----------------------------------------------------------: | :----------------------------------------------------------: |
| 144  | [二叉树的前序遍历](https://leetcode-cn.com/problems/binary-tree-preorder-traversal/) |      |                                                              |                         栈、前序遍历                         |
|  94  | [二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/) |      |                                                              |                         栈、中序遍历                         |
| 145  | [二叉树的后序遍历](https://leetcode-cn.com/problems/binary-tree-postorder-traversal/) |      |                                                              |                   栈、后序遍历、vector反转                   |
| 102  | [二叉树的层序遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/) |      |                                                              |                        队列、层次遍历                        |
| 226  | [翻转二叉树](https://leetcode-cn.com/problems/invert-binary-tree/) |      |                                                              |              前序遍历/后序遍历/层序遍历+swap()               |
| 107  | [二叉树的层序遍历 II](https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/) |      |                                                              |                       层序遍历+reverse                       |
| 199  | [二叉树的右视图](https://leetcode-cn.com/problems/binary-tree-right-side-view/) |      |                                                              |                           层序遍历                           |
| 637  | [二叉树的层平均值](https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/) |      |                                                              |                           层序遍历                           |
| 429  | [N 叉树的层序遍历](https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/) |      |                                                              |                           层序遍历                           |
| 589  | [N叉树的前序遍历](https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/) |      |                                                              |                         栈、前序遍历                         |
| 590  | [N叉树的后序遍历](https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal/) |      |                                                              |                         栈、后序遍历                         |
| 101⭐ | [对称二叉树](https://leetcode-cn.com/problems/symmetric-tree/) |      | [二叉树：我对称么？](https://mp.weixin.qq.com/s/Kgf0gjvlDlNDfKIH2b1Oxg) |                          递归、遍历                          |
| 104  | [二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/) |      | [二叉树：看看这些树的最大深度](https://mp.weixin.qq.com/s/guKwV-gSNbA1CcbvkMtHBg) |                   层序遍历(递归用后序LRT)                    |
| 559  | [N 叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree/) |      |                                                              |                   层序遍历(递归用后序LRT)                    |
| 222  | [完全二叉树的节点个数](https://leetcode-cn.com/problems/count-complete-tree-nodes/) |      |                                                              |                    遍历（递归用后序LRT）                     |
| 110⭐ | [平衡二叉树](https://leetcode-cn.com/problems/balanced-binary-tree/) |      | [二叉树：我平衡么？](https://mp.weixin.qq.com/s/isUS-0HDYknmC0Rr4R8mww) |                                                              |
| 257⭐ | [二叉树的所有路径](https://leetcode-cn.com/problems/binary-tree-paths/) |      |                                                              |                        先序遍历(TLR)                         |
| 100  |   [相同的树](https://leetcode-cn.com/problems/same-tree/)    |      |                                                              | 遍历（联系【[101](https://leetcode-cn.com/problems/symmetric-tree/)】题） |
| 404  | [左叶子之和](https://leetcode-cn.com/problems/sum-of-left-leaves/) |      |                                                              |                       判断左叶子的条件                       |
| 513  | [找树左下角的值](https://leetcode-cn.com/problems/find-bottom-left-tree-value/) |      |                                                              |                           层序遍历                           |
| 106⭐ | [从中序与后序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/) |      |                                                              |                         二叉树的构建                         |

**递归之经验：**

1. 递归三部曲：

   - 确定递归函数的参数和返回值；

   - 确定终止条件；

   - 确定单层递归的逻辑；

     

2. 递归函数什么时候需要返回值？什么时候不需要返回值？

> **「如果需要搜索整颗二叉树，那么递归函数就不要返回值，如果要搜索其中一条符合条件的路径，递归函数就需要返回值，因为遇到符合条件的路径了就要及时返回。」**



3. 参考：
   - [二叉树：以为使用了递归，其实还隐藏着回溯](https://mp.weixin.qq.com/s/ivLkHzWdhjQQD1rQWe6zWA)
   - [二叉树：递归函数究竟什么时候需要返回值，什么时候不要返回值？](https://mp.weixin.qq.com/s/6TWAVjxQ34kVqROWgcRFOg)



**经验：**

- 树的题目先尝试用递归的方法解决，关键是选择一个合适的遍历方式；
- 



### 二叉树的属性

主要是求二叉树的最大/最小深度、最大宽度、结点个数等等，关键是选择合适的遍历方法（一般就是迭代用层序遍历，递归用后序遍历）。



### 二叉树的构建

| 题号 |                             题目                             | 实现 | 参考 |     备注     |
| :--: | :----------------------------------------------------------: | :--: | :--: | :----------: |
| 106⭐ | [从中序与后序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/) |      |      | 二叉树的构建 |



## 回溯



## 贪心



## DP


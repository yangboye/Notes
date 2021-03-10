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

### 二叉树理论：

二叉树分为：满二叉树、完全二叉树、二叉搜素树(BST)、平衡二叉树(AVL)。[关于二叉树，你该了解这些！](https://mp.weixin.qq.com/s/_ymfWYvTNd2GvWvC5HOE4A)

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

| 题号  |                             题目                             | 实现 |                             参考                             |                             备注                             |
| :---: | :----------------------------------------------------------: | :--: | :----------------------------------------------------------: | :----------------------------------------------------------: |
|  144  | [二叉树的前序遍历](https://leetcode-cn.com/problems/binary-tree-preorder-traversal/) |      |                                                              |                         栈、前序遍历                         |
|  94   | [二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/) |      |                                                              |                         栈、中序遍历                         |
|  145  | [二叉树的后序遍历](https://leetcode-cn.com/problems/binary-tree-postorder-traversal/) |      |                                                              |                   栈、后序遍历、vector反转                   |
|  102  | [二叉树的层序遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/) |      |                                                              |                        队列、层次遍历                        |
|  226  | [翻转二叉树](https://leetcode-cn.com/problems/invert-binary-tree/) |      |                                                              |              前序遍历/后序遍历/层序遍历+swap()               |
|  107  | [二叉树的层序遍历 II](https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/) |      |                                                              |                       层序遍历+reverse                       |
|  199  | [二叉树的右视图](https://leetcode-cn.com/problems/binary-tree-right-side-view/) |      |                                                              |                           层序遍历                           |
|  637  | [二叉树的层平均值](https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/) |      |                                                              |                           层序遍历                           |
|  429  | [N 叉树的层序遍历](https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/) |      |                                                              |                           层序遍历                           |
|  589  | [N叉树的前序遍历](https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/) |      |                                                              |                         栈、前序遍历                         |
|  590  | [N叉树的后序遍历](https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal/) |      |                                                              |                         栈、后序遍历                         |
| 101⭐  | [对称二叉树](https://leetcode-cn.com/problems/symmetric-tree/) |      | [二叉树：我对称么？](https://mp.weixin.qq.com/s/Kgf0gjvlDlNDfKIH2b1Oxg) |                          递归、遍历                          |
|  104  | [二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/) |      | [二叉树：看看这些树的最大深度](https://mp.weixin.qq.com/s/guKwV-gSNbA1CcbvkMtHBg) |                   层序遍历(递归用后序LRT)                    |
|  559  | [N 叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree/) |      |                                                              |                   层序遍历(递归用后序LRT)                    |
|  111  | [二叉树的最小深度](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/) |      | [二叉树：看看这些树的最小深度](https://mp.weixin.qq.com/s/BH8-gPC3_QlqICDg7rGSGA) |                                                              |
|  222  | [完全二叉树的节点个数](https://leetcode-cn.com/problems/count-complete-tree-nodes/) |      |                                                              |                    遍历（递归用后序LRT）                     |
| 110⭐  | [平衡二叉树](https://leetcode-cn.com/problems/balanced-binary-tree/) |      | [二叉树：我平衡么？](https://mp.weixin.qq.com/s/isUS-0HDYknmC0Rr4R8mww) |                                                              |
| 257⭐⭐ | [二叉树的所有路径](https://leetcode-cn.com/problems/binary-tree-paths/) |      |                                                              |                     回溯、先序遍历(TLR)                      |
|  100  |   [相同的树](https://leetcode-cn.com/problems/same-tree/)    |      |                                                              | 遍历（联系【[101](https://leetcode-cn.com/problems/symmetric-tree/)】题） |
|  404  | [左叶子之和](https://leetcode-cn.com/problems/sum-of-left-leaves/) |      |                                                              |                       判断左叶子的条件                       |
|  513  | [找树左下角的值](https://leetcode-cn.com/problems/find-bottom-left-tree-value/) |      |                                                              |                           层序遍历                           |
| 106⭐  | [从中序与后序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/) |      |                                                              |                         二叉树的构建                         |
| 543⭐  | [二叉树的直径](https://leetcode-cn.com/problems/diameter-of-binary-tree/) |      |                                                              |                           树的深度                           |
| 236⭐  | [二叉树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/) |      | [二叉树：公共祖先问题](https://mp.weixin.qq.com/s/n6Rk3nc_X3TSkhXHrVmBTQ) |                           后序遍历                           |
| 235⭐  | [二叉搜索树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) |      |                                                              |                       二叉搜索树的性质                       |
|  617  | [合并二叉树](https://leetcode-cn.com/problems/merge-two-binary-trees/) |      | [二叉树：合并两个二叉树](https://mp.weixin.qq.com/s?__biz=MzUxNjY5NTYxNA==&mid=2247484988&idx=1&sn=03bc66ed9af4f5ddf7891d06b0a850f3&scene=21#wechat_redirect) |                                                              |

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
- 最近公共祖先的问题: （1）普通二叉树，需要从底网上遍历，选择后序遍历【[题236](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)】；（2）二叉搜索树，本身就有序，只需从上向下遍历，选择先序遍历【[题235]([二叉搜索树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/))】；



### 二叉树的属性

主要是求二叉树的最大/最小深度、最大宽度、结点个数等等，关键是选择合适的遍历方法（一般就是迭代用层序遍历，递归用后序遍历）。



### 二叉树的构建

| 题号 |                             题目                             | 实现 | 参考 |     备注     |
| :--: | :----------------------------------------------------------: | :--: | :--: | :----------: |
| 106⭐ | [从中序与后序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/) |      |      | 二叉树的构建 |
| 105  | [从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) |      |      | 二叉树的构建 |
|      |                                                              |      |      |              |



### 二叉搜索树

二叉搜索树中序遍历是有序的。如果涉及统计或者比较的，一般需要一个指针指向前一个结点.

| 题号 |                             题目                             | 实现 |                             参考                             |       备注        |
| :--: | :----------------------------------------------------------: | :--: | :----------------------------------------------------------: | :---------------: |
| 700  | [二叉搜索树中的搜索](https://leetcode-cn.com/problems/search-in-a-binary-search-tree/) |      |                                                              |                   |
| 501⭐ | [二叉搜索树中的众数](https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/) |      | [二叉树：我的众数是多少？](https://mp.weixin.qq.com/s/KSAr6OVQIMC-uZ8MEAnGHg) | map转vector的排序 |
| 530  | [二叉搜索树的最小绝对差](https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/) |      |                                                              |     中序遍历      |
| 701  | [二叉搜索树中的插入操作](https://leetcode-cn.com/problems/insert-into-a-binary-search-tree/) |      |                                                              |                   |
| 450⭐ | [删除二叉搜索树中的节点](https://leetcode-cn.com/problems/delete-node-in-a-bst/) |      |                                                              |                   |
| 108⭐ | [将有序数组转换为二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/) |      |                                                              |                   |
| 538⭐ | [把二叉搜索树转换为累加树](https://leetcode-cn.com/problems/convert-bst-to-greater-tree/) |      |                                                              |                   |



## 回溯

### 解决的问题

回溯是暴力解法，如果需要优化，则添加一些剪枝操作。回溯一般可以解决如下几种问题：

- 组合问题：N个数里面按一定规则找出k个数的集合
- 排列问题：N个数按一定规则全排列，有几种排列方式
- 切割问题：一个字符串按一定规则有几种切割方式
- 子集问题：一个N个数的集合里有多少符合条件的子集
- 棋盘问题：N皇后，解数独等等

> 组合与排列的区别：**组合是不强调元素顺序的，排列是强调元素顺序**



### 理论

#### 回溯算法模板框架

框架如下：

```c++
void backtracking(参数) {
    if (终止条件) {
        存放结果;
        return;
    }

    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
        处理节点;
        backtracking(路径，选择列表); // 递归
        回溯，撤销处理结果
    }
}
```



### 相关题目

| 题号 |                             题目                             | 实现 |                             参考                             |     备注      |
| :--: | :----------------------------------------------------------: | :--: | :----------------------------------------------------------: | :-----------: |
|  77  |    [组合](https://leetcode-cn.com/problems/combinations/)    |      | [回溯算法：求组合问题！](https://mp.weixin.qq.com/s?__biz=MzUxNjY5NTYxNA==&mid=2247485253&idx=1&sn=8332edaabc9bf43e45835bce7964ce88&scene=21#wechat_redirect) |   组合问题    |
|  39  | [组合总和](https://leetcode-cn.com/problems/combination-sum/) |      |                                                              |               |
| 40⭐  | [组合总和 II](https://leetcode-cn.com/problems/combination-sum-ii/) |      | [回溯算法：求组合总和（三）](https://mp.weixin.qq.com/s/_1zPYk70NvHsdY8UWVGXmQ) |               |
|      |                                                              |      |                                                              |               |
| 131⭐ | [分割回文串](https://leetcode-cn.com/problems/palindrome-partitioning/) |      | [回溯算法：分割回文串](https://mp.weixin.qq.com/s/Pb1epUTbU8fHIht-g_MS5Q) |   分割问题    |
| 93⭐  | [复原 IP 地址](https://leetcode-cn.com/problems/restore-ip-addresses/) |      |                                                              |               |
|  78  |      [子集](https://leetcode-cn.com/problems/subsets/)       |      | [回溯算法：求子集问题！](https://mp.weixin.qq.com/s/NNRzX-vJ_pjK4qxohd_LtA) |   子集问题    |
| 90⭐  |   [子集 II](https://leetcode-cn.com/problems/subsets-ii/)    |      |                                                              | 子集问题+去重 |
| 491⭐ | [递增子序列](https://leetcode-cn.com/problems/increasing-subsequences/) |      | [回溯算法：递增子序列](https://mp.weixin.qq.com/s/ePxOtX1ATRYJb2Jq7urzHQ) |               |
|  46  |   [全排列](https://leetcode-cn.com/problems/permutations/)   |      |                                                              |   排列问题    |
|  47  |                                                              |      |                                                              |               |



### 经验

#### 1. 何时需要`startIndex`？

> 如果是一个集合来求组合的话，就需要startIndex，例如：[回溯算法：求组合问题！](https://mp.weixin.qq.com/s?__biz=MzUxNjY5NTYxNA==&mid=2247485253&idx=1&sn=8332edaabc9bf43e45835bce7964ce88&scene=21#wechat_redirect)，[回溯算法：求组合总和！](https://mp.weixin.qq.com/s?__biz=MzUxNjY5NTYxNA==&mid=2247485277&idx=1&sn=0553db6b5c5952094d536ae2b8c18124&scene=21#wechat_redirect)。
>
> 如果是多个集合取组合，各个集合之间相互不影响，那么就不用startIndex，例如：[回溯算法：电话号码的字母组合](https://mp.weixin.qq.com/s?__biz=MzUxNjY5NTYxNA==&mid=2247485295&idx=1&sn=35bd6c240a5a59d7ea6d9f98c09e7dbd&scene=21#wechat_redirect)

#### 2. 何时需要对元素排序？

> 如果元素有重复，一般需要排序。例如：[组合总和II](https://leetcode-cn.com/problems/combination-sum-ii/)。但是子序列问题不可以，例如[491]

#### 3. result.add(path)的位置

> 一般来说：组合问题和排列问题是在树形结构的叶子节点上收集结果，而子集问题就是取树上所有节点的结果。

#### 4. 何时需要`return;`，何时又不需要？

> 看情况。



## 贪心

### 解决的问题



### 理论

贪心算法一般分为四步：

- 将问题分解为若干子问题；

- 找出适合的贪心策略；

- 求解每一个子问题的最优解；

- 将局部最优解堆叠成全局最优解。

  

贪心的题一般需要排序

### 相关题目

| 题号 |                             题目                             | 实现 |                             参考                             |     备注     |
| :--: | :----------------------------------------------------------: | :--: | :----------------------------------------------------------: | :----------: |
| 455  | [分发饼干](https://leetcode-cn.com/problems/assign-cookies/) |      |                                                              | 排序，双指针 |
| 376⭐ | [摆动序列](https://leetcode-cn.com/problems/wiggle-subsequence/) |      | [贪心思路 清晰而正确的题解](https://leetcode-cn.com/problems/wiggle-subsequence/solution/tan-xin-si-lu-qing-xi-er-zheng-que-de-ti-jie-by-lg/) |              |
|  53  | [最大子序和](https://leetcode-cn.com/problems/maximum-subarray/) |      |                                                              |      DP      |



### 经验





## 动态规划

### 解决的问题

动态规划（Dynamic Programming），如果某一问题有很多重叠子问题，使用动态规划是最有效的。动态规划中每一个状态一定是由上一个状态推导出来的，这一点区分于贪心，贪心没有状态推导，而是从局部直接选最优的。



### 理论

拆解为五步：

- 确定dp数组及其下标的含义；
- 确定递推公式；
- dp数组如何初始化；
- 确定遍历顺序；
- 举例推导dp数组。



### 相关题目

| 题号 |                             题目                             | 实现 | 参考 |        备注        |
| :--: | :----------------------------------------------------------: | :--: | :--: | :----------------: |
| 509  | [斐波那契数](https://leetcode-cn.com/problems/fibonacci-number/) |      |      |      动态规划      |
|  70  | [爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)  |      |      |      动态规划      |
| 746  | [使用最小花费爬楼梯](https://leetcode-cn.com/problems/min-cost-climbing-stairs/) |      |      | 理解“阶梯顶”的意思 |
|  62  |  [不同路径](https://leetcode-cn.com/problems/unique-paths/)  |      |      |                    |
| 343⭐ | [整数拆分](https://leetcode-cn.com/problems/integer-break/)  |      |      |                    |
| 96⭐  | [不同的二叉搜索树](https://leetcode-cn.com/problems/unique-binary-search-trees/) |      |      |      卡特兰数      |



### 经验





## 其他

### 随机、拒绝采样

| 题号 |                             题目                             | 实现 | 参考 |   备注   |
| :--: | :----------------------------------------------------------: | :--: | :--: | :------: |
| 470⭐ | [用 Rand7() 实现 Rand10()](https://leetcode-cn.com/problems/implement-rand10-using-rand7/) |      |      | 拒绝采样 |



# 技巧

- 将字符串转换成整型

  ```c++
  const char ts[] = "123";
  int a;
  sscanf(ts, "%d", &a);
  ```

  
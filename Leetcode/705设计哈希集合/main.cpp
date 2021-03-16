// 题目：https://leetcode-cn.com/problems/design-hashset/

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class MyHashSet { // 开放链地址法
public:
  MyHashSet() : data(kBase) {}

  void add(int key) { // 添加
    int h = Hash(key);
    for (list<int>::iterator iter = data[h].begin(); iter != data[h].end(); ++iter) {
      if ((*iter) == key) {
        return;
      }
    }
    data[h].push_back(key);
  }

  void remove(int key) {
    int h = Hash(key);
    for (list<int>::iterator iter = data[h].begin(); iter != data[h].end(); ++iter) {
      if ((*iter) == key) {
        data[h].erase(iter);
        return;
      }
    }
  }

  bool contains(int key) {
    int h = Hash(key);
    for (auto iter = data[h].begin(); iter != data[h].end(); ++iter) {
      if ((*iter) == key) {
        return true;
      }
    }
    return false;
  }


private:
  static const int kBase = 769; // 用质数

  static int Hash(int key) {
    return key % kBase;
  }

private:
  vector<list<int>> data;
};
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int serverNum;  // ���Բɹ��ķ�������������
  string serverType, cpuCores, memorySize, serverCost, powerCost;
  scanf("%d", &serverNum);
  cin >> serverType >> cpuCores >> memorySize >> serverCost >> powerCost;
  cout << endl << endl;
  cout << serverNum << endl;
  cout << serverType << endl;
  cout << cpuCores << endl;
  cout << memorySize << endl;
  cout << serverCost << endl;
  cout << powerCost << endl;
  getchar();
  return 0;
}
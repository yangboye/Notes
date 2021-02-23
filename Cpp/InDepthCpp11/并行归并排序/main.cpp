//#include <iostream>
//#include <iterator>
//#include <thread>
//#include <algorithm>
//#include <chrono>
//#include <atomic>
//
//const int n = 10000000; // 排序数量
//const int max_n = 50000100; 
//std::atomic<int> CPU = 8; // 最大线程数
//
//int a[max_n];
//int b[max_n];
//int c[max_n];
//
//void Merge(int l, int r) {
//  int mid = (l + r) / 2;
//  int p = l, p1 = l, p2 = mid + 1;
//  while (p1 <= mid && p2 <= r)
//    b[p++] = a[p1] < a[p2] ? a[p1++] : a[p2++];
//  while (p1 <= mid)
//    b[p++] = a[p1++];
//  while (p2 <= r)
//    b[p++] = a[p2++];
//  for (int i = l; i <= r; i++)
//    a[i] = b[i];
//}
//
//void MergeSort(int l, int r) {
//  if (l >= r)
//    return;
//  int mid = (l + r) / 2;
//  MergeSort(l, mid);
//  MergeSort(mid + 1, r);
//  Merge(l, r);
//}
//
//void ParallelMergeSort(int l, int r) {
//  if (l >= r)
//    return;
//
//  int mid = (l + r) / 2;
//
//  std::thread LeftThread;
//  std::thread RightThread;
//
//  if (CPU > 0) {
//    CPU--;
//    LeftThread = std::thread(ParallelMergeSort, l, mid);
//  } else MergeSort(l, mid);
//  if (CPU > 0) {
//    CPU--;
//    RightThread = std::thread(ParallelMergeSort, mid + 1, r);
//  } else MergeSort(mid + 1, r);
//
//  if (LeftThread.joinable()) LeftThread.join();
//  if (RightThread.joinable()) RightThread.join();
//  Merge(l, r);
//  CPU++;
//}
//
//int main() {
//  clock_t start_time;
//  clock_t end_time;
//  int print_n = std::max(50, n);
//
//  for (int i = 1; i <= n; ++i) {
//    *(a + i) = rand();
//  }
//  std::copy(std::begin(a), std::begin(a) + print_n, std::ostream_iterator<int>(std::cout, " "));  // 打印前50个看看是否有序
//  std::cout << std::endl;
//
//
//  std::copy(std::begin(a), std::end(a), std::begin(c)); // 将a拷贝到c
//
//  start_time = clock();
//  MergeSort(1, n);
//  end_time = clock();
//  std::cout << "The run time of MergeSort: " << double(end_time - start_time) << "ms" << std::endl;
//  
//  std::copy(std::begin(a), std::begin(a) + print_n, std::ostream_iterator<int>(std::cout, " "));  // 打印前50个看看是否有序
//  std::cout << std::endl;
//
//  std::copy(std::begin(c), std::end(c), std::begin(a)); // 将c拷贝到a
//  start_time = clock();
//  ParallelMergeSort(1, n);
//  end_time = clock();
//  std::cout << "The run time of ParallelMergeSort: " << double(end_time - start_time) << "ms" << std::endl;
//  std::copy(std::begin(a), std::begin(a) + print_n, std::ostream_iterator<int>(std::cout, " "));  // 打印前50个看看是否有序
//  std::cout << std::endl;
//
//  return 0;
//}

#include <iostream>
#include <exception>

class A {
public:
  A() {
    std::cout << "In A()" << std::endl;
    throw std::exception();
  }

  ~A() {
    std::cout << "In ~A()" << std::endl;
  }

};

int main() {
  A a;
  return 0;
}
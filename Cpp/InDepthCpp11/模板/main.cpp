#include <iostream>
#include <typeinfo>
#include <type_traits>

using namespace std;

// 当T为integral类型的时候，返回类型为bool
template<typename T>
typename std::enable_if<std::is_integral<T>::value, bool>::type 
IsOdd(T i) {
  return bool(i % 2);
}

template<typename T,
         typename U = typename std::enable_if<std::is_integral<T>::value>::type>
bool IsEven(T i) {
  std::cout << typeid(U).name() << std::endl;
  return !bool(i % 2);
}

template<typename T, typename U>
int Inc(T a, U b) {
  return a + b;
}

int main() {
  short int i = 1;
  std::cout << std::boolalpha << std::endl;
  std::cout << "i is odd: " << IsOdd(1) << std::endl;
  std::cout << "i is even: " << IsEven(1) << std::endl;


  return 0;
}
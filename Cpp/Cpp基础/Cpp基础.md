# Cpp基础

# C++基础笔记
参考：[huihui/interview](https://github.com/huihut/interview/#license)
## 1. `const`的使用

## 2. C++面向对象特性
c++的OOP特性包括`封装`、`继承`、`多态`，[huihui/interview](https://github.com/huihut/interview/#license)中的那张图挺直观的，这里直接贴过来。其中最复杂的便是`多态`，所以接下来主要就讲讲多态。
![C++的OOP](https://img-blog.csdnimg.cn/20200731201456256.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM0NDAwMjMy,size_16,color_FFFFFF,t_70)
### 2.1 封装
靠`public`、`protected`、`private`这三个来控制成员的访问权限来达到封装的特性。
- `public`成员：可以被`任意实体`访问；
- `protected`成员：只允许`本类`和`子类`的成员函数访问；
- `private`成员：只允许`本类的成员函数`、`友元类`、`友元函数`访问。

### 2.2 继承
根据权限控制，继承也可分为三种继承：公有(public)继承、保护(protected)继承、私有(private)继承。成员函数以及成员变量的属性会因继承的方式而改变。
- `public继承`: 不变；
- `protected继承`：父类中的`public`成员都变成`protected`，其他不变；
- `private继承`：父类中的`public`和`protected`都变成`private`，其他不变。

### 2.3 多态
多态分类及实现：
- 重载多态（编译期）：函数重载、运算符重载；
-  子类型多态（运行期）：虚函数；
-  参数多态（编译期）：类模板、函数模板；
-  强制多态（编译器/运行期）：基本类型转换、自定义类型转换。

#### 2.3.1 重载
这里要先区分三个概念：`重载（overload）`、`重写(override)`和`重定义(redefining)`。
 - **重载(overload):** 函数名相同，参数列表不同，但不能靠返回类型来判断。
```c++
int func() {}			// 原函数 
void func() {}			// Error，不能靠返回类型来判断
int func() const {}		// OK，const相当于修饰this，相当于形参不同
const int func() {}		// Error，const int 返回类型还是一样的
```

 - **重写(override)：** 
	-  被重写的函数不能是static，必须是virtual；
	-  重写函数必须有相同的类型，名称和参数列表；
	-  重写函数的访问修饰符可以不同，比如父类中的是private，但是子类中可以重写为public。

#### 2.3.2 虚函数
这里有几点要注意的：
（1） 普通函数（非类成员函数）不能是虚函数；
（2） 静态函数（static）不能是虚函数；
（3）构造函数不能是虚函数（在调用构造函数时，虚表指针并没有在对象的内存空间中，必须要构造函数调用完成后才会形成虚表指针）；
（4） 内联函数不能是表现多态性时的虚函数。
```c++
virtual void func() {}		// Error，普通函数不能是虚函数

class Base
{
public:
	//virtual static void func() {}		// Error, 静态函数不能是虚函数
};
```
下面来看个具体的例子来看看多态：
```c++
class Base	// 父类
{
public:
	Base() { cout << "Base()" << endl; }
	virtual ~Base() { cout << "~Base()" << endl; }
	void fun() { cout << "Base::fun()" << endl; }
};

class Derived : public Base		// 子类
{
public:
	Derived() { cout << "Derived()" << endl; }
	~Derived() { cout << "~Derived()" << endl; }
	void fun() { cout << "Derived::fun()" << endl; }
};

int main()
{
	Base* ptr = new Derived();
	ptr->fun();
	delete ptr;
	ptr = nullptr;
	return 0;
}
```
运行结果：
![虚函数运行结果1](https://img-blog.csdnimg.cn/202007312134175.png)
如果将`Base::fun()`变成虚函数，也就是
```c++
class Base
{...
	virtual void fun() { cout << "Base::fun()" << endl; }
...
};
```
运行结果如下
![虚函数运行结果2](https://img-blog.csdnimg.cn/20200731213749817.png)
#### 2.3.3 虚析构函数
虚析构函数是为了解决基类的指针指向派生类对象，并用基类的指针删除派生类对象。（理解成解决内存泄漏的问题就行了）。
如果将上面的`Base`的析构函数改成普通的，运行结果会怎样呢？

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200731214718312.png)
看到没有看到没有，这样子类`Derived`就没有被释放掉！！！
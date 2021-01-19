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



## 3. 困惑的问题

### 3.1 `sizeof()`和`strlen()`

在学Linux服务器端编程的时候，总是被`sizeof(buf)`、`sizeof(buf)-1`、`strlen(buf)`、`strlen(buf)+1`搞晕，在这里总结一下。

因为`strlen()`是一个函数，参数只能是`char*`类型，而`sizeof()`是一个单目运算符，它的参数可以是数组、指针、类型、对象、函数等等，所以这里分两种情况分别说：第一种是字符串情况下，strlen()和sizeof()都可以用；第二种情况是其他类型下，只能用sizeof()。

#### 3.1.1 字符串情况下（char *）

API: `size_t strlen(char const* str);`，头文件`string.h`

功能：计算指定字符串str的长度，不包括结束字符`\0`。

```c++
#include <stdio.h>
#include <string.h>

int main()
{
    /*字符串中, sizeof()和strlen()的区别*/
    char ch[10];
	printf("sizeof(ch)=%d, strlen(ch)=%d\n", sizeof(ch), strlen(ch));	// 10, 1067(这个值可能不一样)
	memset(ch, '\0', sizeof(ch));	// 将起始地址ch开始的sizeof(ch)个bytes都设置为`\0`
	printf("sizeof(ch)=%d, strlen(ch)=%d\n", sizeof(ch), strlen(ch));	// 10， 0
	ch[0] = 'a';	// 将ch的第0个字符设置为'a'
	ch[2] = 'c';	// 将ch的第2个字符设置为'c'
	printf("ch=%s, sizeof(ch)=%d, strlen(ch)=%d\n", ch, sizeof(ch), strlen(ch));	// 10， 1 （？？？）
	printf("\n");
    
    /*char a[]和char *a的区别*/
    const char a[] = "hello";
	printf("a=%s, sizeof(a)=%d, strlen(a)=%d\n", a, sizeof(a), strlen(a));	// 6, 5
	const char *a2 = "hello";
	printf("a2=%s, sizeof(a2)=%d, strlen(a2)=%d\n", a2, sizeof(a2), strlen(a2));	// 4, 5 （？？？）
	printf("\n");
    
    return 0;
}
```

（1）第`8`行中，`sizeof(ch)=10`表示ch占用了10个bytes，而`strlen(ch)=1067`则表示的是从起始地址ch开始，第1068个byte才是`\0`（这个结果可能会不一样，因为它越界了嘛）；

（2）第`10`行中，`sizeof(ch)`还是等于10，说明不管ch里放的是啥，sizeof计算的都是它所占空间的bytes，而`strlen(ch)=0`，再结合11~13行，设置后的内容应该是"**a**\0**c**\0\0..."，但是strlen的结果却是**1**，说明strlen()计算的是**字符串中第一个`\0`之前的字符个数**；

（3）第`18`行中，`sizeof(a)=6`，包括了结束符`\0`（也就是说sizeof计算的是"hello\0"这样一个字符串）;

（4）第`20`行中，`sizeof(a2)`为啥会是**4**嘞？？？这就涉及到了`char a[]`和`char *a`的区别了。这个待会再讲。



### 3.1.2 其他情况下（只有`sizeof()`）

对于一般的类型，比如sizeof(int)、sizeof(char)这些，计算出来的都是该类型占用的bytes：

```c++
int x;
printf("sizeof(int)=%d, sizeof(x)=%d\n", sizeof(int), sizeof(x));	// 4, 4
```

代表int类型（变量）占用4个bytes，这个跟操作系统（编译器？）有关。

除此之外，问得最多的还是类/结构体的长度了，也就是内存对齐的问题，[可以参考这篇博客https://www.cnblogs.com/dingxiaoqiang/p/8059329.html](https://www.cnblogs.com/dingxiaoqiang/p/8059329.html)



### 3.1.3 使用`memset（）初始化`

API: `void* memset(void *buff, int c, int count); `

功能：将起始地址buff开始的count个bytes都设置为c。

```c++
#include <stdio.h>
#include <string.h>

int main()
{
    char buf[1024];
	printf("sizeof(buf)=%d, strlen(buf)=%d\n", sizeof(buf), strlen(buf));	// 1024, 1183(可能会不同)
	memset(buf, '\0', sizeof(buf));
	printf("sizeof(buf)=%d, strlen(buf)=%d\n", sizeof(buf), strlen(buf));	// 1024, 0
	memset(buf, 'a', sizeof(buf)-1);	// 用的时候只能用 1024-1=1023个，因为最后一个要用作存结束标识符 `\0`
    // memset(buf, 'a', sizeof(buf)-1);	// 你可以试试这句，输出会有在后面有很多烫烫烫烫~~~
	printf("%s\n", buf);
	printf("sizeof(buf)=%d, strlen(buf)=%d\n", sizeof(buf), strlen(buf));	// 1024, 1023
	printf("\n");
    return 0;
}
```

特别注意的是，`memset`是将每一个byte都设置为`c`，那你算算下面的执行结果是多少：

```c++
int x;
printf("sizeof(x)=%d\n", sizeof(x));	// 4
memset(&x, 1, sizeof(x));
printf("%d\n", x);
```

结果是`16843009`。怎么来的呢？让我们看看：

由第`2`行可以知道，x占用了4个bytes空间，也就是4×8=32bit，每一个byte都设置为1，即

> 0000 0001 0000 0001 0000 0001 0000 0001

算一算，2^24 + 2^16 + 2^8 + 2^0 = 16843009.

<hr>

> 课代表：
>
> （1）`strlen()`是用来计算字符串长度的，不包括结束字符`\0`(也就是第一个`\0`之前字符的个数)；
>
> （2）在Linux网络编程中，可以理解为sizeof(buf) = strlen(buf)+1(最后一位不存数据，只用来存放结束标志`\0`)，所以初始化/重置用sizeof(buf)，读写用sizeof(buf)-1。

### 3.2 BitMap(位图)

参考：[C++实现BitMap数据结构](https://blog.csdn.net/yanerhao/article/details/72848524)

Linux服务器编程中IO复用的`select`涉及到了位图的概念，在这里做个了解。

- 概念：位图就是用一个bit来标记某个元素对应的value，而key就是该元素，你可以把它想象成bool的一个数组，只不过这个数组的每一个bit表示一个元素，粒度更小了，所以就更省空间了呀。

- 一个用法：排序。详见[博客](https://blog.csdn.net/yanerhao/article/details/72848524)。

- 实现：关键就是找下标咯，`x>>3`(等价于x/8)，判断在哪个byte上，`x&(7)`(等价于x%8)，判断在某个byte上的哪个bit上。
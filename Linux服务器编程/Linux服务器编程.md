# Linux服务器编程

参考：

	- 《Linux高性能服务器编程》，游双 著.

## 0. Linux编程基础

- **主机字节序和网络字节序**

> `大端字节序（big endian）`：一个整数的高位字节（23~31bit）存储在内存的低地址处，低位字节（0~7bit）存储在内存的高位地址处。
>
> `小端字节序（little endian）`：与大端字节序相反。

![大小端](.\img\大小端.png)

下面用`c++`来实现一下大小端的判断：

```c++
void byte_order() {
	union
	{
		short value;
		char union_bytes[sizeof(short)];
	}test;

	test.value = 0x0102;
	if ((1 == test.union_bytes[0]) && (2 == test.union_bytes[1])) { // 对应上图左边
		printf("Big endian\n");
	}
	else if ((2 == test.union_bytes[0]) && (1 == test.union_bytes[1])) { // 对应上图右边
		printf("Little endian\n");
	}
	else {
		printf("Unknown...\n");
	}
}
```

现代PC大多采用`小端字节序`，所以小端字节序也叫做`主机字节序`。当格式化的数据在两台使用不同字节序的主机上直接传递时，接收端必然会出错，解决方法是：发送端总是把要发送的数据转化成<u>大端字节序</u>数据后再发送。所以`大端字节序`也称之为`网络字节序`。

> 课代表：
>
> （1） 小端字节序 <==> 主机字节序；
>
> （2） 大端字节序 <==> 网络字节序。

为啥要介绍这个呢？当然是要引入下面的函数呀~~

```c++
// 主机字节序 和 网络字节序 之间的转换函数
#include <netinet/in.h>
unsigned long int htonl(unsigned long int hostlong);	// 看名字: host to network long
unsigned short int htons(unsigned short int hostshort);
unsigned long int ntohl(unsigned long int netlong);
unsigned short int ntohs(unsigned short int netshort);
```


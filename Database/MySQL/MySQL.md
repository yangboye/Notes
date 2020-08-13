# MySQL

## 0. 安装中遇到的问题

- **Ubuntu上安装：**

  ```bash
  sudo apt-get install mysql-server          //服务端
  sudo apt-get install mysql-client          //客户端
  sudo apt-get install libmysqlclient-dev    //程序编译时链接的库
  ```

有的说安装的时候会提示设置密码什么的，但是我的没有，所以安装后就出问题了，`sudo mysql -u root -p `提示输入密码总是失败，解决方法：`sudo vi /etc/mysql/mysql.conf.d/mysqld.cnf`，加上一句

![image-20200813214410195](D:\NLP\Notes\Database\MySQL\img\mysql密码错误.png)

保存更改之后再重新`sudo mysql -u root -p`，这样就不用输入密码了，进入之后更改`root`的密码：

```bash
use mysql;
update mysql.user set authentication_string=password('root') where user='root' and Host ='localhost';
update user set plugin="mysql_native_password"; 
flush privileges;
quit;
```

再重新启动mysql：`sudo service mysql restart`，ok。

- **常用命令：**
  - 启动：`sudo service mysql start`
  - 关闭：`sudo service mysql stop`
  - 重启：`sudo service mysql restart`

- **添加用户&分配权限：**

  - 添加用户：

    ```bash
    # 允许本地访问的用户(127.0.0.1)
    create user username@localhost identified by '123456'
    # 允许外网IP访问的用户（这里需要在`/etc/mysql/mysql.conf.d/mysqld.cnf`中注释bind-address=127.0.0.1)
    create user 'username'@'%' identified by '123456'; 
    ```

  - 用户权限分陪：

    ```bash
    # 授予用户在本地服务器对该数据库的全部权限
    grant all privileges on dbname.* to username@localhost identified by '123456';
    # 授予用户通过外网IP对于该数据库的全部权限
    grant all privileges on dbname.* to 'username'@'%' identified by '123456';  
    
    # 刷新权限
    flush privileges;  
    ```

  参考：

   - [MySQL添加用户、为用户分配权限](https://blog.csdn.net/qq_31759205/article/details/80575540)

   - [MySQL远程连接](https://blog.csdn.net/mr_hui_/article/details/88878836)

   - [查看MYSQL数据库中所有用户及拥有权限](https://blog.51cto.com/08jw3/1273075)

     




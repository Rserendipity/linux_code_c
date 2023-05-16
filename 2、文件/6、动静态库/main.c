#include <stdio.h>
#include "add.h"
#include "sub.h"

void staticFunc(int a, int b)
{
    /* 生成自己的静态库：
            gcc -c [编译文件]
            生成同名的 .o 二进制可连接文件
            ar -rc [二进制文件] [生成库文件] [所有的参与打包的文件]
            将所有的参与打包的文件，生成库文件
            库文件的格式：libXXX.a
            去掉前缀lib，去掉后缀.a，才是库的真正的名字，并且格式必须是这样的
    */
    printf("%d + %d = %d\n", a, b, add(a, b));
    printf("%d - %d = %d\n", a, b, sub(a, b));

    /* 连接静态库：
            编译时，连接静态库：
            gcc [参与编译的源文件] -L. -lmymath
            -L   指定库的路径
            -l   指定库的名称，需要去掉库的前缀以及后缀
    */
}

void sharedFunc(int a, int b)
{
    /* 生成自己的动态库：
            gcc -c -fPIC [编译文件]
            生成同名的 .o 二进制可连接文件
            -fPIC 生成位置无关码，用于动态库的连接

            gcc -shared -o libmymath.so
            -shared  指定生成动态库
    */
    printf("%d + %d = %d\n", a, b, add(a, b));
    printf("%d - %d = %d\n", a, b, sub(a, b));

    /* 连接动态库：
            编译时，连接动态库：
            gcc [参与编译的源文件] -L. -lmymath
            -L   指定库的路径
            -l   指定库的名称，需要去掉库的前缀以及后缀

            动态库是运行程序时加载到程序当中的，并且不会默认连接第三方的动态库
            所以，在运行程序的时候，必须把动态库添加到环境变量 或者 把库生成一个软连接，放在标准库文件夹，以供程序搜索
            1、export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./           添加环境变量
            2、ln -s [动态库文件路径] /lib64                           添加到系统的标准库
            这里的文件路径需要是绝对路径
    */
}

int main()
{
    // staticFunc(10, 20);
    sharedFunc(10, 20);
    return 0;
}
/*
    静态区：
        程序编译和链接的时候已经被加载,如果程序中有static修饰的变量，或全局变量，这时候已经分配内存
        代码段:
        只读数据段（被const修饰的全局变量，字符串）:全局已初始化变量在.data段，全局未初始化在.bss段
        
    动态区：
        堆: 手动申请/释放，malloc,calloc,relloc/free
        栈:随用随释放，出来代码块就被销毁
        内核（kernel)

*/

#include <iostream>

using namespace std;

void test()
{
    /*
        //const int a; 错误 a必须初始化
        const int a = 100; 局部变量，当一个基本变量被const修饰并赋值，编译器会在内存中建立一个常量表
        此时，a的值保存在常量表中，当a再次被访问，编译器会从常量表中取值

        int b =100;  
        但是const int a = b;  //此时a不会进常量表
    */
    const int a = 100;  //非常特殊的情况：
    int *p = (int *)&a;
    *p = 300;           //编译器会从常量表中取值，无法修改a的值；
}


const int c = 30;

int main(void)
{
    int a = 10;
    const int b = 20; //常量
    cout << &a << endl;

    int const c = 2;  //const在前和在后意义不同

}
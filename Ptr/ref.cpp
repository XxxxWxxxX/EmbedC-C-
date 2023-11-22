
/*
    引用就是指针
    引用就是const修饰的指针，指向固定的内存空间，引用在函数调用时不可修改，
*/
#include <iostream>

using namespace std;

int add1(int& a,int& b)  //引用
{
    return a + b;
}

int add2(int* a,int* b) //指针
{
    return *a + *b;
}

// int swap(int a,int b)  //局部变量实现不了交换
// {
//     int temp = a;
//     a = b;
//     b = temp;
// }

//  swap(b,a);  //c++会将传递的值隐式转为指针
// void swap(int* a,int* b)  //
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

int swap(int& a,int& b)  //引用
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 100;
    int b = 200;
    int * p = &a;  //地址就是指针

    cout << *p << endl;

    *p = 88;

    cout << a << endl;

    //int const pa = &a; 引用的底层实现
    int& c = a;  //b是a的引用，引用b是a的别名；

   // cout << add1(b,c) << endl;  //参数是引用

    //cout << add2(&a,&b) << endl;  //参数是地址（指针）

    swap(b,a);  //c++会将传递的值隐式转为指针
    
    cout << "b:" << b << endl;
    cout << "a:" << a << endl;

    return 0;
}

#include <iostream>

using namespace std;

//函数模板
//template <class T>      //函数模板，形式1
template <typename T>      //函数模板，形式2
T add_func(T a,T b)
{
    return a + b;
}

//类模板，调用时指定类型
template <class T1,class T2,class T3>  //模板中参数数量不定
class A   //类生成器
{
    T1 t1;
    T2 t2;
    T3 t3;

public:
    void show(T1 t1,T2 t2)
    {
        cout << t1 << "\n" << t2 << endl;
    }
};

//类模板继承
//子类和父类都必须是模板，父类必须指定类型
template <class T1,class T2,class T3,class T4>  //先声明父类用到的类型
class B :
    public A<T1,T2,T3>  //继承时父类要指定类型，否则不知道继承的是哪个，即未定义
{

public :
    void showInfo(T1 t1,T4 t4)
    {
        cout << t1 << "\n" << t4 << endl;
    }

};

int main()
{

    //函数模板
    // int a = 10; 
    // int b = 2;  

    // float c = 2.7;
    // float d = 3.56;
    // cout << add_func<int>(a,b) << endl;
    // cout << add_func<float>(c,d) << endl;

    //类模板
    //A<int,float,char>(22,33.55,"A") a;  //错误使用
    // A<int,float,char> a;   //类模板使用必须指定类型,显式指定
    // a.show(22,3.25);

    //类模板继承
    B<int,float,char,double> b;
    b.showInfo(1,333.4);

    return 0;
}

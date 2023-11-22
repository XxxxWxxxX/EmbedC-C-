/*
    Static 静态成员函数只能访问静态成员变量
    修饰函数,在类内存在，只要这个类存在就无需定义对象，直接调用修饰的函数
    static int getAmount()   //本文件的全局函数，仅属于本文件，且不可被extern 引用

*/

#include <iostream>

using namespace std;

class Student
{
private:
    /* data */
    int age;
    string  name;

    static int amount;
public:
    Student(/* args */)
    {
        cout << "无参构造" << endl;
    }

    ~Student()
    {
        
        cout << "析构" << endl;    
    }

    Student(string name,int age )
    {
        this -> name = name;    
        this -> age = age;

    }

    void show()
    {
        cout << "年龄：" << this-> age << '\n' 
             << "姓名：" << this -> name << endl;
    }

    static int getAmount()   //本文件的全局函数，仅属于本文件，且不可被extern 引用
    {
        return amount;          //Static 静态成员函数只能访问静态成员变量
    }

};

int Student::amount = 100 ;   //类中声明，类外定义
int main(void)
{
    // Student(xxx,28) stu;
    //Student stu("Xxx",28)；  //类定义

    cout << Student::getAmount() << endl;  //static修饰的函数，可以不定义对象就能被引用


    return 0;
}
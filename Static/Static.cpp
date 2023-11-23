/*
    Static 静态成员函数只能访问静态成员变量
    静态函数,在类内存在，只要这个类存在就无需定义对象，直接调用修饰的函数
    static int getAmount()   //本文件的全局函数，仅属于本文件，且不可被extern 引用
    1.其他文件内可以定义同名文件；
    2.不被其他文件引用；
    3.不创建对象也可以调用；
    3.静态函数是全局的，不依赖类对象，没this指针，不能调用类中属性（变量）
*/

#include <iostream>

using namespace std;

class Student
{
private:
    /* data */
    int age;
    string  name;

    static int amount;  //static修饰变量类中声明，类外定义
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

    static int getAmount()   //静态函数本文件的全局函数，仅属于本文件，且不可被extern 引用
    {
        return amount;          //Static 静态成员函数只能访问静态成员变量
    }

    int getAmount2()
    {
        return amount; 
    }

};

int Student::amount = 100 ;   //static修饰变量类中声明，类外定义
int main(void)
{
    cout << Student::getAmount() << endl;  //static修饰的函数，可以不定义对象就能被引用

    Student stu("Xxx",28);
    cout << stu.getAmount2() << endl;       //普通函数调用静态变量必须依赖对象

    return 0;
}
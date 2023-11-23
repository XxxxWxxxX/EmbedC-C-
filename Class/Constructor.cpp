/*
    编译器提供：
        无参构造函数
        析构函数
        拷贝构造函数(浅拷贝仅赋值属性（无指针），深拷贝（有指针）)：如果写了拷贝构造，与默认构造会产生重载关系，编译器不提供默认无参构造，
            默认的拷贝构造形式：
                Stu(Stu& stu)
                {
                    把每一个变量拷贝赋值一份
                    this -> age = stu.age;
                    this -> name = stu.name;
                }

            调用形式：
                Stu p1 = p;
                Stu p1(p);           定义的对象需要另一个对象来初始化调用拷贝构造

                函数传值==拷贝，传址 == 引用（指针）

                void fun(Stu stu1);  函数参数是对象，调用拷贝构造
                Stu fun2(Stu stu2);  函数返回是对象时，但是调用拷贝构造会多开辟一份空间，所以最后使用引用（性能低）
                    Stu& comp(Stu& stu1,Stu& stu2)  引用即指针，固定的同一个空间，不会再拷贝一份

        赋值运算符重载函数
*/

#include <iostream>
#include <cstring>

using namespace std;

class Student
{
private:
    /* data */
    int age;
    string  name;
    char *p;         //有指针要深拷贝，无指针就是浅拷贝（拷贝赋值）

public:
    Student(/* args */)   //有拷贝构造，编译器就不提供默认构造
    {
        cout << "无参构造" << endl;
    }

    ~Student()
    {
        if (p != nullptr) 
        {
            delete p;  // 释放指针 p 的内存空间
        }
        cout << "析构" << endl;    
    }

    Student(string name,int age )
    {
        this -> name = name;    //1.区分类中属性（变量名）
        this -> age = age;
        this ->p =  new char[5];   //构造要初始化属性,每一个对象都开辟了一个堆区的空间
    }

    //默认的拷贝构造实现
    Student(Student& stu)
    {
        this -> age = stu.age;
        this -> name = stu.name;
        cout << "---拷贝构造---" << endl;

        //有指针的话需要改造浅拷贝
        
        this ->p =new char[5];          //深拷贝，需要在堆中开辟新的内存，使用memcpy拷贝到新空间，性能低
        memcpy(this->p,stu.p,sizeof(char)*5);
    }

    //调用拷贝构造
    //当函数返回是对象时，但是调用拷贝构造会多开辟一份空间，所以最后使用引用（性能低）
    Student& setName1(string name)  //TODO & 引用即指针（实际意义），被const修饰后的指针
    {
        this -> name = name;
        return *this;           //2.返回本对象
    }

    string setName2(string name)  
    {
       
        return  this -> name = name;           
    }

    void showThis()    //起始地址与类一致
    {
        cout <<  this << endl;
    }

        void show()
    {
        cout << "年龄：" << this-> age << '\n' << "姓名：" << this -> name << endl;
    }

    int getage()
    {
        return this ->age;
    }

    string getname()
    {
        return this ->name;
    }
    
};

//函数返回值是对象，调用拷贝构造
Student compare(Student stu1,Student stu2)
{
    return stu1.getage() > stu2.getage() ? stu1 :stu2;
}

//转换为引用，不会申请空间
// Student& compare(Student& stu1,Student& stu2)
// {
//     return stu1.getage() > stu2.getage() ? stu1 :stu2;
// }

int main(void)
{
    // Student(xxx,28) stu;
    Student stu("Xxx",28);
    // Student stu2 = stu;  //拷贝构造，当定义的对象需要另一个对象来初始化
    // Student stu3(stu2);  //拷贝构造
    // stu2.show();
    // stu.show();

    Student stu2("Www",29);

    cout << "大" << "\n" << compare(stu,stu2).getname() << endl; //为啥调用3次拷贝构造？2次参数，1次返回值

    cout << &stu << endl;   //查看类的起始地址

    return 0;
}
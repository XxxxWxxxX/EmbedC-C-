/*
    this指针保存的就是本对象的地址,起始地址一致
    1.区分类中属性；
    2.返回本对象；
    3.不占用类空间大小
    4.static 静态成员函数没有this指针，动态区先产生对象 -> 编译器分配this指针;
    而静态成员程序开始前已经存在，
    
    普通函数隐含了一个this指针
    stu.showThis();   //stu.showThis(&stu)  普通成员函数其实隐含了this指针

*/

#include <iostream>

using namespace std;

class Student
{
private:
    /* data */
    int age;
    string  name;

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
        this -> name = name;    //1.区分类中属性（变量名）
        this -> age = age;

    }

    void show()
    {
        cout << "年龄：" << this-> age << '\n' << "姓名：" << this -> name << endl;
    }

    Student & setName1(string name)  //TODO & 引用，
    {
        this -> name = name;
        return *this;           //2.返回本对象
    }

    string setName2(string name)  //
    {
       
        return  this -> name = name;           
    }

    void showThis()    //起始地址与类一致
    {
        cout <<  this << endl;
    }
    
};

int main(void)
{
    // Student(xxx,28) stu;
    Student stu("Xxx",28);
    stu.showThis();   //stu.showThis(&stu)  普通成员函数其实隐含了this指针

    // Student set1 = stu.setName1("Www");
    // set1.show();

    // Student Set2("Xww",29);
    // Set2.setName2("XxxWww");
    // Set2.show();

    cout << &stu << endl;   //本对象的起始地址一致



    return 0;
}
#include <iostream>
#include <memory>  //智能指针包含的头

using namespace std;

class A
{
private:
    /* data */
    int Id;
public:
    A(int id):Id(id)
    {
        cout << "构造" << endl;
    }
    ~A()
    {
         cout << "析构" << endl;
    }

    void show()
    {
        cout << this ->Id << endl;
    }
};

//实现智能指针auto_ptr
template <class T>
class AutoPtr
{
private:
    /* data */
    T* p;
public:
    AutoPtr(T* _p):p(_p)   //初始化要加“：”
    {

    }
    ~AutoPtr()
    {
        delete p;
    }

    T* get()
    {
        return this->p;
    }

    AutoPtr(AutoPtr& autoptr)   //TODO 拷贝构造
    {
        this ->p = autoptr.p;
        autoptr.p = nullptr;
    }

};

template <class T>
class SharePtr
{
private:
    /* data */
    T* p;
    static int count;  //静态区
public:
    SharePtr(T* _ptr):p(_ptr)   //变量初始化要加“：”
    {

    }
    ~SharePtr()
    {
       if(count == 0)
       {
        delete p;
       }
       else
       {
        count--;
       }
    }

    SharePtr(SharePtr& ptr)
    {
        p = ptr.p;
        count++;
        cout << "拷贝构造" << endl;
    }

    T* get()
    {
        return p;
    }
};


template<class T>
int SharePtr<T>::count  = 0; //static修饰变量类中声明，类外定义

int main(void)
{
    // A a(20);
    // a.show();

    // A* ptr = new A(30);  //new开辟类A的空间
    
    // ptr->show();

    // delete ptr;  //开辟空间但是，这部分会经常忘记，因此引入智能指针

    //shared_ptr<A> a(28);
    // shared_ptr<A> ptr(new A(28));  //生成一个A类型的智能指针，指向new开辟的内存空间（堆区）
    // ptr.get()->show();

    // AutoPtr<A> p(new A(30));
    // p.get()->show();

    SharePtr<A> ptr(new A(28));
    ptr.get() ->show();
    SharePtr<A> ptr2(ptr);
    ptr2.get()->show();
    ptr.get()->show();



    return 0;

}
#include <iostream>
#include <memory>

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


int main(void)
{
    // A a(20);
    // a.show();

    // A* ptr = new A(30);  //开辟类A的空间
    
    // ptr->show();

    // delete ptr;  //这部分会经常忘记





    return 0;

}
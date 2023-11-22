#ifndef MY_STACK_H
#define MY_STACK_H

using namespace std;

template <typename T>  //模板关键字
class My_Stack
{
private:
    /* data */
    int capcity;
    int size;
    T* data;

public:
    My_Stack(int c = 10);  //有参构造，
    ~My_Stack();

    bool push(T t);
    bool pop();
    T top();
    bool empty();

};

template <typename T>
My_Stack<T>::My_Stack(int c):size(0),capcity(c)  //需要添加 <T>
{
    data = new T[c];  //申请空间
}

template <typename T>
My_Stack<T>::~My_Stack()
{
    delete []data;  //数组删除
}

template <typename T>
bool My_Stack<T>::push(T t)  //入栈
{
    if(size > capcity)
    {
        return false;
    }

    data[size] = t;
    size++;
    return true;
}

template<typename T>
bool My_Stack<T>::pop()
{
    if(size == 0)
    {
        return false;
    }

    size--;
    return true;
}

template<typename T>
T My_Stack<T>::top()
{
    if(size > 0)
    {
        T temp = data[size - 1];
        return temp;
    }
}

template<typename T>
bool My_Stack<T>::empty()
{
    if(size == 0)
        return true;
    return false;
}

#endif
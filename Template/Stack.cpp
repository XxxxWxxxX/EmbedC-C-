/*
    栈：LIFO,后入先出
    栈顶：size-1
    栈底：0
    
    |__| <-size -1
    |__|
    |__|
    |__| <-0
*/
#include "Stack.h"
#include <iostream>

int main(void)
{
    My_Stack<int> stack;
    //入栈
    stack.push(2);
    stack.push(4);
    stack.push(29);

    for(int i = 0 ; !stack.empty();i++) 
    {
        cout << stack.top() << endl;
        stack.pop();  //出栈
    }

    return 0;
}



#include "Stack.h"
#include <iostream>

int main(void)
{
    My_Stack<int> stack;
    stack.push(2);
    stack.push(4);
    stack.push(29);

    for(int i = 0 ; !stack.empty();i++) 
    {
        cout << stack.top() << endl;
        stack.pop();
    }

    return 0;
}



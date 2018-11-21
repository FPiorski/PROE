#include <iostream>
#include "class.h"

int main()
{
    Stack s1(5), s2;
    for (int i=0; !s1.isFull(); ++i)
        s1.push(StackElement(i, 0));
    while (!s1.isEmpty())
        std::cout << s1.pop().getInt() << '\n';
    for (int i=0; !s2.isFull(); ++i)
        s2.push(StackElement(1, (double) i));
    while (!s2.isEmpty())
        std::cout << s2.pop().getDouble() << '\n';
    return 0;
}

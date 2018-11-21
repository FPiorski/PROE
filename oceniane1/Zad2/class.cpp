#include <string>
#include <stdexcept>
#include "class.h"

Stack::Stack(int sz)
{
    sz_ = sz;
    pos_ = 0;
    data_ = new StackElement [sz_];
}

void Stack::push(const StackElement& el)
{
    if (isFull())
        throw std::runtime_error("stack overflow");
    data_[pos_++] = el;
}

StackElement Stack::pop()
{
    if (isEmpty())
        throw std::runtime_error("stack underflow");
    return data_[--pos_];
}

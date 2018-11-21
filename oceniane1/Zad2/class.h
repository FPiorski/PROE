#pragma once
class StackElement{
private:
    int first_;
    double second_;
public:
    StackElement(int i = 0, double d = 0) : first_(i), second_(d) {};
    int getInt() {return first_;};
    double getDouble() {return second_;};
};

class Stack{
private:
    int sz_, pos_;
    StackElement* data_;
public:
    Stack(int = 10);
    ~Stack() {delete [] data_;}
    void push(const StackElement&);
    StackElement pop();
    bool isFull() {return pos_ == sz_;};
    bool isEmpty() {return pos_ == 0;};
};

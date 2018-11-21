#include <iostream>
#include "complex.h"

void printComplex(const Complex &c)
{
    std::cout << "[" << c.getReal() << ", " << c.getImag() << "]\n";
}

int main()
{
    Complex c(5.4, 3.141592), d(c);
    c.setReal(333.3);
    c.setImag(444.4);
    Complex e(d+d), f(e+d);
    ComplexSum s;
    s.push_back(c);
    s.push_back(d);
    s.push_back(e);
    s.push_back(f);
    ComplexSum s2(s);
    s2.push_back(Complex(-365.0, +536.75));
    printComplex(s.sum());
    printComplex(s2.sum());

    return 0;
}

#include <stdexcept>
#include "complex.h"

ComplexSum::ComplexSum(int sz) : order(sz), pos(0)
{
    ar = new Complex [order];
}

ComplexSum::ComplexSum(const ComplexSum &c) : ComplexSum::ComplexSum(c.order)
{
    pos = c.pos;
    for (int i=0; i<pos; ++i){
        ar[i].setReal(c.ar[i].getReal());
        ar[i].setImag(c.ar[i].getImag());
    }
}

void ComplexSum::push_back(const Complex& c)
{
    if (pos == order)
        throw std::runtime_error("Out of memory");
    ar[pos].setReal(c.getReal());
    ar[pos++].setImag(c.getImag());
}

Complex ComplexSum::sum()
{
    double imag=0.0, real=0.0;
    for (int i=0; i<order; ++i){
        real += ar[i].getReal();
        imag += ar[i].getImag();
    }
    return Complex(real, imag);
}

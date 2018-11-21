#include <iostream>
#include "complex.h"

Complex::Complex(double r, double i) : real_(r), imag_(i)
{
    std::clog << "Two argument (or default) constructor\n";
};

Complex::Complex(const Complex& c) : real_(c.real_), imag_(c.imag_)
{
    std::clog << "Copy constructor\n";
};

Complex& Complex::operator=(const Complex& c) 
{
    std::clog << "Assignment operator (=)\n";
    if (this == &c)
        return *this;
    real_ = c.real_;
    imag_ = c.imag_;
    return *this;
}

Complex Complex::operator+(const Complex& c) const
{
    return Complex(real_ + c.real_, imag_ + c.imag_);
}

Complex Complex::operator*(const Complex& c) const
{
    return Complex(real_*c.real_ - imag_*c.imag_, real_*c.imag_ + imag_*c.real_);
}

Complex Complex::operator*(const int i) const
{
    return Complex(i*real_, i*imag_);
}

bool Complex::operator==(const Complex& c) const
{
    return (real_ == c.real_ && imag_ == c.imag_);
}

std::ostream& operator<<(std::ostream& out, const Complex& c)
{
    return out << '[' << c.real_ << ", " << c.imag_ << "]\n";
}

Complex operator*(const int i, const Complex& c)
{
    return Complex(i*c.real_, i*c.imag_);
}

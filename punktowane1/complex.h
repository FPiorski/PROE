#pragma once

class Complex
{
private:
    double real, imag;

public:
    Complex(double r=0.0, double i=0.0) : real(r), imag(i) {};
    Complex(const Complex &c) : real(c.real), imag(c.imag) {};
    Complex operator+(const Complex &c) const {return Complex(real + c.real, imag + c.imag);}
    double getReal() const {return real;}
    double getImag() const {return imag;}
    void setReal(const double r) {real = r;}
    void setImag(const double i) {imag = i;}
};

class ComplexSum
{
private:
    const int order;
    Complex *ar;
    int pos;

public:
    ComplexSum(int = 100);
    ComplexSum(const ComplexSum &c);
    ~ComplexSum() {delete [] ar;}
    void push_back(const Complex& c);
    Complex sum();
};

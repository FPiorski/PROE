#pragma once

class Complex
{
private:
    double real_, imag_;

public:
    Complex(double=0.0, double=0.0);
    Complex(const Complex&);
    Complex& operator=(const Complex&);
    Complex operator+(const Complex&) const;
    Complex operator*(const Complex&) const;
    Complex operator*(const int) const;
    bool operator==(const Complex&) const;
    friend std::ostream& operator<<(std::ostream&, const Complex&);
    friend Complex operator*(const int, const Complex&);
};

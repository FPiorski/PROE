#include <iostream>
#include "complex.h"

int main()
{
    Complex z(3,4);
    Complex z2(2*z2+Complex(-6.5,0));
    std::cout<<Complex()<<Complex(2,3)<<z2;
    std::cout<<2*Complex(1,2)+Complex(-3,5)*3;
    z2 = Complex(2,3) * z2;
    std::cout<<z2<<((z2==Complex(-13, -19.5))?("They are equal"):("They are not equal"))<<'\n';
    return 0;
}

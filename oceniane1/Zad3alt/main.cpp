#include <iostream>
#include "class.h"

int main()
{
    Deck d(54);
    d.display();
    d.shuffle();
    d.display();
    return 0;
}

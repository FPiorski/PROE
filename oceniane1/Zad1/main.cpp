#include <iostream>
#include "class.h"

int main()
{
    Timer t;
    t.start();
    system("sleep 2");
    t.pause();
    system("sleep 3");
    t.pause();
    system("sleep 3");
    t.pause();
    system("sleep 3");
    t.pause();
    system("sleep 3");
    t.pause();
    system("sleep 3");
    std::cout<<t.stop()<<'\n';    

    return 0;
}

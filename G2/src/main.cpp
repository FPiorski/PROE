#include "Sim.h"

int main(void)
{
    Sim::getInstance()->main();
    delete Sim::getInstance();
    return 0;
}

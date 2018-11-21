//Singleton implementation taken from page 38 of https://studia.elka.pw.edu.pl/file/18L/PROE.A/priv/wyk/wyk2.pdf
#pragma once
#include "Galaxy.h"

class Sim
{
private:
    static Sim* instance_;
    Galaxy g_;
    Sim() {}    //Defining methods right after declaration suggests inlining them to the compiler
    Sim(const Sim&) = delete;
    void operator=(const Sim&) = delete;
    void fromFile(std::ifstream& fs);
    CelestialObject* fromKeyboard();
public:
    static Sim* getInstance();
    void main();
};

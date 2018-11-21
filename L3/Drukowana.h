#pragma once
#include <string>
#include "Ksiazka.h"

class Drukowana : public Ksiazka
{
private:
    std::string oprawa_;
public:
    Drukowana(unsigned int = 10, const std::string& = "Miekka");
    ~Drukowana();
    void info(void);
};
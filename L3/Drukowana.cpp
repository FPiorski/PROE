#include <iostream>
#include <string>
#include "Drukowana.h"

Drukowana::Drukowana(unsigned int n, const std::string& o) : Ksiazka(n), oprawa_(o)
{
    std::cout << "Konstruktor klasy Drukowana\n";
}

Drukowana::~Drukowana()
{
    std::cout << "Destuktor klasy Drukowana\n";
}

void Drukowana::info(void)
{
    Ksiazka::info();
    std::cout << "Oprawa: " << oprawa_ << '\n';
}
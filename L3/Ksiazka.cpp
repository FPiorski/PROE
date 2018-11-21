#include <iostream>
#include "Ksiazka.h"

Ksiazka::Ksiazka(unsigned int n) : liczba_stron_(n)
{
    std::cout << "Konstruktor klasy Ksiazka\n";
}

Ksiazka::~Ksiazka()
{
    std::cout << "Destuktor klasy Ksiazka\n";
}

void Ksiazka::info()
{
    std::cout << "\nLiczba stron: " << liczba_stron_ << '\n';
}
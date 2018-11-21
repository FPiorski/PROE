#include <iostream>
#include "Ebook.h"

Ebook::Ebook(unsigned int n, unsigned int r) : Ksiazka(n), rozmiar_MB_(r)
{
    std::cout << "Konstruktor klasy Ebook\n";
}

Ebook::~Ebook()
{
    std::cout << "Destuktor klasy Ebook\n";
}

void Ebook::info(void)
{
    Ksiazka::info();
    std::cout << "Rozmiar: " << rozmiar_MB_ << "[MB]\n";
}
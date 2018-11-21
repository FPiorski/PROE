#pragma once
#include "Ksiazka.h"

class Ebook : public Ksiazka
{
private:
    unsigned int rozmiar_MB_;
public:
    Ebook(unsigned int = 10, unsigned int = 1);
    ~Ebook();
    void info(void);
};
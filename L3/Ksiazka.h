#pragma once

class Ksiazka
{
private:
    unsigned int liczba_stron_;
public:
    virtual void info(void)=0;
    Ksiazka(unsigned int n = 10);
    virtual ~Ksiazka();
};


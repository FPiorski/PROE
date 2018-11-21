#pragma once
#include <string>
#include <fstream>
#include "CelestialObject.h"

class GalaxyIter; //needed here so that GalaxyIter can be used in Galaxy definition

class Galaxy
{
private:
    CelestialObject** storage_;
    int cap_, size_;
    double Gconst_, dt_;
public:
    Galaxy(int c=10);
    ~Galaxy();
    GalaxyIter begin() const;
    GalaxyIter end() const;
    CelestialObject* operator[](int i) const;
    bool full();
    void pushBack(CelestialObject* c);
    int size();
    std::string toString();
    std::string footnote();
    void setdt(double dt)   {dt_ = dt;}
    void setG(double G) {Gconst_ =  G;}
    void step(int n);
};

class GalaxyIter //used for ranged for loops
{
private:
    const Galaxy* ptr_;
    int pos_;
public:
    GalaxyIter(const Galaxy* g, int pos) : ptr_(g), pos_(pos) {}

    bool operator!=(const GalaxyIter& other) const;
    CelestialObject* operator*() const;
    const GalaxyIter& operator++();
};

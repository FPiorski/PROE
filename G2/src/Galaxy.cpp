#include <algorithm> //for std::copy
#include <string>
#include <cmath>
#include "Galaxy.h"
#include "CelestialObject.h"

Galaxy::Galaxy(int c) : cap_(c), size_(0), Gconst_(6.674E-11), dt_(1)
{
    storage_ = new CelestialObject*[cap_];
}

Galaxy::~Galaxy()
{
    delete[] storage_;
}

GalaxyIter Galaxy::begin() const
{
    return GalaxyIter(this, 0);
}

GalaxyIter Galaxy::end() const
{
    return GalaxyIter(this, size_);
}

bool Galaxy::full()
{
    return size_ == cap_;
}

void Galaxy::pushBack(CelestialObject* c)
{
    if (full()){
        CelestialObject** temporary = new CelestialObject* [cap_<<2];
        std::copy(storage_, storage_+cap_, temporary);
        delete[] storage_;
        storage_ = temporary;
        cap_ <<= 2;
    }
    storage_[size_++] = c;
}

int Galaxy::size()
{
    return size_;
}

std::string Galaxy::toString()
{
    std::string s;
    s = std::to_string(Gconst_) + "\n"
      + std::to_string(dt_)     + "\n"
      + std::to_string(size())  + "\n";
    for (auto i : *this)
        s = s + i->toString();
    return s;
}

std::string Galaxy::footnote()
{
    std::string s;
    s = std::string("The simulation currently looks like this:\n")
      + "G:  " + std::to_string(Gconst_)       + "\n"
      + "dt: " + std::to_string(dt_)           + "\n";
    int n = 0;
    for (auto i : *this){
        s = s + std::to_string(n) + ": " + i->footnote();
        ++n;
    }
    return s;
}

void Galaxy::step(int n)
{
    for (int it=0; it<n; ++it)
    {
        double fx[size_]={0}, fy[size_]={0}, fz[size_]={0};
        for (int i=0; i<size_; ++i)
        {
            for (int j=i+1; j<size_; ++j)
            {
                double r = storage_[i]->dis(*storage_[j]);
                double f = storage_[j]->gm()*storage_[i]->gm()*Gconst_/(r*r);
                fx[j] -= storage_[i]->disx(*storage_[j])/r *f;
                fx[i] += storage_[i]->disx(*storage_[j])/r *f;
                fy[j] -= storage_[i]->disy(*storage_[j])/r *f;
                fy[i] += storage_[i]->disy(*storage_[j])/r *f;
                fz[j] -= storage_[i]->disz(*storage_[j])/r *f;
                fz[i] += storage_[i]->disz(*storage_[j])/r *f;
            }
            storage_[i]->addv(fx[i]/storage_[i]->gm()*dt_, fy[i]/storage_[i]->gm()*dt_, fz[i]/storage_[i]->gm()*dt_);
        }
        for (int i=0; i<size_; ++i){
            storage_[i]->advance(dt_);
        }
    }
}


bool GalaxyIter::operator!=(const GalaxyIter& other) const
{
    return pos_ != other.pos_;
}

CelestialObject* Galaxy::operator[](int i) const
{
    return storage_[i];
}

CelestialObject* GalaxyIter::operator*() const
{
    return (*ptr_)[pos_];
}

const GalaxyIter& GalaxyIter::operator++()
{
    ++pos_;
    return *this;
}

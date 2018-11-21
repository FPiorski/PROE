#include <string>
#include "CelestialObject.h"
#define TOSTR(a) (std::to_string(a).substr(0, std::to_string(a).size()-4))

CelestialObject::CelestialObject(double m,  double x,  double y,  double z,
                                 double vx, double vy, double vz)
                                :m(m), x(x), y(y), z(z), vx(vx), vy(vy), vz(vz) {}

CelestialObject::CelestialObject(const CelestialObject& c) 
                                :m(c.m), x(c.x), y(c.y), z(c.z), vx(c.vx), vy(c.vy), vz(c.vz) {}

std::string CelestialObject::toString()
{
    return std::to_string( m) + "\n"
         + std::to_string( x) + "\n"
         + std::to_string( y) + "\n"
         + std::to_string( z) + "\n"
         + std::to_string(vx) + "\n"
         + std::to_string(vy) + "\n"
         + std::to_string(vz);
}

Star::Star(const CelestialObject& c, double l) : CelestialObject(c), luminosity_(l) {}

std::string Star::toString()
{
    return "Star\n"
         + CelestialObject::toString() + "\n"
         + std::to_string(luminosity_) + "\n";
}

std::string Star::footnote()
{
    return "A star at [" + TOSTR(x) + ", " + TOSTR(y) + ", " + TOSTR(z) + "], traveling at ["
         + TOSTR(vx) + ", " + TOSTR(vy) + ", " + TOSTR(vz) + "], with a mass of " + TOSTR(m)
         + "kg and a luminosity of " + TOSTR(luminosity_) + "cd\n";
}

Planet::Planet(const CelestialObject& c, double r, bool l, bool w, bool i)
              :CelestialObject(c), r_(r), life_(l), water_(w), intelligent_life_(i) {}

std::string Planet::toString()
{
    return "Planet\n"
         + CelestialObject::toString()     + "\n"
         + std::to_string(r_)              + "\n"
         + std::to_string(life_)           + "\n"
         + std::to_string(water_)          + "\n"
         + std::to_string(intelligent_life_)+"\n";
}

std::string Planet::footnote()
{
    return "A planet at [" + TOSTR(x) + ", " + TOSTR(y) + ", " + TOSTR(z) + "], traveling at ["
         + TOSTR(vx) + ", " + TOSTR(vy) + ", " + TOSTR(vz) + "], with a mass of " + TOSTR(m)
         + "kg, radius of " + TOSTR(r_) + "m, " + (life_?"":"not ") + "supporting life, which "
         + (intelligent_life_?"has ":"does not have ") + "intelligent life and "
         + (water_?"has ":"does not have ") + "water on it's surface\n";
}

BlackHole::BlackHole(const CelestialObject& c, double r, bool w) : CelestialObject(c), r_(r), wormhole_(w) {}

std::string BlackHole::toString()
{
    return "BlackHole\n"
         + CelestialObject::toString()     + "\n"
         + std::to_string(r_)              + "\n"
         + std::to_string(wormhole_)       + "\n";
}

std::string BlackHole::footnote()
{
    return "A black hole at [" + TOSTR(x) + ", " + TOSTR(y) + ", " + TOSTR(z) + "], traveling at ["
         + TOSTR(vx) + ", " + TOSTR(vy) + ", " + TOSTR(vz) + "], with a mass of " + TOSTR(m)
         + "kg and radius of " + TOSTR(r_) + "m" + (wormhole_?" which is also a wormhole\n":"\n");
}

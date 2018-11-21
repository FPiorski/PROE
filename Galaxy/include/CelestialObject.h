#pragma once
#include <string>
#include <cmath>

class CelestialObject
{
protected:
    double m, x, y, z, vx, vy, vz;
public:
    CelestialObject(double m,  double x,  double y,  double z,
                              double vx, double vy, double vz);
    CelestialObject(const CelestialObject&);
    virtual std::string toString();
    virtual std::string footnote() {return "";}
    virtual ~CelestialObject() {}
    double gm(){return m;}
    double dis(const CelestialObject&c){
        return sqrt(disx(c)*disx(c)+disy(c)*disy(c)+disz(c)*disz(c));
    }
    double disx(const CelestialObject&c){return c.x-x;}
    double disy(const CelestialObject&c){return c.y-y;}
    double disz(const CelestialObject&c){return c.z-z;}
    void addv(double xx, double yy, double zz){vx+=xx; vy+=yy; vz+=zz;}
    void advance(double dt){x+=vx*dt; y+=vy*dt; z+=vz*dt;};
};

class Star : public CelestialObject
{
private:
    double luminosity_;
public:
    Star(const CelestialObject& c, double l);
    std::string toString();
    std::string footnote();
    ~Star() {}
};

class Planet : public CelestialObject
{
private:
    double r_;
    bool life_;
    bool water_;
    bool intelligent_life_;
public:
    Planet(const CelestialObject& c, double r, bool l, bool w, bool i);
    std::string toString();
    std::string footnote();
    ~Planet() {}
};

class BlackHole : public CelestialObject
{
private:
    double r_;
    bool wormhole_;
public:
    BlackHole(const CelestialObject& c, double r, bool w);
    std::string toString();
    std::string footnote();
    ~BlackHole() {}
};

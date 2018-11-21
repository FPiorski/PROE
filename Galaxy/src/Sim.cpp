//TODO: load, step, add

#include <iostream>
#include <string>
#include <fstream>
#include "Sim.h"
#include "Galaxy.h"
#include "CelestialObject.h"
#include "linenoise.h"

Sim* Sim::instance_ = nullptr;

Sim* Sim::getInstance()
{
    if (instance_ == nullptr)
        instance_ = new Sim;
    return instance_;
}

void Sim::main()
{
    using std::cout;
    using std::cin;
    using std::stoi;
    cout << "Welcome to a galaxy simulation, type >help< for help\n";
    char* linep;
    while((linep = linenoise("PROE1> ")) != NULL)
    {
        std::string line(linep);
        linenoiseHistoryAdd(linep);
        linenoiseFree(linep);
        if (line == "help"){
            cout << "Commands are as follows:\n"
                 << "help - print this message\n"
                 << "step <n> - perform n steps of the simulation and prints current parameters\n"
                 << "state - just prints the current state\n"
                 << "set <parameter> <value> - manually set the value of a variable\n"
                 << "add - add a celestial object to the simulation\n"
                 << "load <filename> - load the simulation parameters from file\n"
                 << "save <filename> - save the current state and all the parameters to file\n"
                 << "Type help <command> for command specific help\n";
        }
        if (line == "help step" || line == "help help" || line == "help load" || line == "help save" || line == "help state")
            cout << "Command specific help unavaible\n";
        if (line == "help set"){
            cout << "Global simulation parameters:\n - dt - step time in ms\n - G - the gravitational constant\n";
        }
        if (line == "help add"){
            cout << "Avaible types of celestial bodies:\n - \"Star\"\n - \"Planet\"\n - \"Black hole\"\n";
        }
        if (line.substr(0, 4) == "step"){
            int n;
            if (line.size()>=6)
                n = std::stoi(line.substr(5));
            else
                n = 1;
            g_.step(n);
            line = "state";
        }
        if (line.substr(0, 3) == "add"){
            CelestialObject *c = fromKeyboard();
            if (c != nullptr)
                g_.pushBack(c);
        }
        if (line.substr(0, 4) == "load"){
            std::ifstream fs(line.substr(5));
            if (!fs.is_open()){
                cout << "Can't open the file!\n";
                continue;
            }
            fromFile(fs);
            fs.close();
        }
        if (line.substr(0, 4) == "save"){
            std::ofstream fs(line.substr(5));
            if (!fs.is_open()){
                cout << "Can't open the file!\n";
                continue;
            }
            fs << g_.toString();
            fs.close();
        }
        if (line.substr(0, 5) == "state"){
            std::cout << g_.footnote();
        }
        if (line.substr(0, 3) == "set"){
            if (line.size()<5)
                continue;
            if (line.substr(4, 2) == "dt")
            {
                g_.setdt(std::stod(line.substr(7)));
            } else if (line[4] == 'G')
            {
                g_.setG(std::stod(line.substr(6)));
            }
        }
    }
    for (int i=0; i<g_.size(); ++i)
        delete g_[i];
}

void Sim::fromFile(std::ifstream& fs)
{
    using std::getline;
    using std::stoi;
    using std::stod;
    std::string t, type;
    getline(fs, t);
    double G = stod(t);
    g_.setG(G);
    getline(fs, t);
    double dt = stod(t);
    g_.setdt(dt);
    getline(fs, t);
    int n = stoi(t);
    for (int i=0; i<n; ++i){
        getline(fs, type);
        getline(fs, t);
        double m = stod(t);
        getline(fs, t);
        double x = stod(t);
        getline(fs, t);
        double y = stod(t);
        getline(fs, t);
        double z = stod(t);
        getline(fs, t);
        double vx = stod(t);
        getline(fs, t);
        double vy = stod(t);
        getline(fs, t);
        double vz = stod(t);
        if (type == "Star"){
            getline(fs, t);
            double lum = stod(t);
            g_.pushBack(new Star(CelestialObject(m, x, y, z, vx, vy, vz), lum));
        } else if (type == "Planet"){
            getline(fs, t);
            double r = stod(t);
            getline(fs, t);
            bool l = stoi(t);
            getline(fs, t);
            bool w = stoi(t);
            getline(fs, t);
            bool i = stoi(t);
            g_.pushBack(new Planet(CelestialObject(m, x, y, z, vx, vy, vz), r, l, w, i));
        } else if (type == "BlackHole"){
            getline(fs, t);
            double r = stod(t);
            getline(fs, t);
            bool w = stoi(t);
            g_.pushBack(new BlackHole(CelestialObject(m, x, y, z, vx, vy, vz), r, w));
        }
    }
}

CelestialObject* Sim::fromKeyboard()
{
    using std::getline;
    using std::cout;
    using std::stoi;
    using std::stod;
    
    cout << "What type of object would you like to add?\n";
    char *linep = linenoise("add> ");
    std::string line(linep);
    linenoiseFree(linep);
    if (line.substr(0, 4) != "Star" && line.substr(0, 6) != "Planet" && line.substr(0, 10) != "Black hole"){
        cout << "Avaible types of celestial object are: \"Planet\", \"Star\", \"Black hole\"\n";
        return nullptr;
    }
    std::string type;
    if (line.substr(0, 4) == "Star")
        type = "Star";
    if (line.substr(0, 6) == "Planet")
        type = "Planet";
    if (line.substr(0, 10) == "Black hole")
        type = "Black hole";
    cout << "What is the mass of the object?\n";
    linep = linenoise("add> ");
    line = linep;
    linenoiseFree(linep);
    double m = stod(line);
    cout << "What is the x coordinate of the object?\n";
    linep = linenoise("add> ");
    line = linep;
    linenoiseFree(linep);
    double x = stod(line);
    cout << "What is the y coordinate of the object?\n";
    linep = linenoise("add> ");
    line = linep;
    linenoiseFree(linep);
    double y = stod(line);
    cout << "What is the z coordinate of the object?\n";
    linep = linenoise("add> ");
    line = linep;
    linenoiseFree(linep);
    double z = stod(line);
    cout << "What is the x velocity of the object?\n";
    linep = linenoise("add> ");
    line = linep;
    linenoiseFree(linep);
    double vx = stod(line);
    cout << "What is the y velocity of the object?\n";
    linep = linenoise("add> ");
    line = linep;
    linenoiseFree(linep);
    double vy = stod(line);
    cout << "What is the z velocity of the object?\n";
    linep = linenoise("add> ");
    line = linep;
    linenoiseFree(linep);
    double vz = stod(line);
    if (type == "Star"){
        cout << "What is the luminosity coordinate of the star?\n";
        linep = linenoise("add> ");
        line = linep;
        linenoiseFree(linep);
        double lum = stod(line);
        g_.pushBack(new Star(CelestialObject(m, x, y, z, vx, vy, vz), lum));
    } else if (type == "Planet"){
        cout << "What is the radius of the planet?\n";
        linep = linenoise("add> ");
        line = linep;
        linenoiseFree(linep);
        double r = stod(line);
        cout << "Is there life on the surface?\n";
        linep = linenoise("add> ");
        line = linep;
        linenoiseFree(linep);
        bool l = line.size()>=2 && line.substr(0,2) == "ye";
        cout << "Is there water on the surface?\n";
        linep = linenoise("add> ");
        line = linep;
        linenoiseFree(linep);
        bool w = line.size()>=2 && line.substr(0,2) == "ye";
        cout << "Is there intelligent life on the surface?\n";
        linep = linenoise("add> ");
        line = linep;
        linenoiseFree(linep);
        bool i = line.size()>=2 && line.substr(0,2) == "ye";
        g_.pushBack(new Planet(CelestialObject(m, x, y, z, vx, vy, vz), r, l, w, i));
    } else if (type == "Black hole"){
        cout << "What is the black hole's radius?\n";
        linep = linenoise("add> ");
        line = linep;
        linenoiseFree(linep);
        double r = stod(line);
        cout << "Is there a white hole on the other side?\n";
        linep = linenoise("add> ");
        line = linep;
        linenoiseFree(linep);
        bool w = line.size()>=2 && line.substr(0,2) == "ye";
        g_.pushBack(new BlackHole(CelestialObject(m, x, y, z, vx, vy, vz), r, w));
    }
    return nullptr;
}

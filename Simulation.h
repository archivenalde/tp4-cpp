#ifndef SIMULATION_H
#define SIMULATION_H

#include <list>

class Mobile;

class Simulation {
    double temps;
    std::list<Mobile*> corps;

public:
    Simulation(double _temps = 0);
    Simulation(const Simulation&);

    double getTemps(void) const;
    std::list<Mobile*> getCorps(void) const;

    void ajoutCorps(Mobile*);
    void oteCorps(Mobile*);
    void afficheCorps(void) const;

    void simuler(double);

    ~Simulation();
};


#endif

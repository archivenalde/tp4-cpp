#include <iostream>
#include <list>

#include "Simulation.h"

#include "Mobile.h"

Simulation::Simulation(double _temps)
: temps(_temps)
{}

double Simulation::getTemps() const
{
    return temps;
}

std::list<Mobile*> Simulation::getCorps() const
{
    return corps;
}

void Simulation::ajoutCorps(Mobile* _m)
{
    corps.push_back(_m->copie());
}

void Simulation::oteCorps(Mobile* _m)
{
    for (Mobile* it : corps)
    {
        if (*_m == *it)
        {
            corps.remove(it);
            delete it;
        }
    }
}

void Simulation::afficheCorps(void) const
{
    std::cout << "Affichage de la liste des mobiles au temps " << temps << " : " << std::endl;
    for (Mobile *it : corps)
    {
        it->affiche();
    }
}

void Simulation::simuler(double dt)
{
    for (Mobile* it : corps)
        it->avance(dt);
    temps +=dt;
}


Simulation::~Simulation()
{
    while (!corps.empty())
    {
        delete corps.front();
        corps.pop_front();
    }
}

#include <iostream>
#include <list>

#include "Simulation.h"

#include "Mobile.h"

Simulation::Simulation(double _temps)
: temps(_temps)
{}

Simulation::Simulation(const Simulation& s)
{
    temps = s.temps;
    for (Mobile* it : s.corps)
        corps.push_back(it->copie());
}

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
    std::list<Mobile*>::iterator it;

    for (it = corps.begin(); it != corps.end(); it++)
    {
        (*it)->affiche();
        if (*_m == **it)
        {
            delete *it;
            it = corps.erase(it);
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

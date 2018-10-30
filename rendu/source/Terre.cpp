#include <cmath>

#include "Terre.h"

unsigned long long Terre::GM = 3986 * pow(10, 11);
unsigned long long Terre::RT = 6378000;
Terre* Terre::instance = 0;

Terre::Terre()
{}

Terre::Terre(const Terre& t)
{}

Terre& Terre::operator=(Terre& t)
{
    return t;
}

unsigned long Terre::getRT() const
{
    return RT;
}

unsigned long Terre::getGM() const
{
    return GM;
}

Vecteur3D Terre::gravite(Vecteur3D const& p)
{
    double coeff = GM / pow(p.norme(), 3);
    Vecteur3D g = -coeff * p;

    return g;
}

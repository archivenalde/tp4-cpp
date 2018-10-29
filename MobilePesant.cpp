#include <string>
#include <cmath>

#include "MobilePesant.h"
#include "Vecteur3D.h"
#include "Terre.h"

MobilePesant::MobilePesant(double _masse, const std::string _nom, Vecteur3D _pos, Vecteur3D _vit)
: Mobile(_nom, _pos, _vit), masse(_masse)
{}

MobilePesant::MobilePesant(double _masse, const std::string _nom, double x, double y, double z, double inclinaison)
: Mobile(_nom), masse(_masse)
{
    Terre* t = Terre::getInstance();
    Vecteur3D normal(0, -sin((M_PI/180)*inclinaison), cos((M_PI/180)*inclinaison));
    long double n;

    position = Vecteur3D(x, y, z);
    if(x*normal[0]+y*normal[1]+z*normal[2] != 0)
    {
        std::cout << "La position du vecteur " << _nom << " n'appartient pas au plan de rotation. Recalibrage automatique." << std::endl;
        n = position.norme();
        z = -(x*normal[0]+y*normal[1])/normal[2];
        position = Vecteur3D(x, y, z);
        position.normaliser(n);
    }

    vitesse = normal^position;
    vitesse.normaliser(sqrt(t->getGM()/position.norme()));
}

Mobile* MobilePesant::copie() const
{
    Mobile* mc = new MobilePesant(*this);
    return mc;
}

double MobilePesant::getMasse(void) const
{
    return masse;
}

void MobilePesant::avance(double dt) {
    Terre* t = Terre::getInstance();
    position += dt*vitesse;
    vitesse += dt*t->gravite(position);
}

MobilePesant::~MobilePesant()
{}

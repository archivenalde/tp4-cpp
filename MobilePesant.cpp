#include <string>

#include "MobilePesant.h"
#include "Vecteur3D.h"
#include "Terre.h"

MobilePesant::MobilePesant(double _masse, const std::string _nom, Vecteur3D _pos, Vecteur3D _vit)
: Mobile(_nom, _pos, _vit), masse(_masse)
{}

Mobile* MobilePesant::copie() const
{
    Mobile* mc = new MobilePesant(*this);
    return mc;
}


double MobilePesant::getMasse(void) const
{
    return masse;
}

/*void MobilePesant::avance(double dt) {
    position += dt*vitesse;
    vitesse += dt*G;
}*/

void MobilePesant::avance(double dt) {
    Terre* t = Terre::getInstance();
    position += dt*vitesse;
    vitesse += dt*t->gravite(position);
}

MobilePesant::~MobilePesant()
{}

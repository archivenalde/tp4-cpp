#include <string>

#include "MobilePesant.h"
#include "Vecteur3D.h"

Vecteur3D MobilePesant::G = Vecteur3D(0, 0, -9.81);

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

void MobilePesant::avance(double dt) {
    position = position + dt*vitesse;
    vitesse = vitesse + dt*G;
}

MobilePesant::~MobilePesant()
{}

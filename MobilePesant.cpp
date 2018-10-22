#include "MobilePesant.h"

Vecteur3D Vecteur3D::G = Vecteur3D(0, 0, -9.81)

double MobilePesant::getMasse(void) const {
    return masse;
}

void MobilePesant::avance(double dt) {
    position = position + dt*vitesse;
    vitesse = vitesse + dt*G;
}

#ifndef MOBILEPESANT_H
#define MOBILEPESANT_H

#include "Mobile.h"

class MobilePesant : public Mobile
{
    static Vecteur3D G;
    double masse;

public:
    MobilePesant(double _masse, const std::string _nom = "Pas de nom", Vecteur3D _pos = Vecteur3D(0,0,0), Vecteur3D _vit = Vecteur3D(0,0,0));

    virtual Mobile* copie() const;

    double getMasse(void) const;
    void avance(double);

    virtual ~MobilePesant();
};
#endif

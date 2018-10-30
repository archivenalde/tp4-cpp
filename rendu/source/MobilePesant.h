#ifndef MOBILEPESANT_H
#define MOBILEPESANT_H

#include "Mobile.h"

class MobilePesant : public Mobile
{
    double masse;

public:
    MobilePesant(double _masse, const std::string _nom, Vecteur3D _pos = Vecteur3D(0,0,0), Vecteur3D _vit = Vecteur3D(0,0,0));
    MobilePesant(double _masse, const std::string _nom, double x, double y, double z, double inclinaison);
    virtual Mobile* copie() const;

    double getMasse(void) const;
    void avance(double);

    virtual ~MobilePesant();
};
#endif

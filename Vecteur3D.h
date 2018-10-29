#ifndef VECTEUR3D_H
#define VECTEUR3D_H

#include <iostream>

class Vecteur3D
{
    double x, y, z;
public:
    Vecteur3D(double _x = 0, double _y = 0, double _z = 0);

    void affiche(void) const;
    double norme(void) const;

    void normaliser(double n = 1.0);

    double operator[](const int a) const;
    void operator+=(Vecteur3D const& v);
    void operator-=(Vecteur3D const& v);
    void operator=(Vecteur3D const& v);
    void operator-(void);
};

Vecteur3D operator+(Vecteur3D const&, Vecteur3D const&);
Vecteur3D operator-(Vecteur3D const&, Vecteur3D const&);
Vecteur3D operator^(Vecteur3D const&, Vecteur3D const&);
Vecteur3D operator*(double d, Vecteur3D const& v);
Vecteur3D operator/(Vecteur3D const& v, double d);
bool operator==(Vecteur3D const& a, Vecteur3D const& b);
bool operator!=(Vecteur3D const& a, Vecteur3D const& b);
std::ostream& operator<<(std::ostream& os, Vecteur3D const& a );

#endif

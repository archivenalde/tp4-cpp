#include <iostream>

#include "Vecteur3D.h"

Vecteur3D::Vecteur3D(double _x, double _y, double _z)
:x(_x), y(_y), z(_z)
{}

void Vecteur3D::affiche()
{
    std::cout << "("<< x << ", " << y << ", " << z << ")";
}



Vecteur3D operator+(Vecteur3D const& a, Vecteur3D const& b)
{
    Vecteur3D res(a.x + b.x, a.y + b.y, a.z + b.z);
    return res;
}

Vecteur3D operator*(double d, Vecteur3D const& v)
{
    Vecteur3D res(d*v.x, d*v.y, d*v.z);
    return res;
}

bool operator==(Vecteur3D const& a, Vecteur3D const& b)
{
    if (a.x == b.x && a.y == b.y && a.z == b.z)
            return true;
    return false;
}

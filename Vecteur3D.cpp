#include <iostream>
#include <cmath>
#include "Vecteur3D.h"

Vecteur3D::Vecteur3D(double _x, double _y, double _z)
:x(_x), y(_y), z(_z)
{}

void Vecteur3D::affiche() const
{
    std::cout << "("<< x << ", " << y << ", " << z << ")";
}



Vecteur3D operator+(Vecteur3D const& a, Vecteur3D const& b)
{
    Vecteur3D res(a[0] + b[0], a[1] + b[1], a[2] + b[2]);
    return res;
}

Vecteur3D operator*(double d, Vecteur3D const& v)
{
    Vecteur3D res(d*v[0], d*v[1], d*v[2]);
    return res;
}

bool operator==(Vecteur3D const& a, Vecteur3D const& b)
{
    if (a[0] == b[0] && a[1] == b[1] && a[2] == b[2])
            return true;
    return false;
}

bool operator!=(Vecteur3D const& a, Vecteur3D const& b)
{
    return !(a == b);
}

double Vecteur3D::operator[](const int a) const
{
    if(a == 0)
        return x;
    if(a == 1)
        return y;
    if(a == 2)
        return z;

    return 0;
}

void Vecteur3D::operator+=(Vecteur3D const& v)
{
    this->x += v.x;
    this->y += v.y;
    this->z += v.z;
}

void Vecteur3D::operator-=(Vecteur3D const& v)
{
    this->x -= v.x;
    this->y -= v.y;
    this->z -= v.z;
}

 void Vecteur3D::operator=(Vecteur3D const& v)
 {
     this->x = v.x;
     this->y = v.y;
     this->z = v.z;
 }

void Vecteur3D::operator-(void)
{
    this->x = -x;
    this->y = -y;
    this->z = -z;
}

double Vecteur3D::norme() const
{
    return sqrt(x*x + y*y + z*z);
}

std::ostream& operator<<(std::ostream& os, const Vecteur3D& v)
{
    os << "("<< v[0] << ", " << v[1] << ", " << v[2] << ")";
    return os;
}

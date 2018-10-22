#ifndef VECTEUR3D_H
#define VECTEUR3D_H

class Vecteur3D {
public:
    double x, y, z;
    Vecteur3D(double _x = 0, double _y = 0, double _z = 0);

    void affiche();

};

Vecteur3D operator+(Vecteur3D const&, Vecteur3D const&);
Vecteur3D operator*(double d, Vecteur3D const& v);
bool operator==(Vecteur3D const& a, Vecteur3D const& b);

#endif

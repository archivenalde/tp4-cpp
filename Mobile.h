#ifndef MOBILE_H
#define MOBILE_H

#include <string>

#include "Vecteur3D.h"

class Mobile {
protected:
    std::string nom;
    Vecteur3D position;
    Vecteur3D vitesse;

public:
    Mobile(const std::string& _nom = "Pas de nom");
    Mobile(const std::string&, Vecteur3D _pos, Vecteur3D _vit);

    void avance(double dt);

    const std::string& getNom(void) const;
    const Vecteur3D& getPosition(void) const;
    const Vecteur3D& getVitesse(void) const;

    void setNom(const std::string&);
    void setPosition(const Vecteur3D&);
    void setVitesse(const Vecteur3D&);

    void affiche();

    ~Mobile();
};

bool operator==(const Mobile& a, const Mobile& b);

#endif
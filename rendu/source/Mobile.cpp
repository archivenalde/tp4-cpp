#include <iostream>

#include "Mobile.h"

Mobile::Mobile(const std::string& _nom)
: nom(_nom)
{}

Mobile::Mobile(const std::string& _nom, Vecteur3D _pos, Vecteur3D _vit)
: nom(_nom), position(_pos), vitesse(_vit)
{}



Mobile* Mobile::copie() const
{
    Mobile* mc = new Mobile(*this);
    return mc;
}

void Mobile::avance(double dt)
{
    position += dt*vitesse;
}

const std::string& Mobile::getNom(void) const
{
    return nom;
}
const Vecteur3D& Mobile::getPosition(void) const
{
    return position;
}
const Vecteur3D& Mobile::getVitesse(void) const
{
    return vitesse;
}

void Mobile::setNom(const std::string& _nom)
{
    nom = _nom;
}

void Mobile::setPosition(const Vecteur3D& _pos)
{
    position = _pos;
}

void Mobile::setVitesse(const Vecteur3D& _vit)
{
    vitesse = _vit;
}

void Mobile::affiche()
{
    std::cout << "Mobile " << nom << " : " << std::endl;
    std::cout << "Position : ";
    position.affiche();
    std::cout << std::endl;
    std::cout << "Vitesse : ";
    vitesse.affiche();
    std::cout << std::endl << std::endl;

}

Mobile::~Mobile()
{}


bool operator==(const Mobile& a, const Mobile& b)
{
    return a.getPosition() == b.getPosition() && a.getVitesse() == b.getVitesse();
}

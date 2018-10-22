#ifndef MOBILEPESANT_H
#define MOBILEPESANT_H

class MobilePesant : public Mobile {
    double masse;
    static Vecteur3D G;

public:
    double getMasse(void) const;
    void avance(double);
};
#endif

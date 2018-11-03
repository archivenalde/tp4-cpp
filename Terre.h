#ifndef TERRE_H
#define TERRE_H


#include "Vecteur3D.h"


class Terre {
    static unsigned long long GM;
    static unsigned long long RT;

    static Terre* instance;
    Terre();
    Terre(const Terre& t);
    Terre& operator=(Terre&);

public:
    // Methode a appeler soit pour initialiser l'instance de Terre, soit pour recuperer cette instance.
    static Terre* getInstance() {
        if (instance == 0)
            instance = new Terre();
        return instance;
    }

    // Methode lorsqu'on a plus besoin de l'instance de Terre dans la suite du programme. Il sera necessaire de reinitialiser la Terre avec (void)Terre::getInstance().
    static void destroyInstance() {
        if (instance != 0)
        {
            delete instance;
            instance = 0;
        }
    }

    unsigned long getRT() const;
    unsigned long getGM() const;
    Vecteur3D gravite(Vecteur3D const& p);
};

#endif

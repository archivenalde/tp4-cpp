#ifndef TERRE_H
#define TERRE_H


#include "Vecteur3D.h"


class Terre {
    static unsigned long GM;
    static unsigned long RT;

    static Terre* instance;
    Terre();
    Terre(const Terre& t);
    Terre& operator=(Terre&);

public:
    static Terre* getInstance() {
        if (instance == 0)
            instance = new Terre();
        return instance;
    }

    unsigned long getRT() const;
    unsigned long getGM() const;
    Vecteur3D gravite(Vecteur3D const& p);
};

#endif

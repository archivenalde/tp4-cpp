#include "Mobile.h"
#include "Vecteur3D.h"
#include "Simulation.h"

#include <iostream>

bool testMobile1()
{
    bool res = true;
    Mobile m("test", Vecteur3D(1, 1, 1), Vecteur3D(0, 2, 3));

    if (m.getPosition().x != 1 || m.getPosition().y != 1 || m.getPosition().z != 1)
        if (m.getVitesse().x != 0 || m.getVitesse().y != 2 || m.getVitesse().z != 3)
            res &= false;

    m.avance(5);

    if (m.getPosition().x != 1 || m.getPosition().y != 11 || m.getPosition().z != 16)
        if (m.getVitesse().x != 0 || m.getVitesse().y != 2 || m.getVitesse().z != 3)
            res &= false;

    return res;
}

bool testSimulation1()
{
    bool res = true;
    Simulation simu(3);

    Mobile m1("Test simu m1", Vecteur3D (0, 0, 0), Vecteur3D(2, 0, 3));
    Mobile m2("Test simu m2", Vecteur3D (0, 0, 1), Vecteur3D(0, -1, 3));

    simu.ajoutCorps(&m1);
    simu.ajoutCorps(&m2);

    std::list<Mobile*> c = simu.getCorps();
    for (Mobile* it : c)
    {
        if (*it == m1)
        {
            res &= (it->getPosition() == Vecteur3D (0, 0, 0) && it->getVitesse() == Vecteur3D (2, 0, 3));
            std::cout << "1" << std::endl;
        }
        if (*it == m2)
        {
            res &= (it->getPosition() == Vecteur3D (0, 0, 1) && it->getVitesse() == Vecteur3D (0, -1, 3));
            std::cout << "2" << std::endl;
        }
    }

    simu.simuler(2);

    Mobile m1bis("test mobile m1bis", m1.getPosition() + 2*m1.getVitesse(), m1.getVitesse());
    Mobile m2bis("test mobile m2bis", m2.getPosition() + 2*m2.getVitesse(), m2.getVitesse());

    c = simu.getCorps();

    for (Mobile* it : c)
    {
        it->affiche();
        m1bis.affiche();
        m2bis.affiche();
        if (*it == m1bis)
        {
            res &= (it->getPosition() == Vecteur3D (4, 0, 6) && it->getVitesse() == Vecteur3D (2, 0, 3));
            std::cout << "3" << std::endl;
        }
        if (*it == m2bis)
        {
            res &= (it->getPosition() == Vecteur3D (0, -2, 7) && it->getVitesse() == Vecteur3D (0, -1, 3));
            std::cout << "4" << std::endl;
        }
        std::cout << "res = " << res << std::endl;

    }

    simu.oteCorps(&m2bis);
    res &= simu.getCorps().size() == 1;

    return res;
}


bool testSimulation2()
{
    Simulation *s = new Simulation(5);
    Mobile m("test mobile 1", Vecteur3D(0, 0, 0), Vecteur3D(1, 1, 1));

    Simulation s1(3);
    s->ajoutCorps(&m);
    s1.ajoutCorps(&m);

    delete s;
    return true;
}

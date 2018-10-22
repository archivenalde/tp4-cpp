#include "Mobile.h"
#include "MobilePesant.h"
#include "Vecteur3D.h"
#include "Simulation.h"

#include <iostream>
#include <cmath>

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

bool testMobile2() {
    double hauteur = 15;
    MobilePesant mp(5, "Test Mobile Pesant", Vecteur3D(10, 10, hauteur), Vecteur3D(0, 0, 0));
    double tpsChute = 0, dt = 0.0001;
    double tpsChuteTheorique = sqrt(2 * hauteur/9.81);

    mp.affiche();
    while(mp.getPosition().z > 0)
    {
        mp.avance(dt);
        tpsChute += dt;
    }
    std::cout << "Temps de chute : " << tpsChute << std::endl;
    mp.affiche();

    return (tpsChute - dt <= tpsChuteTheorique || tpsChute + dt >= tpsChuteTheorique );

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

bool testSimulation3()
{
    Simulation s;
    double dt = 0.4;
    Mobile m("Test Mobile Pas Pesant", Vecteur3D(0, 0, 0), Vecteur3D(1, 1, 1));
    MobilePesant mp(5, "Test Mobile Pesant", Vecteur3D(10, 10, 10), Vecteur3D(0, 0, 0));

    s.ajoutCorps(&m);
    s.ajoutCorps(&mp);

    s.afficheCorps();

    while (s.getTemps() < 4)
    {
        s.simuler(dt);
        s.afficheCorps();
    }

    return true;
}


bool testSimulation4()
{
    Simulation s1;
    Mobile m("Test Mobile Pas Pesant", Vecteur3D(0, 0, 0), Vecteur3D(1, 1, 1));
    MobilePesant mp(5, "Test Mobile Pesant", Vecteur3D(10, 10, 10), Vecteur3D(0, 0, 0));
    int compteur = 0;

    s1.ajoutCorps(&m);
    s1.ajoutCorps(&mp);

    Simulation s2(s1);

    s1.afficheCorps();
    s2.afficheCorps();


    if (s2.getTemps() == s1.getTemps())
    {
        for (Mobile* it : s1.getCorps())
        {
            if (compteur == 0 && !(*it == m))
                return false;
            if (compteur == 1 && !(*it == mp))
                return false;
            compteur++;
        }
        compteur = 0;
        for (Mobile* it : s2.getCorps())
        {
            if (compteur == 0 && !(*it == m))
                return false;
            if (compteur == 1 && !(*it == mp))
                return false;
            compteur++;
        }
        return true;
    }

    return false;
}

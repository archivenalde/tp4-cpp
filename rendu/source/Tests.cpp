#include "Mobile.h"
#include "MobilePesant.h"
#include "Vecteur3D.h"
#include "Simulation.h"
#include "Terre.h"

#include <iostream>
#include <cmath>

bool testMobile1()
{
    bool res = true;
    Mobile m("test", Vecteur3D(1, 1, 1), Vecteur3D(0, 2, 3));

    if (m.getPosition()[0] != 1 || m.getPosition()[1] != 1 || m.getPosition()[2] != 1)
        if (m.getVitesse()[0] != 0 || m.getVitesse()[1] != 2 || m.getVitesse()[2] != 3)
            res &= false;

    m.avance(5);

    if (m.getPosition()[0] != 1 || m.getPosition()[1] != 11 || m.getPosition()[2] != 16)
        if (m.getVitesse()[0] != 0 || m.getVitesse()[1] != 2 || m.getVitesse()[2] != 3)
            res &= false;

    return res;
}

bool testMobile2() {
    double hauteur = 6377999 + 2;
    MobilePesant mp(5, "Test Mobile Pesant", Vecteur3D(0, 0, hauteur), Vecteur3D(0, 0, 0));
    double tpsChute = 0, dt = 0.0001;
    double tpsChuteTheorique = sqrt(2 * (hauteur - 6377999)/9.79);

    mp.affiche();
    while(mp.getPosition()[2] > 6377999)
    {
        mp.avance(dt);
        tpsChute += dt;
    }
    std::cout << "Temps de chute : " << tpsChute << std::endl;
    mp.affiche();

    std::cout << tpsChuteTheorique << std::endl;

    return (tpsChute - 0.5 <= tpsChuteTheorique && tpsChute + 0.5 >= tpsChuteTheorique );

}

bool testSimulation1()
{
    bool res = true;
    Simulation simu(3);

    Mobile m1("Test simu m1", Vecteur3D (0, 0, 0), Vecteur3D(2, 0, 3));
    Mobile m2("Test simu m2", Vecteur3D (0, 0, 1), Vecteur3D(0, -1, 3));

    simu.ajoutCorps(&m1);
    simu.ajoutCorps(&m2);

    res &= simu.getCorps().size() == 2;

    std::list<Mobile*> c = simu.getCorps();
    for (Mobile* it : c)
    {
        if (*it == m1)
        {
            res &= (it->getPosition() == Vecteur3D (0, 0, 0) && it->getVitesse() == Vecteur3D (2, 0, 3));
        }
        if (*it == m2)
        {
            res &= (it->getPosition() == Vecteur3D (0, 0, 1) && it->getVitesse() == Vecteur3D (0, -1, 3));
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
        }
        if (*it == m2bis)
        {
            res &= (it->getPosition() == Vecteur3D (0, -2, 7) && it->getVitesse() == Vecteur3D (0, -1, 3));
        }

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

bool testVecteur3D()
{
    bool res = true;
    Vecteur3D v(1, 2, 3);
    Vecteur3D v2;
    Vecteur3D v3 = v;
    Vecteur3D v5(0, 0, 1);
    v5 += v;
    v2 = v;

    if (v2 != v)
        return res &= false;
    if (v3 != v2)
        return res &= false;

    Vecteur3D v4 = 3*v3;

    if (!(v4[0] == 3 && v4[1] == 6 && v4[2] == 9))
        return false;

    if (!(v5[0] == 1 && v5[1] == 2 && v5[2] == 4))
        return false;

    std::cout << "Affichage d'un Vecteur3D : " << std::endl;
    std::cout << v5 << std::endl;

    return res;
}

bool testTerre()
{
    bool res = true;
    Terre* t = Terre::getInstance();
    Terre* terreTest = Terre::getInstance();
    Vecteur3D point(6378000, 0, 0);
    Vecteur3D g = t->gravite(point);

    std::cout << g << std::endl;
    if(g[0] < -9.81 || g[0] > -9.79)
        res &= false;
    if(t != terreTest)
        res &= false;

    return res;
}


bool testSatellite1()
{
    Terre* t = Terre::getInstance();
    Simulation s;
    int hauteur = 200000;
    Vecteur3D positionSatellite(hauteur + t->getRT(), 0, 0);
    Vecteur3D vitesseSatellite(0, sqrt((long double)t->getGM()/(t->getRT() + hauteur)), 0);
    MobilePesant satellite(150, "Satellite", positionSatellite, vitesseSatellite);
    double dt = 0.1;
    double tpsSimulation = 2*M_PI*sqrt(pow(t->getRT() + hauteur, 3) / t->getGM());
    std::cout << "Temps de simulation : " << (int)(tpsSimulation/3600.0)  << "h" << ((int)tpsSimulation%3600)/60 << "m" << (int)tpsSimulation%60 << "s" << std::endl;
    double incertitude = 1000;

    s.ajoutCorps(&satellite);
    std::cout << "Position de départ du satellite : " << positionSatellite << std::endl;
    std::cout << "Vitesse de départ du satellite : " << vitesseSatellite << std::endl;

    while (s.getTemps() < tpsSimulation)
        s.simuler(dt);

    Vecteur3D positionArrivee = s.getCorps().front()->getPosition();
    Vecteur3D vitesseArrivee = s.getCorps().front()->getVitesse();

    std::cout << "Position d'arrive du satellite : " << positionArrivee << std::endl;
    std::cout << "Vitesse d'arrive du satellite : " << vitesseArrivee << std::endl;

    if (positionSatellite[1] + incertitude >= positionArrivee[1] && positionSatellite[1] - incertitude <= positionArrivee[1])
        return true;
    return false;
}


bool testSatellite2()
{
    Terre* t = Terre::getInstance();
    Simulation s;
    int hauteur = 820000;
    MobilePesant satellite(150, "SPOT", t->getRT() + hauteur, 0, 0, 98.7);
    Vecteur3D positionDepart, positionArrivee;
    double dt = 0.1;
    double tpsSimulation = 2 * M_PI * sqrt((double)pow(t->getRT() + hauteur, 3) / t->getGM());
    std::cout << "Temps de simulation : " << (int) (tpsSimulation/3600.0)  << "h" << ((int)tpsSimulation%3600)/60 << "m" << (int)tpsSimulation%60 << "s" << std::endl;
    double incertitude = 1000;

    s.ajoutCorps(&satellite);
    positionDepart = satellite.getPosition();
    std::cout << "Position de départ du satellite SPOT : " << positionDepart << std::endl;
    std::cout << "Vitesse de départ du satellite SPOT : " << satellite.getVitesse().norme() << " m.s^(-1)" << std::endl;

    while (s.getTemps() <= tpsSimulation)
        s.simuler(dt);

    positionArrivee = s.getCorps().front()->getPosition();
    std::cout << "Position d'arrivee du satellite SPOT : " << positionArrivee << std::endl;

    Vecteur3D ecart = positionDepart-positionArrivee;
    if (ecart.norme() < incertitude)
        return true;
    return false;
}


bool testLune()
{
    Terre* t = Terre::getInstance();
    Simulation s;
    int hauteur = 378027000;
    MobilePesant satellite(7.42*pow(10, 22), "Lune", t->getRT() + hauteur, 0, 0, 28.58);
    Vecteur3D positionDepart, positionArrivee;
    double dt = 0.1;
    double tpsSimulation = 2 * M_PI * sqrt((double)pow(t->getRT() + hauteur, 3) / t->getGM());
    std::cout << "Temps de simulation : ";
    if (tpsSimulation > 3600*24)
        std::cout <<  (int) (tpsSimulation/(3600.0*24)) << "j";
    std::cout <<  (int) (tpsSimulation/3600.0)%24  << "h" << ((int)tpsSimulation%3600)/60 << "m" << (int)tpsSimulation%60 << "s" << std::endl;
    double incertitude = 1000;

    s.ajoutCorps(&satellite);
    positionDepart = satellite.getPosition();
    std::cout << "Position de départ de la Lune : " << positionDepart << std::endl;
    std::cout << "Vitesse de départ de la Lune : " << satellite.getVitesse().norme() << " m.s^(-1)" << std::endl;

    while (s.getTemps() <= tpsSimulation)
        s.simuler(dt);

    positionArrivee = s.getCorps().front()->getPosition();
    std::cout << "Position d'arrivee de la Lune : " << positionArrivee << std::endl;

    Vecteur3D ecart = positionDepart-positionArrivee;
    if (ecart.norme() < incertitude)
        return true;
    return false;
}

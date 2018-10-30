#include <iostream>

#include "Mobile.h"
#include "Vecteur3D.h"
#include "Simulation.h"
#include "Tests.h"

int main(int argc, char const *argv[])
{
    std::cout << "---------------Test Mobile 1---------------" << std::endl;
    std::cout << testMobile1() << std::endl;

    std::cout << "---------------Test Mobile 2---------------" << std::endl;
    std::cout << testMobile2() << std::endl;

    std::cout << "---------------Test Simulation 1---------------" << std::endl;
    std::cout << testSimulation1() << std::endl;

    std::cout << "---------------Test Simulation 2---------------" << std::endl;
    std::cout << testSimulation2() << std::endl;

    std::cout << "---------------Test Simulation 3---------------" << std::endl;
    std::cout << testSimulation3() << std::endl;

    std::cout << "---------------Test Simulation 4---------------" << std::endl;
    std::cout << testSimulation4() << std::endl;

    std::cout << "---------------Test Vecteur3D---------------" << std::endl;
    std::cout << testVecteur3D() << std::endl;

    std::cout << "---------------Test Terre ---------------" << std::endl;
    std::cout << testTerre() << std::endl;

    std::cout << "---------------Test Satellite 1---------------" << std::endl;
    std::cout << testSatellite1() << std::endl;

    std::cout << "---------------Test Satellite 1---------------" << std::endl;
    std::cout << testSatellite1() << std::endl;

    std::cout << "---------------Test Lune---------------" << std::endl;
    std::cout << testLune() << std::endl;

    return 0;
}

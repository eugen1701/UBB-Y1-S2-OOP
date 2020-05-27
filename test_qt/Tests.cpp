//
// Created by sweethuman on 25.05.2020.
//
#include "Repository.h"
#include <fstream>
#include <assert.h>
void TestRepo(){
    std::ofstream file{"tests.txt"};
    file<<"Mercedes-Benz|SUV|2013|blue\n"
            "Fiat|Bravo|2007|red\n"
            "Jaguar|Pantera|2020|green\n"
            "Mitsubishi|Impreza|2015|yellow\n"
            "Mazda|Furious|2002|magenta\n"
            "Mazda|Banana|2003|yellow";
    file.close();
    Repository repo{"tests.txt"};
    assert(2 == repo.numberOfCarsforManufacturer("Mazda"));
    assert(1 == repo.numberOfCarsforManufacturer("Jaguar"));
    assert(0 == repo.numberOfCarsforManufacturer("Bambino"));
}
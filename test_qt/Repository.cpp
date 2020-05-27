//
// Created by sweethuman on 24.05.2020.
//

#include "Repository.h"
#include <fstream>


std::vector<BaseClass> &Repository::list() {
    return this->elems;
}

void Repository::write_to_file() {
    std::ofstream file{filename};
    for(auto item : this->elems){
        file << item.toString() << "\n";
    }
}
void Repository::read_from_file() {
    elems.clear();
    std::ifstream fileToRead(filename);
    BaseClass item;
    while (fileToRead >> item)
        elems.push_back(item);
}

/// Returns the number of cars for the specified manufacturer.
/// \param manufacturer The manufacturer name
/// \return The Number of cars that are from that manufacturer
int Repository::numberOfCarsforManufacturer(std::string manufacturer) {
    int count = 0;
    for (auto &car : elems) {
        if (car.manufacturer == manufacturer) {
            count++;
        }
    }
    return count;
}

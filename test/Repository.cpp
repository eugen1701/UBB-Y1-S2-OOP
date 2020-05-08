//
// Created by sweethuman on 04.05.2020.
//

#include "Repository.h"
std::vector<MedLab*> &Repository::getAll() {
    return labs;
}
bool Repository::add(MedLab*lab) {
    labs.push_back(lab);
    return true;
}

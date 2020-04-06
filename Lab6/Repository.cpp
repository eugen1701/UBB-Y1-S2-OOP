//
// Created by sweethuman on 22.03.2020.
//

#include "Repository.h"
void Repository::addDog(const Dog &dog) { this->dogs.add(dog); }
Dog Repository::getDog(const std::string &breed, const std::string &name) {
    for (int i = 0; i < dogs.getSize(); i++) {
        if (dogs[i].getBreed() == breed && dogs[i].getName() == name) {
            return dogs[i];
        }
    }
    return Dog();
}
bool Repository::removeDog(const std::string &breed, const std::string &name) {
    for (int i = 0; i < dogs.getSize(); i++) {
        if (dogs[i].getBreed() == breed && dogs[i].getName() == name) {
            dogs.pop(i);
            return true;
        }
    }
    return false;
}
bool Repository::isDog(const std::string &breed, const std::string &name) {
    for (int i = 0; i < dogs.getSize(); i++) {
        if (dogs[i].getBreed() == breed && dogs[i].getName() == name) {
            return true;
        }
    }
    return false;
}

//
// Created by sweethuman on 22.03.2020.
//

#include "Repository.h"
void Repository::addDog(Dog &dog) {
    this->dogs.push_back(dog);
}
Dog Repository::getDog(const std::string &breed, const std::string &name) {
    for (auto &dog : dogs) {
        if (dog.getBreed() == breed && dog.getName() == name) {
            return dog;
        }
    }
    return Dog();
}
bool Repository::removeDog(const std::string &breed, const std::string &name) {
    for (unsigned int i = 0; i < dogs.size(); i++) {
        if (dogs[i].getBreed() == breed && dogs[i].getName() == name) {
            dogs.erase(dogs.begin() + i);
            return true;
        }
    }
    return false;
}
bool Repository::isDog(const std::string &breed, const std::string &name) {
    for (auto &dog : dogs) {
        if (dog.getBreed() == breed && dog.getName() == name) {
            return true;
        }
    }
    return false;
}

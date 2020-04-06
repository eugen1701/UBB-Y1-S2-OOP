//
// Created by sweethuman on 23.03.2020.
//

#include "Service.h"
bool Service::addDog(const std::string &breed, const std::string &name, int age, const std::string &photograph) {
    if (this->repository.isDog(breed, name)) {
        return false;
    }
    Dog *dog = new Dog(breed, name, age, photograph);
    this->repository.addDog(*dog);
    delete dog;
    return true;
}
bool Service::removeDog(const std::string &breed, const std::string &name) {
    return this->repository.removeDog(breed, name);
}
std::string Service::listDogs() {
    auto array = this->repository.getDogs();
    std::string result;
    for (int i = 0; i < array.getSize(); i++) {
        result += array[i].toString();
        result += "\n";
    }
    return result;
}
bool Service::updateDog(const std::string &breed, const std::string &name, int age, const std::string &photograph) {
    if (!this->repository.isDog(breed, name)) {
        return false;
    }
    auto dog = this->repository.getDog(breed, name);
    this->repository.removeDog(breed, name);
    if (age != 0) {
        dog.setAge(age);
    }
    if (!photograph.empty()) {
        dog.setPhotograph(photograph);
    }
    this->repository.addDog(dog);
    return true;
}
DynamicVector<Dog> Service::filterDogs(const std::string &breed, int age) {
    DynamicVector<Dog> tempDogs;
    auto dogs = repository.getDogs();
    for (auto &dog : dogs) {
        if((breed.empty() || dog.getBreed() == breed) && dog.getAge() < age) {
            tempDogs.add(dog);
        }
    }
    return tempDogs;
}
bool Service::adoptDog(const Dog &dog) {
    if (this->adoptedRepo.isDog(dog.getBreed(), dog.getName())) {
        return false;
    }
    this->adoptedRepo.addDog(dog);
    return true;
}
bool Service::unadoptDog(const std::string &breed, const std::string &name) {
    return this->adoptedRepo.removeDog(breed, name);
}
bool Service::isDogAdopted(const std::string &breed, const std::string &name) {
    return this->adoptedRepo.isDog(breed, name);
}
DynamicVector<Dog> Service::getAdoptedDogs() {
    return this->adoptedRepo.getDogs();
}

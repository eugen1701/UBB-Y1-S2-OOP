//
// Created by sweethuman on 23.03.2020.
//

#include "Service.h"
#include "DogValidator.h"
bool Service::addDog(const std::string &breed, const std::string &name, int age, const std::string &photograph) {
    Dog *dog = new Dog(breed, name, age, photograph);
    DogValidator::validate(*dog);
    if (this->repository.isDog(breed, name)) {
        return false;
    }
    this->repository.addDog(*dog);
    delete dog;
    sync();
    return true;
}
bool Service::removeDog(const std::string &breed, const std::string &name) {
    auto result = this->repository.removeDog(breed, name);
    sync();
    return result;
}
std::string Service::listDogs() {
    auto dogs = this->repository.getDogs();
    std::string result;
    for (auto &i : dogs) {
        result += i.toString();
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
    DogValidator::validate(dog);
    this->repository.addDog(dog);
    sync();
    return true;
}
std::vector<Dog> Service::filterDogs(const std::string &breed, int age) {
    std::vector<Dog> tempDogs;
    auto dogs = repository.getDogs();
    for (auto &dog : dogs) {
        if ((breed.empty() || dog.getBreed() == breed) && dog.getAge() < age) {
            tempDogs.push_back(dog);
        }
    }
    return tempDogs;
}
bool Service::adoptDog(Dog dog) {
    if (this->adoptedRepo.isDog(dog.getBreed(), dog.getName())) {
        return false;
    }
    DogValidator::validate(dog);
    this->adoptedRepo.addDog(dog);
    return true;
}
bool Service::unadoptDog(const std::string &breed, const std::string &name) {
    return this->adoptedRepo.removeDog(breed, name);
}
bool Service::isDogAdopted(const std::string &breed, const std::string &name) {
    return this->adoptedRepo.isDog(breed, name);
}
std::vector<Dog> Service::getAdoptedDogs() {
    return this->adoptedRepo.getDogs();
}

void Service::sync() {
    auto dogs = adoptedRepo.getDogs();
    for (auto &dog : dogs) {
        if (repository.isDog(dog.getBreed(), dog.getName())) {
            auto original_dog = repository.getDog(dog.getBreed(), dog.getName());
            adoptedRepo.removeDog(dog.getBreed(), dog.getName());
            adoptedRepo.addDog(original_dog);
        } else {
            adoptedRepo.removeDog(dog.getBreed(), dog.getName());
        }
    }
}

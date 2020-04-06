//
// Created by sweethuman on 22.03.2020.
//

#include "Domain.h"
Dog::Dog() : breed(""), name(""), age(0), photograph("") {}
Dog::Dog(const std::string &breed, const std::string &name, int age, const std::string &photograph) {
    this->breed = breed;
    this->name = name;
    this->age = age;
    this->photograph = photograph;
}
Dog::Dog(Dog &other_dog) {
    this->breed = other_dog.breed;
    this->name = other_dog.name;
    this->age = other_dog.age;
    this->photograph = other_dog.photograph;
}
void Dog::setAge(int new_age) { this->age = new_age; }
void Dog::setPhotograph(const std::string &new_photograph) { this->photograph = new_photograph; }
std::string Dog::toString() {
    return this->breed + " " + this->name + " " + std::to_string(this->age) + " " + this->photograph;
}
Dog &Dog::operator=(const Dog &other_dog) {
    if (this == &other_dog) {
        return *this;
    }
    this->breed = other_dog.breed;
    this->name = other_dog.name;
    this->age = other_dog.age;
    this->photograph = other_dog.photograph;
    return *this;
}

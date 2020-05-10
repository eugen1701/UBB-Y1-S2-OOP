//
// Created by sweethuman on 22.03.2020.
//

#include "Domain.h"
#include <vector>
#include <sstream>
Dog::Dog() : breed(""), name(""), age(0), photograph("") {}
Dog::Dog(const std::string &breed, const std::string &name, int age, const std::string &photograph) {
    this->breed = breed;
    this->name = name;
    this->age = age;
    this->photograph = photograph;
}
Dog::Dog(const Dog &other_dog) {
    this->breed = other_dog.breed;
    this->name = other_dog.name;
    this->age = other_dog.age;
    this->photograph = other_dog.photograph;
}
void Dog::setAge(int new_age) { this->age = new_age; }
void Dog::setPhotograph(const std::string &new_photograph) { this->photograph = new_photograph; }
std::string Dog::toString() const {
    return this->breed + ", " + this->name + ", " + std::to_string(this->age) + ", " + this->photograph;
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

std::vector<std::string> split(const std::string& input, char delimiter) {
    std::vector<std::string> result;
    std::stringstream input_stream(input);
    std::string token;
    while (getline(input_stream, token, delimiter))
        result.push_back(token);

    return result;
}

std::istream &operator>>(std::istream &is, Dog &dog) {
    std::string line{};
    getline(is, line);
    std::vector<std::string> arguments = split(line, ',');
    if (arguments.size() == 0) {
        return is;
    }

    dog.breed = arguments[0];
    dog.name = arguments[1];
    dog.age = std::stoi(arguments[2]);
    dog.photograph = arguments[3];
    return is;
}
std::ostream &operator<<(std::ostream &os, const Dog &dog) {
    return os << dog.breed << "," << dog.name << "," << std::to_string(dog.age) << "," << dog.photograph;
}

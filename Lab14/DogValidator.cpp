//
// Created by sweethuman on 23.04.2020.
//

#include "DogValidator.h"
void DogValidator::validate(const Dog &dog) {
    std::string errors;
    if (dog.getName().size() == 0)
        errors += "The Dog name cannot be empty!\n";
    if (dog.getBreed().size() == 0)
        errors += "The Dog breed cannot be empty!\n";
    if (dog.getAge() < 0)
        errors += "The Dog age cannot be negative\n";
    if (dog.getPhotograph().size() == 0)
        errors += "The Dog has to have a photograph!\n";
    if(!errors.empty())
        throw InvalidDogException(errors);
}

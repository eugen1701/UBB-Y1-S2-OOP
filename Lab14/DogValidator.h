//
// Created by sweethuman on 23.04.2020.
//

#ifndef LAB9_DOGVALIDATOR_H
#define LAB9_DOGVALIDATOR_H

#include "Domain.h"
#include <string>
class InvalidDogException : public std::exception {
  private:
    std::string message;

  public:
    InvalidDogException(std::string message) : message(message) {}
    const char* what() const noexcept override { return message.c_str(); }
};

class DogValidator {
  public:
    static void validate(const Dog& dog);
};

#endif // LAB9_DOGVALIDATOR_H

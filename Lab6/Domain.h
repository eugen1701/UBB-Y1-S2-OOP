//
// Created by sweethuman on 22.03.2020.
//
#include <string>
#ifndef LAB5_DOMAIN_H
class Dog {
  private:
    std::string breed;
    std::string name;
    int age;
    std::string photograph;

  public:
    Dog();
    Dog(const std::string &breed, const std::string &name, int age, const std::string &photograph);
    Dog(Dog &other_dog);
    Dog &operator=(const Dog &other_dog);

    [[nodiscard]] std::string getBreed() const { return breed; };
    [[nodiscard]] std::string getName() const { return name; };
    [[nodiscard]] int getAge() const { return age; };
    [[nodiscard]] std::string getPhotograph() const { return photograph; };

    void setAge(int new_age);
    void setPhotograph(const std::string &new_photograph);
    /// Converts Dog to a string.
    /// \return The Dog object represented as a String.
    std::string toString();
};
#define LAB5_DOMAIN_H

#endif // LAB5_DOMAIN_H

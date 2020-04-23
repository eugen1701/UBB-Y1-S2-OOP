//
// Created by sweethuman on 12.04.2020.
//

#include "FileRepository.h"
#include <fstream>
void FileRepository::addDog(Dog &dog) {
    auto dogs = readData();
    dogs.push_back(dog);
    writeData(dogs);
}
Dog FileRepository::getDog(const std::string &breed, const std::string &name) {
    auto dogs = readData();
    for (auto &dog : dogs) {
        if (dog.getBreed() == breed && dog.getName() == name) {
            return dog;
        }
    }
    return Dog();
}
bool FileRepository::removeDog(const std::string &breed, const std::string &name) {
    auto dogs = readData();
    for (unsigned int i = 0; i < dogs.size(); i++) {
        if (dogs[i].getBreed() == breed && dogs[i].getName() == name) {
            dogs.erase(dogs.begin() + i);
            writeData(dogs);
            return true;
        }
    }
    return false;
}
bool FileRepository::isDog(const std::string &breed, const std::string &name) { return Repository::isDog(breed, name); }
std::vector<Dog> FileRepository::readData() const {
    std::vector<Dog> dogs;
    std::ifstream dogsFile{fileName};
    Dog dog;
    while (dogsFile >> dog) {
        dogs.push_back(dog);
    }
    return dogs;
}
void FileRepository::writeData(const std::vector<Dog> &dogs) {
    std::ofstream dogsFile{fileName};
    for (auto &dog : dogs) {
        dogsFile << dog << "\n";
    }
}
std::vector<Dog> FileRepository::getDogs() const { return readData(); }

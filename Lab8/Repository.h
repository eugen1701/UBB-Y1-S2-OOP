//
// Created by sweethuman on 22.03.2020.
//

#ifndef LAB5_REPOSITORY_H
#define LAB5_REPOSITORY_H
#include "Domain.h"
#include <vector>
class Repository {
  private:
    std::vector<Dog> dogs;

  public:
    Repository() = default;
    /// Adds a dog to the repository, doesn't care about duplicates or uniqueness
    /// \param dog the dog to add
    virtual void addDog(Dog &dog);
    /// Returns the Dog from the repository that matches the parameters
    /// \param breed The Breed of the Dog
    /// \param name The Name of the Dog
    /// \return If the dog doesn't exist it returns an empty Dog.
    virtual Dog getDog(const std::string &breed, const std::string &name);
    /// Removes the dog that matches the parameters
    /// \param breed The breed of the dog to remove
    /// \param name The name of the dog to remove
    /// \return True if Removal was successful, false if not, ussually because there was no dog found that matches
    virtual bool removeDog(const std::string &breed, const std::string &name);
    /// Checks if there is a dog that matches the parameters
    /// \param breed The breed of the dog
    /// \param name The name of the dog
    /// \return True if such dog exists, false otherwise
    virtual bool isDog(const std::string &breed, const std::string &name);
    /// Returns copy of the DynamicArray containing all the dogs
    /// \return The DynamicVector containing the dogs
    [[nodiscard]] virtual std::vector<Dog> getDogs() const { return dogs; }
};

#endif // LAB5_REPOSITORY_H

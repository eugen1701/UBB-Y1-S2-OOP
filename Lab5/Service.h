//
// Created by sweethuman on 23.03.2020.
//

#ifndef LAB5_SERVICE_H
#define LAB5_SERVICE_H
#include "Repository.h"
class Service {
  private:
    Repository& repository;

  public:
    explicit Service(Repository &repo) : repository(repo) {}
    /// Adds a dog to the database inside.
    /// If there already exists a dog with the same breed and name, it fails
    /// \param breed The Breed of the New Dog
    /// \param name The Name of the New Dog
    /// \param age The age of the new dog
    /// \param photograph The link to the new dog's photograph
    /// \return True if adding was successful, false otherwise
    bool addDog(const std::string &breed, const std::string &name, int age, const std::string &photograph);
    /// Removes the dog that matches de parameters
    /// \param breed The breed of the dog
    /// \param name The name of the dog
    /// \return True if removal was successful, false if there was no dog matching
    bool removeDog(const std::string &breed, const std::string &name);
    /// The Whole list of dogs in the database under string form to be easily printable to the ui
    /// \return The string
    std::string listDogs();
    /// Updates the age and photograph of the dog using breed and name as unique identifiers
    /// \param breed The breed of the dog
    /// \param name The name of the dog
    /// \param age The New age of the dog
    /// \param photograph The New photograph of the dog
    /// \return True if the dog was updated, false otherwise, ussualy because there exists no Dog that matches the criteria
    bool updateDog(const std::string &breed, const std::string &name, int age = 0, const std::string &photograph = "");
};
#endif // LAB5_SERVICE_H

//
// Created by sweethuman on 23.03.2020.
//

#ifndef LAB5_SERVICE_H
#define LAB5_SERVICE_H
#include "Repository.h"
#include <vector>
#include "Action.h"
#include <memory>
class Service {
  private:
    Repository &repository;
    Repository &adoptedRepo;
    std::vector<std::unique_ptr<Action>> undoStack;
    std::vector<std::unique_ptr<Action>> redoStack;

  public:
    explicit Service(Repository &repo, Repository &adoptedRepo) : repository(repo), adoptedRepo(adoptedRepo) {}
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
    /// \return True if the dog was updated, false otherwise, ussualy because there exists no Dog that matches the
    /// criteria
    bool updateDog(const std::string &breed, const std::string &name, int age = 0, const std::string &photograph = "");
    /// Returns Dog if it respects criteria
    /// \param breed Dog has to be equal to breed
    /// \param age Dog has to be smaller than age
    std::vector<Dog> filterDogs(const std::string &breed, int age);
    /// All dogs currently in the system
    /// \return
    std::vector<Dog> getDogs() { return repository.getDogs(); }
    /// Adds a dog to the adoption list
    bool adoptDog(const Dog dog);
    /// Removes a dog from the adoption list
    bool unadoptDog(const std::string &breed, const std::string &name);
    /// Checks if a dog with the unique identifiers is already adopted
    bool isDogAdopted(const std::string &breed, const std::string &name);
    /// Get all the dogs in the adoption list
    std::vector<Dog> getAdoptedDogs();

    bool executeUndo();
    bool executeRedo();
    void something(Action::ExecutedAction aha) {};
  private:
    void sync();
};
#endif // LAB5_SERVICE_H

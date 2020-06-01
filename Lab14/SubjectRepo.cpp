//
// Created by sweethuman on 30.05.2020.
//

#include "SubjectRepo.h"
void SubjectRepo::addDog(Dog &dog) {
    repo.addDog(dog);
    notify(Action::ExecutedAction::added);
}
bool SubjectRepo::unregisterCallback(int uid) {
    return callbacks.erase(uid) != 0;
}
bool SubjectRepo::removeDog(const std::string &breed, const std::string &name) {
    auto result = repo.removeDog(breed, name);
    notify(Action::ExecutedAction::removed);
    return result;
}
void SubjectRepo::notify(Action::ExecutedAction action) {
    for (auto &item : callbacks) {
        item.second(action);
    }
}
Dog SubjectRepo::getDog(const std::string &breed, const std::string &name) {
    return repo.getDog(breed, name);
}
bool SubjectRepo::isDog(const std::string &breed, const std::string &name) {
    return repo.isDog(breed, name);
}
std::vector<Dog> SubjectRepo::getDogs() const {
    return repo.getDogs();
}

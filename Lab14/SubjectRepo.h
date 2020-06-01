//
// Created by sweethuman on 30.05.2020.
//

#ifndef LAB14_SUBJECTREPO_H
#define LAB14_SUBJECTREPO_H

#include "Action.h"
#include "Repository.h"
#include <functional>
#include <map>
#include <vector>
class SubjectRepo : public Repository {
  private:
    Repository &repo;
    typedef std::function<void(Action::ExecutedAction)> callback;
    std::map<int, callback> callbacks;
    int lastid = 0;

  public:
    SubjectRepo(Repository &repo) : repo(repo) {
    }
    ~SubjectRepo() {
    }
    template <class R>
    inline int registerCallback(R *instance, void (R::*mem_callback)()) {
        callbacks[lastid] = std::bind(mem_callback, instance);
        return lastid++;
    }
    template <class R>
    inline int registerCallback(R *instance, void (R::*mem_callback)(Action::ExecutedAction)) {
        callbacks[lastid] = std::bind(mem_callback, instance, std::placeholders::_1);
        return lastid++;
    }
    bool unregisterCallback(int uid);
    void notify(Action::ExecutedAction action);
    void addDog(Dog &dog) override;
    bool removeDog(const std::string &breed, const std::string &name) override;
    virtual Dog getDog(const std::string &breed, const std::string &name) override;
    virtual bool isDog(const std::string &breed, const std::string &name) override;
    virtual std::vector<Dog> getDogs() const override;
};

#endif // LAB14_SUBJECTREPO_H

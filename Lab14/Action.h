//
// Created by sweethuman on 28.04.2020.
//

#ifndef LAB9_ACTION_H
#define LAB9_ACTION_H

#include "Domain.h"
#include "Repository.h"
class Action {
  protected:
    Repository &repo;

  public:
    enum class ExecutedAction { added, removed, updated };
    virtual ExecutedAction executeUndo() = 0;
    virtual ExecutedAction executeRedo() = 0;
    Action(Repository &repo) : repo(repo) {
    }
};

class ActionAdd : public Action {
  private:
    Dog addedDog;

  public:
    ExecutedAction executeUndo() override;
    ExecutedAction executeRedo() override;
    ActionAdd(Repository &repo, Dog &addedDog) : Action(repo), addedDog(addedDog){};
};

class ActionRemove : public Action {
  private:
    Dog removedDog;

  public:
    ExecutedAction executeUndo() override;
    ExecutedAction executeRedo() override;
    ActionRemove(Repository &repo, Dog &removedDog) : Action(repo), removedDog(removedDog){};
};

class ActionUpdate : public Action {
  private:
    Dog originalDog;
    Dog updatedDog;

  public:
    ExecutedAction executeUndo() override;
    ExecutedAction executeRedo() override;
    ActionUpdate(Repository &repo, Dog &originalDog, Dog &updatedDog)
        : Action(repo), originalDog(originalDog), updatedDog(updatedDog){};
};

#endif // LAB9_ACTION_H

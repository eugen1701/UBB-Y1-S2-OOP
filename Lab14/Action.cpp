//
// Created by sweethuman on 28.04.2020.
//

#include "Action.h"
Action::ExecutedAction ActionAdd::executeUndo() {
    repo.removeDog(addedDog.getBreed(), addedDog.getName());
    return ExecutedAction::removed;
}

Action::ExecutedAction ActionAdd::executeRedo() {
    repo.addDog(addedDog);
    return ExecutedAction::added;
}
Action::ExecutedAction ActionRemove::executeUndo() {
    repo.addDog(removedDog);
    return ExecutedAction::added;
}
Action::ExecutedAction ActionRemove::executeRedo() {
    repo.removeDog(removedDog.getBreed(), removedDog.getName());
    return ExecutedAction::removed;
}
Action::ExecutedAction ActionUpdate::executeUndo() {
    repo.removeDog(updatedDog.getBreed(), updatedDog.getName());
    repo.addDog(originalDog);
    return ExecutedAction::updated;
}
Action::ExecutedAction ActionUpdate::executeRedo() {
    repo.removeDog(originalDog.getBreed(), originalDog.getName());
    repo.addDog(updatedDog);
    return ExecutedAction::updated;
}

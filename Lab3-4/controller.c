//
// Created by sweethuman on 03.03.2020.
//

#include "controller.h"
#include "OperationStack.h"
#include "repo.h"
#include <stdlib.h>
#include <string.h>
bool controller__add(Controller *controller, Medication *medicine) {
    Medication *medicineFromRepo =
        repo__get(controller->repo, getMedicationName(medicine), getMedicationConcentration(medicine));
    if (medicineFromRepo == NULL) {
        Operation *operation = operation__create(medicine, "add");
        opstack__push(controller->undoStack, operation);
        opstack__destroy(controller->redoStack);
        controller->redoStack = opstack__create();
        operation__destroy(operation);
        Medication *medicine_copy = medication__copy(medicine);
        repo__add(controller->repo, medicine_copy);
        return false;
    } else {
        medicineFromRepo->quantity += getMedicationQuantity(medicine);
        return true;
    }
}
bool controller__remove(Controller *controller, char *name, int concentration) {
    Medication *medicineFromRepo = repo__get(controller->repo, name, concentration);
    if (medicineFromRepo == NULL) {
        return false;
    }
    Operation *operation = operation__create(medicineFromRepo, "remove");
    opstack__push(controller->undoStack, operation);
    opstack__destroy(controller->redoStack);
    controller->redoStack = opstack__create();
    operation__destroy(operation);
    bool remove_success = repo__remove(controller->repo, name, concentration);
    return remove_success;
}
bool controller__update(Controller *controller, char *name, int concentration, int quantity, int price) {
    Medication *medicineFromRepo = repo__get(controller->repo, name, concentration);
    if (medicineFromRepo == NULL) {
        return false;
    }
    Operation *operation = operation__create(medicineFromRepo, "remove");
    opstack__push(controller->undoStack, operation);
    opstack__destroy(controller->redoStack);
    controller->redoStack = opstack__create();
    operation__destroy(operation);
    medicineFromRepo->quantity = quantity;
    medicineFromRepo->price = price;
    return true;
}
DynamicArray *controller__nameFilter(Controller *controller, char *substring) {
    DynamicArray *objects = repo__getAll(controller->repo);
    if (substring[0] == '\n' || substring[0] == '\0') {
        DynamicArray *copy = dynamicArray__copy(objects);
        return copy;
    }
    DynamicArray *copy = dynamicArray__create(10);
    for (int i = 0; i < dynamicArray__getLength(objects); i++) {
        if (strstr(getMedicationName(dynamicArray__getElement(objects, i)), substring) != NULL) {
            dynamicArray__addElement(copy, dynamicArray__getElement(objects, i));
        }
    }
    return copy;
}

DynamicArray *controller__quantityFilter(Controller *controller, int quantity) {
    DynamicArray *objects = repo__getAll(controller->repo);
    DynamicArray *copy = dynamicArray__create(10);
    for (int i = 0; i < dynamicArray__getLength(objects); i++) {
        if (getMedicationQuantity(dynamicArray__getElement(objects, i)) < quantity) {
            dynamicArray__addElement(copy, dynamicArray__getElement(objects, i));
        }
    }
    return copy;
}
Controller *controller__create(Repo *repo, OperationStack *undoStack, OperationStack *redoStack) {
    Controller *controller = (Controller *)malloc(sizeof(Controller));
    if (controller == NULL)
        return NULL;
    controller->repo = repo;
    controller->undoStack = undoStack;
    controller->redoStack = redoStack;
    return controller;
}
void controller__destroy(Controller *controller) {
    if (controller == NULL)
        return;
    repo__destroy(controller->repo);
    opstack__destroy(controller->undoStack);
    opstack__destroy(controller->redoStack);
    free(controller);
}
DynamicArray *controller__getAll(Controller *controller) { return dynamicArray__copy(repo__getAll(controller->repo)); }
bool controller__undo(Controller *controller) {
    if (opstack__isEmpty(controller->undoStack)) {
        return false;
    }
    Operation *operation = opstack__pop(controller->undoStack);
    char *operationType = operation__getType(operation);
    Medication *medication = operation__getMedication(operation);
    if (strcmp(operationType, "add") == 0) {
        repo__remove(controller->repo, getMedicationName(medication), getMedicationConcentration(medication));
        opstack__push(controller->redoStack, operation);
    } else if (strcmp(operationType, "remove") == 0) {
        repo__add(controller->repo, medication__copy(medication));
        opstack__push(controller->redoStack, operation);
    } else if (strcmp(operationType, "update") == 0) {
        Medication *original_medication =
            repo__get(controller->repo, getMedicationName(medication), getMedicationConcentration(medication));
        Medication *copy_medication = medication__copy(original_medication);
        original_medication->quantity = medication->quantity;
        original_medication->price = medication->price;
        Operation *redo_operation = operation__create(copy_medication, "update");
        opstack__push(controller->redoStack, redo_operation);
        operation__destroy(redo_operation);
    }
    operation__destroy(operation);
    return true;
}
bool controller__redo(Controller *controller) {
    if (opstack__isEmpty(controller->redoStack)) {
        return false;
    }
    Operation *operation = opstack__pop(controller->redoStack);
    char *operationType = operation__getType(operation);
    Medication *medication = operation__getMedication(operation);
    if (strcmp(operationType, "add") == 0) {
        repo__add(controller->repo, medication__copy(medication));
        opstack__push(controller->undoStack, operation);
    } else if (strcmp(operationType, "remove") == 0) {
        repo__remove(controller->repo, getMedicationName(medication), getMedicationConcentration(medication));
        opstack__push(controller->undoStack, operation);
    } else if (strcmp(operationType, "update") == 0) {
        Medication *original_medication =
            repo__get(controller->repo, getMedicationName(medication), getMedicationConcentration(medication));
        Medication *copy_medication = medication__copy(original_medication);
        original_medication->quantity = medication->quantity;
        original_medication->price = medication->price;
        Operation *undo_operation = operation__create(copy_medication, "update");
        opstack__push(controller->undoStack, undo_operation);
        operation__destroy(undo_operation);
    }
    operation__destroy(operation);
    return true;
}

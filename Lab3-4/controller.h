//
// Created by sweethuman on 03.03.2020.
//

#include "OperationStack.h"
#include "domain.h"
#include "repo.h"
#include <stdbool.h>
#ifndef LAB3_4_CONTROLLER_H
#define LAB3_4_CONTROLLER_H
typedef struct {
    Repo *repo;
    OperationStack *undoStack;
    OperationStack *redoStack;
} Controller;
/// Doesn't make any copy of the given parameters
Controller *controller__create(Repo *repo, OperationStack *undoStack, OperationStack *redoStack);
void controller__destroy(Controller *controller);
// false - is normal add and true - special add where only quantities are added, prices remain the same
/// Adds Medicine to storage
/// Makes a copy of the medication
/// \param medicine Medication to add
/// \return Boolean - False if addition was normal and true if medication already exists and just increased quantity
bool controller__add(Controller *controller, Medication *medicine);
/// Removes medicine from storage
/// \param name Name of the medication
/// \param concentration Concentration of the medication
/// \return Boolean - True if remove was successful, false if element didn't exist
bool controller__remove(Controller *controller, char *name, int concentration);
/// Updates a medication using name and concentration as identifiers
/// \param name Name of the medication
/// \param concentration Concentration of the medication
/// \param quantity Updated quantity
/// \param price Updated price
/// \return Boolean - True if the update was successful, False if element did not exit
bool controller__update(Controller *controller, char *name, int concentration, int quantity, int price);
/// Searches for medicine which name contains substring
/// \param substring The substring to filter with
/// \return A struct with the filtered items containing an array and length
DynamicArray *controller__nameFilter(Controller *controller, char *substring);
/// Searches for medication that is lower than the quantity specified
/// \param controller The Controller to search through
/// \param quantity The quantity you want to filter by
/// \return A new DynamicArray containing only the filtered elements
DynamicArray *controller__quantityFilter(Controller *controller, int quantity);
/// Gives all the medication containted in the controller
/// \param controller The controller to return from
/// \return A NEW DynamicArray containing all the medications
DynamicArray *controller__getAll(Controller *controller);
/// Undoes the last operation that modified the internal database
/// \return True if undo was successful, false otherwise
bool controller__undo(Controller *controller);
/// Redoes the last operation that modified the internal database
/// Opposite of undo.
/// \return True if redo was successful, false otherwise
bool controller__redo(Controller *controller);

#endif // LAB3_4_CONTROLLER_H

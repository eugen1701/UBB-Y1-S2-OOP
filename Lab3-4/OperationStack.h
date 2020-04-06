//
// Created by sweethuman on 22.03.2020.
//

#ifndef LAB3_4_OPERATIONSTACK_H
#define LAB3_4_OPERATIONSTACK_H
#include "domain.h"
#include <stdbool.h>
typedef struct {
    Medication *med;
    char *operationType;
} Operation;
/// Creates a new Operation instance
/// Makes a copy of Medication and the string representing the performed operation
/// \param med The medication of the operation that was used in the operation
/// \param performedOperation A string representing the operation that was performed
/// \return A new Operation
Operation *operation__create(Medication *med, char *performedOperation);
/// Frees up all the memory associated with the operation
/// \param operation the operation to destroy
void operation__destroy(Operation *operation);
/// Creates a new copy of a given operation
/// Makes a copy of everything inside.
/// \param operation The Operation to copy
/// \return The new copy of the operation
Operation *operation__copy(Operation *operation);
/// Get the operation Type
/// \param operation
/// \return The string of the operation type
char *operation__getType(Operation *operation);
// E destul de clar ce se intampla, m-am saturat sa ma repet
// Nu, nu returneaza o copie
Medication *operation__getMedication(Operation *operation);

typedef struct {
    Operation *operations[100];
    int length;
} OperationStack;
// Creates a new OperationStack, magical
OperationStack *opstack__create();
// Frees up the memory associated with operationStack
// thanks a lot buddy
void opstack__destroy(OperationStack *operationStack);
/// Pushes an operation on the operation stack and returns
/// Creates a copy of the operation
/// \param operationStack The operationStack to push onto
/// \param operation The operatiaon to push
void opstack__push(OperationStack *operationStack, Operation *operation);
/// Removes the last pushed operation and returns it
/// \param operationStack The operation stack to remove from
/// \return The operation just removed, must be freed.
Operation *opstack__pop(OperationStack *operationStack);
// Ok, these below are pretty clear, i tried to write clear and understandable code
bool opstack__isEmpty(OperationStack *operationStack);
bool opstack__isFull(OperationStack *operationStack);

void testStack();
#endif // LAB3_4_OPERATIONSTACK_H

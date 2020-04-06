//
// Created by sweethuman on 22.03.2020.
//

#include "OperationStack.h"
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
Operation *operation__create(Medication *med, char *performedOperation) {
    Operation *operation = (Operation *)malloc(sizeof(Operation));
    operation->med = medication__copy(med);
    if (performedOperation != NULL) {
        operation->operationType = (char *)malloc(sizeof(char) * strlen(performedOperation) + 1);
        strcpy(operation->operationType, performedOperation);
    } else {
        operation->operationType = NULL;
    }
    return operation;
}

void operation__destroy(Operation *operation) {
    if (operation == NULL) {
        return;
    }
    medication__destroy(operation->med);
    free(operation->operationType);
    free(operation);
}

Operation *operation__copy(Operation *operation) {
    if (operation == NULL) {
        return NULL;
    }
    Operation *newOperation = operation__create(operation__getMedication(operation), operation__getType(operation));
    return newOperation;
}

char *operation__getType(Operation *operation) { return operation->operationType; }

Medication *operation__getMedication(Operation *operation) { return operation->med; }

OperationStack *opstack__create() {
    OperationStack *stack = (OperationStack *)malloc(sizeof(OperationStack));
    stack->length = 0;
    return stack;
}

void opstack__destroy(OperationStack *stack) {
    if (stack == NULL)
        return;
    for (int i = 0; i < stack->length; i++) {
        operation__destroy(stack->operations[i]);
    }
    free(stack);
}

void opstack__push(OperationStack *operationStack, Operation *operation) {
    operationStack->operations[operationStack->length++] = operation__copy(operation);
}

Operation *opstack__pop(OperationStack *operationStack) {
    if (operationStack->length == 0) {
        return NULL;
    }
    return operationStack->operations[--operationStack->length];
}

bool opstack__isEmpty(OperationStack *operationStack) { return operationStack->length == 0; }

bool opstack__isFull(OperationStack *operationStack) { return operationStack->length == 100; }
void testStack() {
    OperationStack *stack = opstack__create();
    assert(opstack__isEmpty(stack) == true);
    Medication *med1 = medication__create("Alfonzo", 100, 67, 90);
    Medication *med2 = medication__create("Caranbulo", 76, 909, 69);
    Operation *op1 = operation__create(med1, "add");
    Operation *op2 = operation__create(med2, "add");
    Operation *op3 = operation__create(med1, "remove");

    medication__destroy(med1);
    medication__destroy(med2);

    opstack__push(stack, op1);
    opstack__push(stack, op2);
    opstack__push(stack, op3);
    operation__destroy(op1);
    operation__destroy(op2);
    operation__destroy(op3);

    assert(opstack__isFull(stack) == false);
    assert(opstack__isEmpty(stack) == false);
    Operation *operation = opstack__pop(stack);
    assert(strcmp(operation__getType(operation), "remove") == 0);
    operation__destroy(operation);
    operation = opstack__pop(stack);
    assert(strcmp(operation__getType(operation), "add") == 0);
    operation__destroy(operation);
    operation = opstack__pop(stack);
    assert(strcmp(operation__getType(operation), "add") == 0);
    operation__destroy(operation);
    assert(opstack__isEmpty(stack) == true);
    opstack__destroy(stack);
}

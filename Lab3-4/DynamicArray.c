//
// Created by sweethuman on 21.03.2020.
//

#include "DynamicArray.h"
#include "domain.h"
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

DynamicArray *dynamicArray__create(int capacity) {
    DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));
    if (array == NULL)
        return NULL;
    array->capacity = capacity;
    array->length = 0;
    array->elems = (TElem *)malloc(sizeof(TElem) * capacity);
    if (array->elems == NULL)
        return NULL;
    return array;
}
void dynamicArray__destroy(DynamicArray *array) {
    if (array == NULL)
        return;
    for (int i = 0; i < array->length; i++) {
        medication__destroy(array->elems[i]);
    }
    free(array->elems);
    array->elems = NULL;
    free(array);
}

bool dynamicArray__resize(DynamicArray *array) {
    if (array == NULL) {
        return false;
    }
    array->capacity *= 2;
    TElem *auxiliary_elements = (TElem *)malloc(array->capacity * sizeof(TElem));
    if (auxiliary_elements == NULL)
        return false;
    for (int i = 0; i < array->length; i++) {
        auxiliary_elements[i] = array->elems[i];
    }
    free(array->elems);
    array->elems = auxiliary_elements;
    return true;
}

void dynamicArray__addElement(DynamicArray *array, TElem elem) {
    if (array == NULL)
        return;
    if (array->elems == NULL)
        return;
    if (array->length == array->capacity)
        dynamicArray__resize(array);
    array->elems[array->length] = elem;
    array->length++;
}
TElem dynamicArray__removeElement(DynamicArray *array, int position) {
    if (array == NULL)
        return NULL;
    if (array->elems == NULL)
        return NULL;
    TElem element = array->elems[position];
    array->length--;
    for (int i = position; i < array->length; i++) {
        array->elems[i] = array->elems[i + 1];
    }
    return element;
}
TElem dynamicArray__getElement(DynamicArray *array, int position) {
    if (array == NULL)
        return NULL;
    if (position < 0 || position >= array->length) {
        return NULL;
    }
    return array->elems[position];
}
int dynamicArray__getLength(DynamicArray *array) {
    if (array == NULL)
        return -1;
    return array->length;
}
DynamicArray *dynamicArray__copy(DynamicArray *array) {
    DynamicArray *copy_array = (DynamicArray *)malloc(sizeof(DynamicArray));
    copy_array->capacity = array->capacity;
    copy_array->length = array->length;
    copy_array->elems = (TElem *)malloc(sizeof(TElem) * array->capacity);
    for (int i = 0; i < copy_array->length; i++) {
        copy_array->elems[i] = medication__copy(array->elems[i]);
    }
    return copy_array;
}
void testDynamicArray() {
    DynamicArray *array = dynamicArray__create(2);
    if (array == NULL) {
        assert(0);
    }
    assert(array->capacity == 2);
    assert(array->length == 0);

    Medication *med1 = medication__create("Albastreaua", 10, 90, 90);
    dynamicArray__addElement(array, med1);
    assert(array->length == 1);

    Medication *med2 = medication__create("Boogaloo", 100, 1, 110);
    dynamicArray__addElement(array, med2);
    assert(array->length == 2);

    Medication *med3 = medication__create("Medoxilatoza", 60, 231, 413);
    dynamicArray__addElement(array, med3);
    assert(array->length == 3);
    assert(array->capacity == 4);

    Medication *med4 = dynamicArray__removeElement(array, 0);
    assert(med1 == med4);
    medication__destroy(med4);
    Medication *med5 = dynamicArray__getElement(array, 0);
    assert(med2 == med5);
    assert(array->length == 2);
    dynamicArray__destroy(array);
    dynamicArray__destroy(NULL);
    assert(dynamicArray__resize(NULL) == false);
    dynamicArray__addElement(NULL, med5);
    assert(dynamicArray__removeElement(NULL, 3) == NULL);
    assert(dynamicArray__getLength(NULL) == -1);
}

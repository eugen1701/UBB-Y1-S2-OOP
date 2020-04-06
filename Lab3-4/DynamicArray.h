//
// Created by sweethuman on 21.03.2020.
//

#include "domain.h"
#ifndef LAB3_4_DYNAMICARRARY_H
#define LAB3_4_DYNAMICARRARY_H
typedef Medication *TElem;
typedef struct {
    TElem *elems;
    int length;
    int capacity;
} DynamicArray;

/// Creates a dynamicArray with memory allocated as big as the capacity
/// \param capacity a number representing the capacity
/// \return The created dynamic array
DynamicArray *dynamicArray__create(int capacity);
/// Frees up all the memory associated with the DynamicArray
/// \param array the array to free up from memory
void dynamicArray__destroy(DynamicArray *array);
/// Creates a copy from the given dynamicArray
/// \param array The array to copy
/// \return The copy of the given array
DynamicArray *dynamicArray__copy(DynamicArray *array);
/// Adds an element to the array
/// !!Doesn't make a copy of the element!!
/// \param array the array to add the element to
/// \param elem the element to add
void dynamicArray__addElement(DynamicArray *array, TElem elem);
/// Removes the element from the array and returns its
/// Isn't responsible for deallocating it's memory
/// \param array The array to remove the element from
/// \param position The position of the element
/// \return The element that was just removed
TElem dynamicArray__removeElement(DynamicArray *array, int position);
/// Returns the element it finds on the specific position
/// \param array The array containing the element
/// \param position The position of the element
/// \return the element or NULL if array is NULL or position is invalid
TElem dynamicArray__getElement(DynamicArray *array, int position);
/// The Length(number of elements) of the array
/// \param array The array to count the elements off
/// \return The number of elements
int dynamicArray__getLength(DynamicArray *array);

void testDynamicArray();

#endif // LAB3_4_DYNAMICARRARY_H

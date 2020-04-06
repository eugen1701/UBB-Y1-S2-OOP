//
// Created by sweethuman on 22.03.2020.
//

#include "DynamicVector.h"
#include "Domain.h"
template <class T>
DynamicVector<T>::DynamicVector(int capacity) {
    this->size = 0;
    this->capacity = capacity;
    this->elems = new T[capacity];
}
template <class T>
DynamicVector<T>::DynamicVector(const DynamicVector<T> &v) {
    this->size = v.size;
    this->capacity = v.capacity;
    this->elems = new T[this->capacity];
    for (int i = 0; i < this->size; i++) {
        this->elems[i] = v.elems[i];
    }
}

template <class T>
DynamicVector<T>::~DynamicVector() {
    delete[] this->elems;
}

template <class T>
DynamicVector<T> &DynamicVector<T>::operator=(const DynamicVector<T> &v) {
    if (this == &v) {
        return *this;
    }

    this->size = v.size;
    this->capacity = v.capacity;
    delete[] this->elems;
    this->elems = new T[this->capacity];
    for (int i = 0; i < this->size; i++) {
        this->elems[i] = v.elems[i];
    }
    return *this;
}
template <class T>
void DynamicVector<T>::add(const T &e) {
    if (this->size == this->capacity) {
        this->resize();
    }
    this->elems[this->size] = e;
    this->size++;
}
template <class T>
void DynamicVector<T>::resize(const int factor) {
    this->capacity *= factor;

    T *elements = new T[this->capacity];
    for (int i = 0; i < this->size; i++) {
        elements[i] = this->elems[i];
    }
    delete[] this->elems;
    this->elems = elements;
}

template <class T>
int DynamicVector<T>::getSize() const {
    return this->size;
}
template <class T>
T DynamicVector<T>::get(int position) const {
    return this->elems[position];
}
template <class T>
T DynamicVector<T>::pop(int pos) {
    auto element = this->elems[pos];
    for (int i = pos; i < this->size - 1; i++) {
        this->elems[i] = this->elems[i + 1];
    }
    this->size--;
    return element;
}
template <class T>
T &DynamicVector<T>::operator[](int position) {
    return this->elems[position];
}

template class DynamicVector<Dog>;
template class DynamicVector<int>;

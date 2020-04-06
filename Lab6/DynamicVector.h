//
// Created by sweethuman on 22.03.2020.
//

#ifndef LAB5_DYNAMICVECTOR_H
#define LAB5_DYNAMICVECTOR_H
template <typename T>
class DynamicVector {
  private:
    T *elems;
    int size;
    int capacity;

  public:
    explicit DynamicVector(int capacity = 10);
    DynamicVector(const DynamicVector<T> &v);
    ~DynamicVector();

    class iterator {
      public:
        explicit iterator(T *ptr) : pointer(ptr) {}
        iterator operator++() {
            pointer++;
            return *this;
        }
        iterator operator++(int junk) {
            pointer+=junk;
            return *this;
        }
        T &operator*() { return *pointer; }
        T *operator->() { return pointer; }
        bool operator==(const iterator &other) const { return pointer == other.pointer; }
        bool operator!=(const iterator &other) const { return pointer != other.pointer; }

      private:
        T *pointer;
    };

    DynamicVector &operator=(const DynamicVector<T> &v);
    /// Returns the Element on the Specified Position.
    /// Position has to be a valid
    /// \param position a valid position in the vector
    /// \return The Found Element
    T &operator[](int position);
    /// Adds a new elemnt to the dynamic vector.
    /// Doesn't care about anything, it just adds
    /// \param e the elemnt to add
    void add(const T &e);
    /// Removes the element from the DynamicVector and returns it
    /// \param pos The position of the elemnt to remove in the vector
    /// \return The Removed element
    T pop(int pos);
    /// Return the Size of the DynamicVector
    /// \return a number that represents the number of elements
    [[nodiscard]] int getSize() const;
    T get(int position) const;

    iterator begin() const {
        return iterator(elems);
    }

    iterator end() const {
        return iterator(elems + size);
    }

  private:
    /// Increases the of memory allocated for the vector by a factor
    /// \param factor The factor to multiply the previous capacity with, by default it is 2
    void resize(int factor = 2);
};

template <typename T>
DynamicVector<T>::DynamicVector(int capacity) {
    this->size = 0;
    this->capacity = capacity;
    this->elems = new T[capacity];
}
template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector<T> &v) {
    this->size = v.size;
    this->capacity = v.capacity;
    this->elems = new T[this->capacity];
    for (int i = 0; i < this->size; i++) {
        this->elems[i] = v.elems[i];
    }
}

template <typename T>
DynamicVector<T>::~DynamicVector() {
    delete[] this->elems;
}

template <typename T>
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
template <typename T>
void DynamicVector<T>::add(const T &e) {
    if (this->size == this->capacity) {
        this->resize();
    }
    this->elems[this->size] = e;
    this->size++;
}
template <typename T>
void DynamicVector<T>::resize(const int factor) {
    this->capacity *= factor;

    T *elements = new T[this->capacity];
    for (int i = 0; i < this->size; i++) {
        elements[i] = this->elems[i];
    }
    delete[] this->elems;
    this->elems = elements;
}

template <typename T>
int DynamicVector<T>::getSize() const {
    return this->size;
}
template <typename T>
T DynamicVector<T>::get(int position) const {
    return this->elems[position];
}
template <typename T>
T DynamicVector<T>::pop(int pos) {
    auto element = this->elems[pos];
    for (int i = pos; i < this->size - 1; i++) {
        this->elems[i] = this->elems[i + 1];
    }
    this->size--;
    return element;
}
template <typename T>
T &DynamicVector<T>::operator[](int position) {
    return this->elems[position];
}

#endif // LAB5_DYNAMICVECTOR_H

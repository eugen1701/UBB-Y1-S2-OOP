//
// Created by sweethuman on 22.03.2020.
//

#ifndef LAB5_DYNAMICVECTOR_H
#define LAB5_DYNAMICVECTOR_H
template <class T>
class DynamicVector {
  private:
    T *elems;
    int size;
    int capacity;

  public:
    explicit DynamicVector(int capacity = 10);
    DynamicVector(const DynamicVector<T> &v);
    ~DynamicVector();

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

  private:
    /// Increases the of memory allocated for the vector by a factor
    /// \param factor The factor to multiply the previous capacity with, by default it is 2
    void resize(int factor = 2);
};
#endif // LAB5_DYNAMICVECTOR_H

//
// Created by Teodora Dan on 2019-03-30.
//

#ifndef LAB5_DYNAMICVECTORTEMPLATE_H
#define LAB5_DYNAMICVECTORTEMPLATE_H

#endif //LAB5_DYNAMICVECTORTEMPLATE_H

#pragma once
#include <iterator>

template <typename T>
class DynamicVector
{
private:
    T* elements;
    int size;
    int capacity;

public:
    // default constructor for a DynamicVector
    DynamicVector(int dynamicVector_capacity = 10);

    // copy constructor for a DynamicVector
    DynamicVector(const DynamicVector& v);
    ~DynamicVector();

    // assignment operator for a DynamicVector
    DynamicVector& operator=(const DynamicVector& v);

    /*
        Overloading the subscript operator
        Input: pos - a valid position within the vector.
        Output: a reference to the element o position pos.
    */
    // operator[]

    // Adds an element to the current DynamicVector.
    void add(const T& e);

    int getSize() const;
    void setSize(int s) { size = s; }

private:
    // Resizes the current DynamicVector, multiplying its capacity by a given factor (real number).
    void resize(double factor = 2);

public:
    class iterator
    {
    private:
        T* ptr;
    public:
        // constructor with parameter T*
        // operator++ - pre-incrementing
        // operator++ - post-incrementing
        // dereferencing operator
        // operator!=
    };

    iterator begin()
    {
        // TODO
    }

    iterator end()
    {
        // TODO
    }
};

template <typename T>
DynamicVector<T>::DynamicVector(int dynamicVector_capacity)
{
    this->size = 0;
    this->capacity = dynamicVector_capacity;
    this->elements = new T[dynamicVector_capacity];
}

template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector<T>& v)
{
    this->size = v.size;
    this->capacity = v.capacity;
    this->elements = new T[this->capacity];
    for (int i = 0; i < this->size; i++)
        this->elements[i] = v.elements[i];
}

template <typename T>
DynamicVector<T>::~DynamicVector()
{
    delete[] this->elements;
}

template <typename T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector<T>& v)
{
    if (this == &v)
        return *this;

    this->size = v.size;
    this->capacity = v.capacity;

    delete[] this->elements;
    this->elements = new T[this->capacity];
    for (int i = 0; i < this->size; i++)
        this->elements[i] = v.elements[i];

    return *this;

}

template <typename T>
void DynamicVector<T>::add(const T& e)
{
    if (this->size == this->capacity)
        this->resize();
    this->elements[this->size] = e;
    this->size++;
}

template <typename T>
void DynamicVector<T>::resize(double factor)
{
    this->capacity *= static_cast<int>(factor);

    T* els = new T[this->capacity];
    for (int i = 0; i < this->size; i++)
        els[i] = this->elements[i];

    delete[] this->elements;
    this->elements = els;
}

template <typename T>
int DynamicVector<T>::getSize() const
{
    return this->size;
}
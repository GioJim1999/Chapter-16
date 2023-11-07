#pragma once
#include<iostream>
#include<new>
#include<cstdlib>

template <class T>
class SimpleVector
{
private:
    T* aptr;
    int arraySize;
    void memError();
    void subError();

public:
    //Default Constructor:
    SimpleVector()
    {
        aptr = 0;
        arraySize = 0;
    };

    //Constructor Declaration:
    SimpleVector(int s);

    //Copy Constructor:
    SimpleVector(const SimpleVector&);

    //Destructor:
    ~SimpleVector();

    //Accessor to return the array size:
    int size() const
    {
        return arraySize;
    };

    //Accessor to return specific element
    T getElementAt(int position);

    void push_back(int item)
    {
        
    }

    //T pop_back();

    //Overloaded [] operator:
    T& operator[] (const int&);
};

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
    arraySize = s;

    try
    {
        aptr = new T[s];
    }
    catch (bad_alloc)
    {
        memError();
    }

    for (int i = 0; i < arraySize; i++)
    {
        *(aptr + i) = 0;
    }
}

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector& obj)
{
    arraySize = obj.arraySize;

    aptr = new T[arraySize];
    if (aptr == 0)
        memError();

    for (int count = 0; count < obj.arraySize; count++)
        *(aptr + count) = *(obj.aptr + count);
}

template <class T>
SimpleVector<T>::~SimpleVector()
{
    if (arraySize > 0)
        delete[] aptr;
}

template <class T>
void SimpleVector<T>::memError()
{
    cout << "\n\tERROR: Cannot allocate memory.\n";
}

template <class T>
void SimpleVector<T>::subError()
{
    cout << "\n\tERROR: Subscript out of range!\n";
}

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
    if (sub < 0 || sub > arraySize)
        subError();
    else
        return aptr[sub];
}

template <class T>
T& SimpleVector<T>::operator[] (const int& sub)
{
    if (sub < 0 || sub > arraySize)
        subError();
    else
        return aptr[sub];
}
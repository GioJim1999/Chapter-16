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


    void push_back(T item)
    {
        T* tempPtr1 = new T[arraySize + 1];
        T* tempPtr2 = nullptr;

        for (int i = 0; i < arraySize; i++)
            *(tempPtr1 + i) = *(aptr + i);

        tempPtr1[arraySize] = item;

        arraySize++;

        //swap the arrays
        tempPtr2 = aptr;
        aptr = tempPtr1;
        tempPtr1 = tempPtr2;
        tempPtr2 = nullptr;

        //Delete old array.
        delete[] tempPtr1;
    }

    void pop_back()
    {
        T* tempPtr1 = new T[arraySize - 1]; 
        T* tempPtr2 = nullptr;

        for (int i = 0; i < arraySize - 1; i++)
            *(tempPtr1 + i) = *(aptr + i);

        //swap arrays
        tempPtr2 = aptr;
        aptr = tempPtr1;
        tempPtr1 = tempPtr2;
        tempPtr2 = nullptr;

        //Delete old array:
        delete[] tempPtr1;
    }

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
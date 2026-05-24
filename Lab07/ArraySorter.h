// COS30008, Tutorial 6, 2026

#pragma once

#include <cstdint>
#include <iostream>
#include <cassert>

template<typename T>
class ArraySorter
{
public:

    ArraySorter(const T aArray[] = nullptr, size_t aSize = 0) noexcept;

    virtual ~ArraySorter() noexcept;

    size_t size() const noexcept;
    size_t swapCount() const noexcept;

    void swap(T& aLeft, T& aRight) noexcept;

    T& operator[](size_t aIndex) const noexcept;

    virtual void sort(bool aDoLog = false, std::ostream& aOStream = std::cout) noexcept;

    template<typename U>
    friend std::ostream& operator<<(std::ostream& aOStream, const ArraySorter<U>& aSorter);

private:

    T* fElements;
    size_t fSize;
    size_t fSwapCount;
};

// ----- Implementation -----

template<typename T>
ArraySorter<T>::ArraySorter(const T aArray[], size_t aSize) noexcept
    : fSize(aSize), fSwapCount(0)
{
    if (aArray != nullptr && aSize > 0)
    {
        fElements = new T[aSize];
        for (size_t i = 0; i < aSize; i++)
            fElements[i] = aArray[i];
    }
    else
    {
        fElements = nullptr;
        fSize = 0;
    }
}

template<typename T>
ArraySorter<T>::~ArraySorter() noexcept
{
    delete[] fElements;
}

template<typename T>
size_t ArraySorter<T>::size() const noexcept
{
    return fSize;
}

template<typename T>
size_t ArraySorter<T>::swapCount() const noexcept
{
    return fSwapCount;
}

template<typename T>
void ArraySorter<T>::swap(T& aLeft, T& aRight) noexcept
{
    T lTemp = aLeft;
    aLeft = aRight;
    aRight = lTemp;
    fSwapCount++;
}

template<typename T>
T& ArraySorter<T>::operator[](size_t aIndex) const noexcept
{
    assert(aIndex < fSize);
    return fElements[aIndex];
}

template<typename T>
void ArraySorter<T>::sort(bool aDoLog, std::ostream& aOStream) noexcept
{
    fSwapCount = 0;
}

template<typename U>
std::ostream& operator<<(std::ostream& aOStream, const ArraySorter<U>& aSorter)
{
    aOStream << "[";
    for (size_t i = 0; i < aSorter.fSize; i++)
    {
        if (i > 0)
            aOStream << ",";
        aOStream << aSorter.fElements[i];
    }
    aOStream << "]";
    return aOStream;
}
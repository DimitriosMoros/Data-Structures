
// COS30008, Tutorial 6, 2026

#pragma once

#include "ArraySorter.h"

#include <cstdlib>
#include <ctime>

template<typename T, typename Order = std::greater<T>>
class FisherAndYatesSorter : public ArraySorter<T>
{
private:
    
    Order fOrderFtn;
    
    void shuffle() noexcept;
    
    bool isSorted() noexcept;
    
public:
    
    FisherAndYatesSorter( const T aArray[] = nullptr, size_t aSize = 0 ) noexcept;

    void sort( bool aDoLog = false, std::ostream& aOStream = std::cout ) noexcept override;
};

template<typename T, typename Order>
inline void FisherAndYatesSorter<T, Order>::shuffle() noexcept

{
    size_t n = this->size();
    
    while (n > 1)
    {
        size_t k = std::rand() % n;
        n--;
        this->swap(this->operator[](n), this->operator[](k));
	}
}

template<typename T, typename Order>
inline bool FisherAndYatesSorter<T, Order>::isSorted() noexcept
{
    return false;
}

template<typename T, typename Order>
inline FisherAndYatesSorter<T, Order>::FisherAndYatesSorter(const T aArray[], size_t aSize) noexcept
    : ArraySorter<T>(aArray, aSize), fOrderFtn(Order())
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

template<typename T, typename Order>
inline void FisherAndYatesSorter<T, Order>::sort(bool aDoLog, std::ostream& aOStream) noexcept
{
    this->ArraySorter<T>::sort();
    while (true)
    { 
        if (aDoLog) {
			aOStream << *this << std::endl;
        }

        if (isSorted()) {
            break;


        }
        shuffle();
    }
}

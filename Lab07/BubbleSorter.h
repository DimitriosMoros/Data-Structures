
// COS30008, Tutorial 6, 2026

#pragma once

#include "ArraySorter.h"

template<typename T, typename Order = std::greater<T>>
class BubbleSorter : public ArraySorter<T>
{
private:
    
    Order fOrderFtn;
    
public:
    
    BubbleSorter( const T aArray[] = nullptr, size_t aSize = 0 ) noexcept;

    void sort( bool aDoLog = false, std::ostream& aOStream = std::cout ) noexcept override;
};

template<typename T, typename Order>
inline BubbleSorter<T, Order>::BubbleSorter(const T aArray[], size_t aSize) noexcept
	: ArraySorter<T>(aArray, aSize), fOrderFtn(Order())
{
}

template<typename T, typename Order>
inline void BubbleSorter<T, Order>::sort(bool aDoLog, std::ostream& aOStream) noexcept
{
    this->ArraySorter<T>::sort();

	size_t n = this->size();


    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = 0; j < n - i - 1; j++)
        {
            if (fOrderFtn(this->operator[](j), this->operator[](j + 1)))
            {
                this->swap(this->operator[](j), this->operator[](j + 1));
            }
     
        
        }

        if (aDoLog)
        {
            aOStream << "After pass " << i + 1 << ": " << *this << std::endl;
		}
	}
}

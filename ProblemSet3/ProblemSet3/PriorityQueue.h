
// COS30008 - Problem Set 3, 2026

#pragma once

#include "SortablePair.h"

#include <optional>
#include <cassert>
#include <algorithm>

template<typename T, typename P>
class PriorityQueue
{
public:
    
    using value_type = SortablePair<P, T>;
    
    PriorityQueue() noexcept;
    
    ~PriorityQueue() noexcept;
    
    PriorityQueue( const PriorityQueue& ) = delete;
    PriorityQueue& operator=( const PriorityQueue& ) = delete;

    size_t count() const noexcept;
    size_t capacity() const noexcept;
    
    std::optional<T> top() const noexcept;    
    void push( const T& aValue, const P& aPriority ) noexcept;
    void pop() noexcept;
    
private:
    
    value_type* fElements;
    size_t fHead;
    size_t fTail;
    size_t fCapacity;
    
    void sort() noexcept
    {
        std::sort( &fElements[fHead], &fElements[fTail] );
    }
    
    void resize( size_t aCapacity );
    void ensure_capacity();
    void adjust_capacity();
};

template<typename T, typename P>
PriorityQueue<T, P>::PriorityQueue() noexcept
    : fElements(static_cast<value_type*>(::operator new(sizeof(value_type)))),
    fHead(0),
    fTail(0),
    fCapacity(1)
{
}

template<typename T, typename P>
PriorityQueue<T, P>::~PriorityQueue() noexcept
{
    for (size_t i = fHead; i < fTail; i++)
    {
        fElements[i].~value_type();
    }
    ::operator delete(fElements);
}

template<typename T, typename P>
size_t PriorityQueue<T, P>::count() const noexcept
{
    return fTail - fHead;
}

template<typename T, typename P>
size_t PriorityQueue<T, P>::capacity() const noexcept
{
    return fCapacity;
}

template<typename T, typename P>
std::optional<T> PriorityQueue<T, P>::top() const noexcept
{
    if (count() == 0)
    {
        return std::nullopt;
    }
    return fElements[fHead].second();
}

template<typename T, typename P>
void PriorityQueue<T, P>::resize(size_t aCapacity)
{
    value_type* lNewElements = static_cast<value_type*>(::operator new(aCapacity * sizeof(value_type)));

    size_t lCount = count();

    for (size_t i = 0; i < lCount; i++)
    {
        new (&lNewElements[i]) value_type(fElements[i + fHead]);
        fElements[i + fHead].~value_type();
    }

    ::operator delete(fElements);

    fElements = lNewElements;
    fHead = 0;
    fTail = lCount;
    fCapacity = aCapacity;
}

template<typename T, typename P>
void PriorityQueue<T, P>::ensure_capacity()
{
    if (fTail == fCapacity)
    {
        resize(fCapacity * 2);
    }
}

template<typename T, typename P>
void PriorityQueue<T, P>::adjust_capacity()
{
    if (fCapacity > 1 && count() * 4 <= fCapacity)
    {
        size_t lNewCapacity = fCapacity / 2;
        if (lNewCapacity < 1) lNewCapacity = 1;
        resize(lNewCapacity);
    }
}

template<typename T, typename P>
void PriorityQueue<T, P>::push(const T& aValue, const P& aPriority) noexcept
{
    ensure_capacity();
    new (&fElements[fTail++]) value_type(aPriority, aValue);
    std::stable_sort(&fElements[fHead], &fElements[fTail]);
}

template<typename T, typename P>
void PriorityQueue<T, P>::pop() noexcept
{
    assert(count() > 0);
    fElements[fHead].~value_type();
    fHead++;
    adjust_capacity();
}
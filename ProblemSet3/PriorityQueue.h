
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

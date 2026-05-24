
// COS30008 - Problem Set 3, 2026

#pragma once

#include <ostream>

template<typename K, typename V>
class SortablePair
{
public:
    
    SortablePair( const K& aFirst = K{}, const V& aSecond = V{} ) noexcept;
    
    const K& first() const noexcept;
    const V& second() const noexcept;

    bool operator==( const SortablePair& aOther ) const noexcept;
    
    bool operator<( const SortablePair& aOther ) const noexcept;
    
    friend std::ostream& operator<<( std::ostream& aOStream, const SortablePair<K,V>& aPair );
    
private:
    
    K fFirst;
    V fSecond;
};


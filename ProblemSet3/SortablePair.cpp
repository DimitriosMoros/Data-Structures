#include "SortablePair.h"

SortablePair::SortablePair(const K& aFirst = K{}, const V& aSecond = V{}) noexcept :
{

}

const K& SortablePair::first() const noexcept {

}
const V& SortablePair::second() const noexcept {
	
}

bool SortablePair::operator==(const SortablePair& aOther) const noexcept {

}

bool operator<(const SortablePair& aOther) const noexcept;

friend std::ostream& operator<<(std::ostream& aOStream, const SortablePair<K, V>& aPair);
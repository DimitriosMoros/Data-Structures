#include "AutoCaesarIterator.h"


AutoCaesarIterator::AutoCaesarIterator(const char aInt[KEY_LENGTH],
	const std::string* aCollection) noexcept:
	fCollection(aCollection),
	fInt(aInt),
	fKey(aInt),
	fIndex(0)
{

}

AutoCaesarIterator::value_type AutoCaesarIterator::operator*() const noexcept 
{
	char lResult = fInt[fIndex];
	if (std::isalpha(lResult))
	{
		bool lIsLower = std::islower(lResult) != 0;
		lResult = std::toupper(lResult);
		lResult += (char)*fKey;
		if (lResult > 'Z')
		{
			lResult -= 26;
		}

	}	

	return lResult;
}

AutoCaesarIterator::iterator& AutoCaesarIterator::operator++() noexcept
{
	char lCurrent = (*this).operator*();
	if (std::isalpha(lCurrent))
	{
		fKey += lCurrent;
		fKey++;
	}

	fIndex++;
	return* this;
}
AutoCaesarIterator::iterator AutoCaesarIterator::operator++(int) noexcept {
	iterator lTemp = *this;
	++(*this);
	return lTemp;
}

bool AutoCaesarIterator::operator ==(const iterator& aOther) const noexcept
{
	return fCollection == aOther.fCollection 
			&& fInt == aOther.fInt 
		&& fIndex == aOther.fIndex;
}

AutoCaesarIterator::iterator AutoCaesarIterator::begin() const noexcept
{
	iterator lBegin = *this;
	lBegin.fIndex = 0;
	lBegin.fKey = KeyIterator<KEY_LENGTH>(fInt);

	return lBegin;
}
AutoCaesarIterator::iterator AutoCaesarIterator::end() const noexcept
{
	iterator lEnd = *this;
	lEnd.fIndex = fCollection->size();
	return lEnd;
}
#include "AutoCaesarIterator.h"

AutoCaesarIterator::AutoCaesarIterator(const char aInit[KEY_LENGTH],
    const std::string* aCollection) noexcept :
    fCollection(aCollection),
    fKeys(aInit),
    fInit(aInit),
    fIndex(0)
{

}

AutoCaesarIterator::value_type AutoCaesarIterator::operator*() const noexcept 
{
    char lResult = fInit[fIndex];

    if (std::isalpha(lResult))
    {
        bool lIsLower = std::islower(lResult) != 0;
        lResult = std::toupper(lResult);
        lResult = (char)*fKeys;

        if (lResult > 'Z')
        {
            lResult -= 26;
        }

        if (lIsLower != 0)
        {
            lResult = std::tolower(lResult);
        }

    }

    return lResult;
}

AutoCaesarIterator::iterator& AutoCaesarIterator::operator++() noexcept 
{
    
    char lCurrent = (*this).operator*();
    if (std::isalpha(lCurrent))
    {
        fKeys += lCurrent;
        fKeys++;

    }
    fIndex++;
    return *this;

    
}
AutoCaesarIterator::iterator AutoCaesarIterator::operator++(int) noexcept 
{
    iterator  lCurrent= *this;
    (*this)++;
    return lCurrent;
}

bool AutoCaesarIterator::operator==(const iterator& aOther) const noexcept 
{
    return fCollection == aOther.fCollection &&
           fInit == aOther.fInit &&
           fIndex == aOther.fIndex;
}

AutoCaesarIterator::iterator AutoCaesarIterator::begin() const noexcept
{
    iterator lBegin = *this;
    lBegin.fKeys = KeyIterator<KEY_LENGTH>(fInit);
    lBegin.fIndex = 0;
    return lBegin;
    

}
AutoCaesarIterator::iterator AutoCaesarIterator::end() const noexcept
{
    iterator lEnd = *this;
    lEnd.fIndex = fCollection->size();
    return lEnd;
    
}



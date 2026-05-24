#include "FibonacciSequenceIterator.h"

FibonacciSequenceIterator::FibonacciSequenceIterator(FibonacciSequence* aSequence,
                                                    uint64_t aStart) noexcept:
	fSequence(aSequence), fIndex(aStart)
{

}


const uint64_t& FibonacciSequenceIterator::operator*() const noexcept
{
    return **fSequence;
}
FibonacciSequenceIterator& FibonacciSequenceIterator::operator++() noexcept
{ 
	++(*fSequence);
    fIndex++;
	return *this;
}
FibonacciSequenceIterator FibonacciSequenceIterator::operator++(int) noexcept
{
    FibonacciSequenceIterator temp = *this;
    ++(*this);
    return temp;
}

bool FibonacciSequenceIterator::operator==(const FibonacciSequenceIterator& aOther) const noexcept
{
    return fSequence == aOther.fSequence && fIndex == aOther.fIndex;
}

FibonacciSequenceIterator FibonacciSequenceIterator::begin() const noexcept
{
	fSequence->begin();
    return FibonacciSequenceIterator(fSequence, 1);
}

FibonacciSequenceIterator FibonacciSequenceIterator::end() const noexcept 
{
	return FibonacciSequenceIterator(fSequence, MAX_FIBONACCI + 1);
}
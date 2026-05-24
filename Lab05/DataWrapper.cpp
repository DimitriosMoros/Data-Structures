#include "DataWrapper.h"
#include <cassert>
#include <fstream>



DataWrapper::DataWrapper() :
	fSize(0),
	fData(nullptr)
{
	
}
DataWrapper::~DataWrapper() 
{
	delete[] fData;
}


std::istream& operator>>(std::istream& aIStream, Map<size_t, size_t>& aMap)
{
	aIStream >> aMap.fKey >> aMap.fValue;
	return aIStream;
}

bool DataWrapper ::load(const std::string& aFileName)
{
	std::ifstream lInput(aFileName);
	if (lInput.good())
	{
		lInput >> fSize;
		if (fSize != 0)
		{
			fData = new DataMap[fSize];

			for (size_t i = 0; i < fSize; i++)
			{
				lInput >> fData[i];
			}
		}
		return true;
	}
	return false;
}

size_t DataWrapper::size() const noexcept
{
	return fSize;
}
const DataMap& DataWrapper ::operator[](size_t aIndex) const
{
	assert(aIndex < fSize);
	return fData[aIndex];
}

void DataWrapper::apply(const std::function<void(size_t)>& aFunction) const noexcept
{
	for (size_t i = 0; i < fSize; i++)
	{
		aFunction(i);
	}
	
}
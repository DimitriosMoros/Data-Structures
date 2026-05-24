
#include <iostream>

//#define Naive

#ifdef Naive

void printIntArray(int aArray[], size_t aSize)
{
	std::cout << '[';

	for (size_t i = 0; i < aSize; )
	{
		std::cout << aArray[i];

		if (++i < aSize)
		{
			std::cout << ", ";
		}
	}

	std::cout << ']' << std::endl;
}

#else

void printIntArray(int aArray[], size_t aSize)
{
	std::cout << '[';

	if (aSize > 0)
	{
		std::cout << aArray[0];

		for (size_t i = 1; i < aSize; ++i)
		{
			std::cout << ", " << aArray[i];
		}
	}

	std::cout << ']' << std::endl;
}

#endif // Naive


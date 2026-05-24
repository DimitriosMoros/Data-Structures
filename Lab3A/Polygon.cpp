// COS30008, Tutorial 3, 2026

#include "Polygon.h"
#include <cassert>

Polygon::Polygon() noexcept : fNumberOfVertices(0)
{
}

void Polygon::readData(std::istream& aIStream)
{
    Vector2D lVertex;

    // Read vertices until end-of-file or array is full
    while (aIStream >> lVertex && fNumberOfVertices < MAX_VERTICES)
    {
        fVertices[fNumberOfVertices] = lVertex;
        fNumberOfVertices++;
    }
}

// Bug fix: was returning size_t() (i.e. 0) instead of fNumberOfVertices
size_t Polygon::getNumberOfVertices() const noexcept
{
    return fNumberOfVertices;
}

const Vector2D& Polygon::getVertex(size_t aIndex) const
{
    assert(aIndex < fNumberOfVertices);
    return fVertices[aIndex];
}


float Polygon::getPerimeter() const noexcept
{
    float Result = 0.0f;

    for (size_t i = 0; i < fNumberOfVertices; i++)
    {
        // Next vertex index wraps around using modulus
        size_t next = (i + 1) % fNumberOfVertices;
        Result += (fVertices[next] - fVertices[i]).length();
    }

    return Result;
}

Polygon Polygon::scale(float aScalar) const noexcept
{
    Polygon Result = *this;

    for (size_t i = 0; i < fNumberOfVertices; i++)
    {
        Result.fVertices[i] = fVertices[i] * aScalar;
    }

    return Result;
}
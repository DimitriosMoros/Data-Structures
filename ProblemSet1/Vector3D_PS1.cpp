#include "Vector3D.h"
#include <cmath>
#include <sstream>



bool Vector3D::operator==(const Vector3D& aOther) const noexcept
{
	float lCompX = std::fabs(x() - aOther.x());
	float lCompY= std::fabs(y() - aOther.y());
	float lCompW= std::fabs(w() - aOther.w());
	
	return lCompX <= eps && lCompY <= eps && lCompW <= eps;
}


std::string Vector3D::toString() const noexcept
{
    std::stringstream lStream;

    lStream << "[" << x() << "," << y() << "," << w() << "]";

    return lStream.str();
}
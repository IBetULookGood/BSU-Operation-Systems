#include"Vector.h"

Vector::Vector(Number n1, Number n2) {
    X = n1;
    Y = n2;
}

Vector Vector::VectorMultiply(Vector v)
{
    return Vector(this->X * v.Y,this->Y * v.Y);
}

Number Vector::getR() {
    return Number(sqrt(pow(this->X.getValue(), 2) + pow(this->Y.getValue(), 2)));
}

Number Vector::getPhi() {
    return Number(asin(this->Y.getValue() / sqrt(pow(this->X.getValue(), 2) + pow(this->Y.getValue(), 2))));
}

std::ostream& operator <<(std::ostream& out, const Vector& v) {
    out << "Vector(" << Number(v.X).getValue() <<", "<< Number(v.Y).getValue() << ")";
    return out;
}
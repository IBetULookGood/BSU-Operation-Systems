#include"pch.h"
#include"Vector.h"

Vector::Vector(Number n1, Number n2) {
	X = n1;
	Y = n2;
}

Number Vector::getR() {
	return Number(sqrt(pow(this->X.getValue(), 2) + pow(this->Y.getValue(), 2)));
}

Number Vector::getPhi() {
	return Number(asin(this->Y.getValue() / sqrt(pow(this->X.getValue(), 2) + pow(this->Y.getValue(), 2))));//
}


#include"Number.h"
#include<iostream>

Number::Number(double a) {
    this->value = a;
}

double Number::getValue() const {
    return this->value;
}

Number Number::operator+(Number v) const {
    return this->value + v.value;
}

Number Number::operator-(Number v) const {
    return this->value - v.value;
}

Number Number::operator/(Number v) const {
    return this->value / v.value;
}

Number Number::operator*(Number v) const {
    return this->value * v.value;
}

std::ostream& operator<< (std::ostream& out, const Number& n) {
    out << "Number(" << n.value << ")";
    return out;
}

bool Number::operator= (Number n) {
    return this->value = n.value;
}
Number createNumber(double x) {
    return Number(x);
}

#pragma once
#include<iostream>
#include <cmath>
#include<Number.h>


class Vector {
public:
     Vector() = default;
     ~Vector() = default;
     Vector(Number, Number);
     Vector VectorMultiply(Vector);
     Number getR();
     Number getPhi();
     friend std::ostream& operator <<(std::ostream&, const Vector&);

private:
    Number X;
    Number Y;
};

const Vector ZEROVECT(ZERO,ZERO);
const Vector ONEVECT(ONE,ONE);
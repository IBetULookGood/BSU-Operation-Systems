#include <iostream>
#include <Vector.h>


int main() {
    Vector v1(createNumber(10),ZERO);
    Vector v2 = ONEVECT;
    std::cout<<v1.VectorMultiply(v2)<<std::endl;
    std::cout<<v1.getPhi()<<", "<<v1.getR()<<std::endl;

    return 0;
}

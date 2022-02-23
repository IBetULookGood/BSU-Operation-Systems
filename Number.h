#pragma once
#include<string>

class Number {

public:
	Number() = default;
	~Number() = default;
	Number(double);
	double getValue();
	Number operator +(Number);
	Number operator -(Number);
	Number operator /(Number);
	Number operator *(Number);
	bool operator =(Number);
	friend std::ostream& operator <<(std::ostream&, const Number&);

private:
	double value;
};

Number createNumber(double);

const Number ONE(1);
const Number ZERO(0);
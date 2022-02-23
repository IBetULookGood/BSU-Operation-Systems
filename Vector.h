#pragma once
#include"Number.h"
#ifdef VECTORLIB_EXPORTS
#define VECTORLIB_API __declspec(dllexport)
#else
#define VECTORLIB_API __declspec(dllimport)
#endif


class Vector {
public:
	VECTORLIB_API Vector() = default;
	VECTORLIB_API ~Vector() = default;
	VECTORLIB_API Vector(Number, Number);
	VECTORLIB_API Number getR();
	VECTORLIB_API Number getPhi();

private:
	Number X;
	Number Y;
};
const Vector ZEROVECT(ZERO,ZERO);
const Vector ONEVECT(ONE, ONE);
#pragma once
#ifndef MULTITHREADING__MATRIX_H_
#define MULTITHREADING__MATRIX_H_

#include <vector>
#include <ostream>
#include <ctime>
#include <iostream>
#include <random>
#include <exception>

class Matrix
{
public:

	Matrix(int m, int n);
	double GetElement(int i, int j) const;
	void SetElement(double element, int i, int j);
	void IncreaseElement(double value, int i, int j);
	std::pair<int, int> GetSize() const;
	void Generate(double max_value);

private:
	std::vector<std::vector<double>> elements_;
	std::pair<int, int> size_;
};

std::ostream& operator<<(std::ostream& out, const Matrix& matrix);


#endif //MULTITHREADING__MATRIX_H_
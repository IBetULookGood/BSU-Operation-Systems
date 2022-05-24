#include "Matrix.h"
Matrix::Matrix(int m, int n) : elements_(m, std::vector<double>(n, 0)), size_(std::make_pair(m, n)) {}

double Matrix::GetElement(int i, int j) const
{
    if (i < 0 || i >= size_.first || j < 0 || j >= size_.second)
    {
        throw std::range_error("Index out of range");
    }
    return elements_[i][j];
}

std::pair<int, int> Matrix::GetSize() const {
    return size_;
}


void Matrix::Generate(double max_value)
{
    std::mt19937 mt(time(nullptr));
    for (int i = 0; i < size_.first; ++i)
    {
        for (int j = 0; j < size_.second; ++j)
        {
            elements_[i][j] = mt() % (int)(max_value);
        }
    }
}



std::ostream& operator<<(std::ostream& out, const Matrix& matrix)
{
    for (int i = 0; i < matrix.GetSize().first; i++)
    {
        for (int j = 0; j < matrix.GetSize().second; j++)
        {
            out << matrix.GetElement(i, j) << " ";
        }
        out << std::endl;
    }
    return out;
}
void Matrix::SetElement(double element, int i, int j) {
    elements_[i][j] = element;
}
void Matrix::IncreaseElement(double value, int i, int j) {
    elements_[i][j] += value;
}
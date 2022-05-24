#include "Multiplication.h"

MatrixMultiplicator::MatrixMultiplicator()
{
    lock_ = CreateMutex(NULL, FALSE, NULL);
}

MatrixMultiplicator::~MatrixMultiplicator()
{
    CloseHandle(lock_);
}

MatrixMultiplicator::MultiplyBlocksArguments::MultiplyBlocksArguments
(HANDLE lock, Matrix& result_matrix, const Matrix& matrix1, const Matrix& matrix2,
    int rows_amount_1, int columns_amount_1, int rows_amount_2, int columns_amount_2, int block_size) :
    lock_(lock), result_matrix_(result_matrix), matrix1_(matrix1), matrix2_(matrix2),
    rows_amount1_(rows_amount_1), columns_amount1_(columns_amount_1),
    rows_amount2_(rows_amount_2), columns_amount2_(columns_amount_2),
    block_size_(block_size) {}


Matrix MatrixMultiplicator::Multiply(const Matrix& matrix1, const Matrix& matrix2)
{
    if (matrix1.GetSize().second != matrix2.GetSize().first)
    {
        throw std::invalid_argument("Invalid matrix size");
    }
    Matrix result_matrix = Matrix(matrix1.GetSize().first, matrix2.GetSize().second);

    for (int i = 0; i < result_matrix.GetSize().first; i++)
    {
        for (int j = 0; j < result_matrix.GetSize().second; j++)
        {
            for (int k = 0; k < result_matrix.GetSize().second; k++)
            {
                double result_element = matrix1.GetElement(i, k) * matrix2.GetElement(k, j);
                result_matrix.IncreaseElement(result_element, i, j);
            }
        }
    }
    return result_matrix;
}


Matrix MatrixMultiplicator::MultiplyByBlocks(const Matrix& matrix1, const Matrix& matrix2, int blocks_number)
{
    if (matrix1.GetSize().second != matrix2.GetSize().first)
    {
        throw std::invalid_argument("Invalid matrix size");
    }

    if (matrix1.GetSize().first != matrix1.GetSize().second || matrix2.GetSize().first != matrix2.GetSize().second) {
        throw new std::invalid_argument("Matrices are not square");
    }

    if (matrix1.GetSize().first % blocks_number != 0)
    {
        throw std::invalid_argument("Invalid block number");
    }

    int block_size = matrix1.GetSize().first / blocks_number;
    Matrix result_matrix = Matrix(matrix1.GetSize().first, matrix2.GetSize().second);
    std::vector<HANDLE> threads;
    std::vector<MultiplyBlocksArguments*> arguments;
    for (int i = 0; i < result_matrix.GetSize().first; i += block_size)
    {
        for (int j = 0; j < result_matrix.GetSize().second; j += block_size)
        {
            for (int k = 0; k < result_matrix.GetSize().second; k += block_size)
            {
                MultiplyBlocksArguments* argument = new  MultiplyBlocksArguments(lock_, result_matrix, matrix1, matrix2, i, k, k, j, block_size);
                HANDLE thread = CreateThread(NULL, 0, MatrixMultiplicator::MultiplyBlocks, argument, 0, NULL);
                threads.push_back(thread);
                arguments.push_back(argument);
            }
        }
    }
    WaitForMultipleObjects(threads.size(), &threads[0], TRUE, INFINITE);
    for (int i = 0; i < threads.size(); ++i)
    {
        CloseHandle(threads[i]);
        delete arguments[i];
    }
    return result_matrix;
}


DWORD WINAPI MatrixMultiplicator::MultiplyBlocks(LPVOID argument_struct)
{
    MatrixMultiplicator::MultiplyBlocksArguments* argument = (MatrixMultiplicator::MultiplyBlocksArguments*)argument_struct;
    for (int i = argument->rows_amount1_; i < argument->rows_amount1_ + argument->block_size_; i++)
    {
        for (int j = argument->columns_amount2_; j < argument->columns_amount2_ + argument->block_size_; j++)
        {
            double sum = 0.;
            for (int k = 0; k < argument->block_size_; k++)
            {
                sum += argument->matrix1_.GetElement(i, argument->columns_amount1_ + k) * argument->matrix2_.GetElement(argument->rows_amount2_ + k, j);
            }
            WaitForSingleObject(argument->lock_, INFINITE);
            argument->result_matrix_.IncreaseElement(sum, i, j);
            ReleaseMutex(argument->lock_);
        }
    }
    ExitThread(0);
}
#include "Matrix.h"
#include "Multiplication.h"

int main()
{
    int n = 500;
    //Matrix matrix1=Matrix(n,n);
    Matrix matrix1(n, n);
    matrix1.Generate(500);
    //std::cout<<matrix1<<"\n\n";
    Matrix matrix2(n, n);
    matrix2.Generate(500);
    //std::cout<<matrix2<<"\n\n";

    int start = clock();
    MatrixMultiplicator matrix_multiplicator;
    Matrix result_matrix = matrix_multiplicator.Multiply(matrix1, matrix2);
    //std::cout<<result_matrix<<"\n\n";
    int end = clock();
    std::cout << "---------------------------------------------" << "\n";
    std::cout << "Multiplication by elements time: " << end - start << "\n";

    std::cout << "---------------------------------------------" << "\nMultiplication by blocks" << "\n";
    for (int k = 1; k <= 25; k++)
    {
        if (n % k == 0)
        {
            int start = clock();
            result_matrix = matrix_multiplicator.MultiplyByBlocks(matrix1, matrix2, k);
            int end = clock();
            std::cout << "Amount of blocks: " << k << " Time: " << end - start << "\n";
            //std::cout<<result_matrix<<"\n\n";

        }
    }
}
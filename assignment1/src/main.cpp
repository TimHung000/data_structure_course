#include "saddlePoint.h"
#include <cmath>
#include <vector>
#include <cstddef>
#include <list>
#include <string>
#include <utility> // std::pair, std::make_pair
#include <iostream> // FLT_MIN
#include <iomanip>

void printMatrix(std::vector<std::vector<float>> matrix, float minX, float minY, float stepX, float stepY)
{
    std::cout << std::fixed << std::setprecision(4);
    std::cout << std::setw(7) << "x/y" << '|';
    for(size_t col = 0; col < matrix[0].size(); ++col)
    {
        std::cout << std::setw(7) << minY + col * stepY << " ";
    }
    std::cout << "\n" << std::string(8*(matrix[0].size() + 1),'-') << "\n";
    for(size_t row = 0; row < matrix.size(); ++row)
    {
        std::cout << std::setw(7) << minX + row * stepX << "|";

        for(size_t col = 0; col < matrix[row].size(); ++col)
        {
            std::cout << std::setw(7) << matrix[row][col] << " "; 
        }
        std::cout << "\n";
    }
}

void printSaddlePoints(std::vector<elementOfMatrix> saddlePoints, float minX, float minY, float stepX, float stepY)
{
    for(size_t i = 0; i < saddlePoints.size(); ++i)
    {
        std::cout << '(' << minX + saddlePoints[i].xAxis * stepX << ',' << minY + saddlePoints[i].yAxis * stepY << ") " << saddlePoints[i].val << '\n';
    }
}


int main()
{
    SaddlePoint test1(-5, 0.5, 5, -5, 0.5, 5);
    test1.SelectFunction(Function::FUNCTION1);
    test1.GenerateSampleMatrix();
    std::vector<std::vector<float>> matrix1 = test1.GetSampleMatrix();
    std::vector<elementOfMatrix> saddlePoints1 = test1.DetermineSaddlePoints();
    printMatrix(matrix1, test1.GetSampleMinX(), test1.GetSampleMinY(), test1.GetSampleStepX(), test1.GetSampleStepY());
    printSaddlePoints(saddlePoints1, test1.GetSampleMinX(), test1.GetSampleMinY(), test1.GetSampleStepX(), test1.GetSampleStepY());
    std::cout << "\n";


    SaddlePoint test2(-5, 0.5, 5, -5, 0.5, 5);
    test2.SelectFunction(Function::FUNCTION2);
    test2.GenerateSampleMatrix();
    std::vector<std::vector<float>> matrix2 = test2.GetSampleMatrix();
    std::vector<elementOfMatrix> saddlePoints2 = test2.DetermineSaddlePoints();    
    printMatrix(matrix2, test2.GetSampleMinX(), test2.GetSampleMinY(), test2.GetSampleStepX(), test2.GetSampleStepY());
    printSaddlePoints(saddlePoints2, test2.GetSampleMinX(), test2.GetSampleMinY(), test2.GetSampleStepX(), test2.GetSampleStepY());
    std::cout << "\n";

    SaddlePoint test3(-3, 0.5, 3, -3, 0.5, 3);
    test3.SelectFunction(Function::FUNCTION3);
    test3.GenerateSampleMatrix();
    std::vector<std::vector<float>> matrix3 = test3.GetSampleMatrix();
    std::vector<elementOfMatrix> saddlePoints3 = test3.DetermineSaddlePoints();
    printMatrix(matrix3, test3.GetSampleMinX(), test3.GetSampleMinY(), test3.GetSampleStepX(), test3.GetSampleStepY());
    printSaddlePoints(saddlePoints3, test3.GetSampleMinX(), test3.GetSampleMinY(), test3.GetSampleStepX(), test3.GetSampleStepY());
    std::cout << "\n";

    return 0;
}
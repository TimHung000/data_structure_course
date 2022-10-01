/**
 * Find the saddle points based on chosen function and parameters
 * 
 * 
 * @class_hw: NSYSU_Data_Structure assignment1
 * @author Hao Yu Hung
 * @date   2022/10/01
 * 
 */ 

#include "saddlePoint.h"
#include <cmath>
#include <vector>
#include <cstddef>
#include <list>
#include <string>
#include <utility> // std::pair, std::make_pair
#include <iostream> // FLT_MIN
#include <iomanip>

float function1(float x, float y)
{
    return y * std::sin(x) - x * std::cos(y);
}

float function2(float x, float y)
{
    return -std::cos(x) + std::sin(y);
}

float function3(float x, float y)
{
    return std::sqrt(std::pow(x, 2) + std::pow(y, 2)); 
}

SaddlePoint::SaddlePoint()
{
    matrix = {
        {10,12,7,3,12},
        {3,10,6,2,8},
        {18,24,17,6,10},
        {15,21,10,8,12},
        {1,18,22,4,15}
    };
}

SaddlePoint::SaddlePoint(float minX, float stepX, float maxX, float minY, float stepY, float maxY)
{
    _minX = minX;
    _stepX = stepX;
    _maxX = maxX;
    _minY = minY;
    _stepY = stepY;
    _maxY = maxY;

    int xAxisLen = (_maxX - _minX) / _stepX + 1;
    int yAxisLen = (_maxX - _minY) / _stepY + 1;
    
    matrix.resize(xAxisLen);
    for(int i = 0; i < xAxisLen; ++i)
    {
        matrix[i].resize(yAxisLen);
    }
}

SaddlePoint::~SaddlePoint() {}

void SaddlePoint::SelectFunction(Function n)
{
    switch (n)
    {
    case Function::FUNCTION1:
        funcPtr = &function1;
        break;
    case Function::FUNCTION2:
        funcPtr = &function2;
        break;
    case Function::FUNCTION3:
        funcPtr = &function3;
        break;
    default:
        funcPtr = &function1;
        break;
    }
}
void SaddlePoint::SetSampleMinX(float minX)
{
    _minX = minX;
}
void SaddlePoint::SetSampleStepX(float stepX)
{
    _stepX = stepX;
}
void SaddlePoint::SetSampleMaxX(float maxX)
{
    _maxX = maxX;
}
void SaddlePoint::SetSampleMinY(float minY)
{
    _minY = minY;
}
void SaddlePoint::SetSampleStepY(float stepY)
{
    _stepY = stepY;
}
void SaddlePoint::SetSampleMaxY(float maxY)
{
    _maxY = maxY;
}
float SaddlePoint::GetSampleMinX() { return _minX; }
float SaddlePoint::GetSampleStepX() { return _stepX; }
float SaddlePoint::GetSampleMaxX() { return _maxX; }
float SaddlePoint::GetSampleMinY() { return _minY; }
float SaddlePoint::GetSampleStepY() { return _stepY; }
float SaddlePoint::GetSampleMaxY() { return _maxY; }
void SaddlePoint::GenerateSampleMatrix()
{
    int xAxisLen = (_maxX - _minX) / _stepX + 1;
    int yAxisLen = (_maxX - _minY) / _stepY + 1;
    
    // create matrix based on the given range
    matrix.resize(xAxisLen);
    for(int i = 0; i < xAxisLen; ++i)
    {
        matrix[i].resize(yAxisLen);
    }

    // calculate the value
    float x;
    float y;
    for(int i = 0; i < xAxisLen; ++i)
    {
        x = _minX + i * _stepX;
        for(int j = 0; j < yAxisLen; ++j)
        {
            y = _minY + j * _stepY;
            matrix[i][j] = funcPtr(x, y);
        }
    }
}
std::vector<std::vector<float>> SaddlePoint::GetSampleMatrix()
{
    return matrix;
}
std::vector<elementOfMatrix> SaddlePoint::DetermineSaddlePoints()
{
    std::vector<struct elementOfMatrix> result;
    // minByRow are used to store all the mininum
    // maxByRow are used to store all the maximum
    std::vector<float> minByRow(matrix.size());
    std::vector<float> maxByRow(matrix.size());
    for(size_t row = 0; row < matrix.size(); ++row)
    {

        minByRow[row] = matrix[row][0];
        maxByRow[row] = matrix[row][0];
        for(size_t col = 1; col < matrix[row].size(); ++col)
        {
            // find minimum
            if(matrix[row][col] < minByRow[row])
                minByRow[row]  = matrix[row][col];

            // find maximum
            if(matrix[row][col] > maxByRow[row])
                maxByRow[row] = matrix[row][col];
        }
    }

    for(size_t col = 0; col < matrix[0].size(); ++col)
    {
        float minByCol = matrix[0][col];
        float maxByCol = matrix[0][col];
        for(size_t row = 1; row < matrix.size(); ++row)
        {
            if(matrix[row][col] < minByCol)
                minByCol = matrix[row][col];

            if(matrix[row][col] > maxByCol)
                maxByCol = matrix[row][col];
        }

        for(size_t row = 0; row < matrix.size(); ++row)
        {
            if(minByCol == maxByRow[row] && minByCol == matrix[row][col])
            {
                elementOfMatrix ele = {(int)row,(int)col,matrix[row][col]};
                result.push_back(ele);
            }

            if(maxByCol == minByRow[row] && maxByCol == matrix[row][col])
            {
                elementOfMatrix ele = {(int)row,(int)col,matrix[row][col]};
                result.push_back(ele);
            }            
        }
    }

    return result;
}
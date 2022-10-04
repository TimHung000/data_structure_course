/**
 * Find the saddle points based on chosen function and parameters
 * 
 * @class_hw: NSYSU_Data_Structure assignment1
 * @author: Hao Yu Hung(M113040047)
 * @date:   2022/10/01
 * @modified_date: 2022/10/05
 * 
 */ 

#ifndef __SADDLEPOINT_H__
#define __SADDLEPOINT_H__

#include <string>
#include <vector>
#include <array>

typedef float (*MathFunc)(float, float);


enum class Function
{
    FUNCTION1,
    FUNCTION2,
    FUNCTION3,
};

const std::array<std::string,3> allFunction = {"y * sin(x) - x * cos(y)", "-cos(x) + sin(y)", "sqrt(x^2 + y^2)"};
/**
 * 
 * this structure is used to record the matrix element,
 * which is given as f(x,y) = val
 * 
 */
typedef struct elementOfMatrix
{
    int xAxis;
    int yAxis;
    float val;
}elementOfMatrix;

float function1(float x, float y);
float function2(float x, float y);
float function3(float x, float y);
/**
 * 
 * This class is used to construct the matrix based on given range
 * of x, y and the function selected by user.
 * 
 * minX/Y : the start value of axis(including itself)
 * maxX/Y : the end value of axis(including itself)
 * stepX/Y; the interval between every point
 * (e.g minX=0 stepX=0.5 than we will calculate 0 0.5 1 1.5 ...)
 *
 * GetSampleMatrix will return the calulated matrix based on the
 * given function and x/y axis
 * 
 * DetermineSaddlePoints will return all the saddlePoints of the 
 * constructed marix.
 * The saddle point is when a element in a mtrix is the largest of 
 * the row also the smallest of the column, or the smallest of the 
 * column and also largest of the row.
 * 
 */ 
class SaddlePoint
{
private:
    std::string expression;
    MathFunc funcPtr;
    std::vector<std::vector<float>> matrix;
    float _minX;
    float _stepX;
    float _maxX;
    float _minY;
    float _stepY;
    float _maxY;
public:
    SaddlePoint(float minX, float stepX, float maxX, float minY, float stepY, float maxY);
    SaddlePoint();
    ~SaddlePoint();
    void SelectFunction(Function);
    void SetSampleMinX(float);
    void SetSampleStepX(float);
    void SetSampleMaxX(float);
    void SetSampleMinY(float);
    void SetSampleStepY(float);
    void SetSampleMaxY(float);
    float GetSampleMinX();
    float GetSampleStepX();
    float GetSampleMaxX();
    float GetSampleMinY();
    float GetSampleStepY();
    float GetSampleMaxY();
    void GenerateSampleMatrix();
    std::vector<std::vector<float>> GetSampleMatrix();
    std::vector<elementOfMatrix> DetermineSaddlePoints();
};

#endif
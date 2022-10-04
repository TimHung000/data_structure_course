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

typedef struct elementOfMatrix
{
    int xAxis;
    int yAxis;
    float val;
}elementOfMatrix;

float function1(float x, float y);
float function2(float x, float y);
float function3(float x, float y);

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
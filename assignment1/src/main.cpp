/**
 * Find the saddle points based on chosen function and parameters
 * 
 * @class_hw: NSYSU_Data_Structure assignment1
 * @author Hao Yu Hung(M113040047)
 * @date   2022/10/01
 * 
 */ 
#include "saddlePoint.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <limits> //std::numeric_limits
#include <sstream> //std::istringstream

void printMatrix(std::vector<std::vector<float>> matrix, float minX, float minY, float stepX, float stepY)
{
    std::cout << "this is the matrix based on the given function and axis range:\n\n";
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
    std::cout << "all the saddle points in the matrix:\n\n";
    if(saddlePoints.size() == 0)
        std::cout << "No saddle points" << std::endl;
        
    for(size_t i = 0; i < saddlePoints.size(); ++i)
    {
        std::cout << '(' << minX + saddlePoints[i].xAxis * stepX << ',' << minY + saddlePoints[i].yAxis * stepY << ") " << saddlePoints[i].val << '\n';
    }
}


int main()
{
    std::cout << "This executable is used for finding the saddle point of given function and parameters\n\n";

    while(true)
    {
        // get function option from user
        int option;
        while(true)
        {
            std::cout << "Please select the function:\n";

            for(int i = 0; i < allFunction.size(); ++i)
            {
                std::cout << std::setw(3) << i+1 << ": " << allFunction[i] << "\n";
            }
            std::cout << std::setw(3) << allFunction.size()+1 << ": exit the program\n";

            std::cout << "input here: ";
            if(std::cin >> option && option > 0 && option <= allFunction.size()+1)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }

            std::cout << "That's not a option\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        if(option == allFunction.size() + 1) break;

        Function chosenFunction;
        switch (option)
        {
        case 1:
            chosenFunction = Function::FUNCTION1;
            break;
        case 2:
            chosenFunction = Function::FUNCTION2;
            break;
        case 3:
            chosenFunction = Function::FUNCTION3;
            break;
        default:
            chosenFunction = Function::FUNCTION1;
            break;
        }


        // get x,y range of the function
        float xMin,xStep,xMax,yMin,yStep,yMax;
        std::string line;
        
        std::cout << "\nplease enter the range of the x y axis, and the format is 'start step end'(e.g. 0 0.5 5)\n";
        std::cout << "x axis: ";

        while(getline(std::cin, line))
        {

            std::stringstream tmp(line);
            if(tmp >> xMin >> xStep >> xMax) break;
            std::cout << "wrong format.It should be formatted like this '0 0.5 5'\n";
            std::cout << "x axis: ";
        }

        std::cout << "y axis: ";
        while(getline(std::cin, line))
        {
            std::stringstream tmp(line);
            if(tmp >> yMin >> yStep >> yMax) break;
            std::cout << "wrong format.It should be formatted like this '0 0.5 5'\n";
            std::cout << "y axis: ";
        }


        // create SaddlePoint class and show saddle point
        SaddlePoint test(xMin, xStep, xMax, yMin, yStep, yMax);
        test.SelectFunction(chosenFunction);
        test.GenerateSampleMatrix();

        std::cout << "\n";
        printMatrix(test.GetSampleMatrix(),test.GetSampleMinX(), test.GetSampleMinY(), test.GetSampleStepX(), test.GetSampleStepY());
        std::cout << "\n";
        printSaddlePoints(test.DetermineSaddlePoints(), test.GetSampleMinX(), test.GetSampleMinY(), test.GetSampleStepX(), test.GetSampleStepY());
        std::cout << "\n";

    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include "Matrix.h"
using namespace std;

Matrix::Matrix(int w, int h, std::vector<std::vector<double>>& m) : width(w), height(h), matrix(m) {}

void Matrix::scale(int row, double scalar)
{
    for(int i = 0; i < width; i++)
    {
        matrix[row][i] *= scalar;
    }
}

void Matrix::swap(int row1, int row2)
{
    if(matrix[row1] != matrix[row2])
    {
        std::vector<double> tmp = matrix[row1];
        for(int i = 0; i < width; i++)
        {
            matrix[row1][i] = matrix[row2][i];
        }
        matrix[row2] = tmp;
    }
}

void Matrix::rowSum(int rowOrigin, int rowDestination, double scalar)
{
    for(int i = 0; i < width; i++)
    {
        matrix[rowDestination][i] += matrix[rowOrigin][i] * scalar;
    }
}

void Matrix::rref(void)
{
    int currPivot = 0;
    int currRow = 0;
    while(currPivot != min(width, height))
    {
        for(int i = currRow; i < height; i++)
        {
            if(matrix[i][currPivot] != 0)
            {
                swap(i, currRow);
                cout << endl; printMatrix(); cout << endl;
                scale(currRow, 1/matrix[currRow][currPivot]);
                printMatrix(); cout << endl;
                for(int j = currRow + 1; j < height; j++)
                {
                    if(matrix[j][currPivot] != 0)
                    {
                        rowSum(currRow, j, -matrix[j][currPivot]);
                        matrix[j][currPivot] = 0;
                        printMatrix(); cout << endl;
                    }
                }
                currRow++;
                break;
            }
        }
        currPivot++;
    }

    currRow = height - 1;
    while(currRow > 0) //from bottom row to top (not including the 1st row)
    {
        for(int i = 0; i < width; i++)
        {
            if(matrix[currRow][i] == 1)
            {
                for(int j = currRow - 1; j >= 0; j--)
                {
                    if(matrix[j][i] != 0)
                    {
                        rowSum(currRow, j, -matrix[j][i]);
                        matrix[j][i] = 0;
                        printMatrix(); cout << endl;
                    }
                }
                break;
            }
        }
        currRow--;
    }
}

void Matrix::printMatrix(void) const
{
    for(auto row : matrix)
    {
        cout << "[ ";
        for(auto col : row)
        {
            if(col == 0)
            { cout << int(col) << " "; }
            else { cout << col << " "; }
        }
        cout << "]" << endl;
    }
}
#include <iostream>
#include <vector>
#include <stdexcept>
#include "Matrix.h"
using namespace std;

void input(vector<vector<double>>& matrix, int& width, int& height)
{
    cout << "Enter Dimensions for an m x n matrix:\n";
    cin >> height >> width;
    if(height < 1 || width < 1)
    {
        throw invalid_argument("Invalid dimensions.");
    } else {
        for(int i = 0; i < height; i++)
        {
            vector<double> row;
            cout << "Row #" << i+1 << ": \n";
            for(int j = 0; j < width; j++)
            {
                int x;
                cin >> x;
                row.push_back(x);
            }
            matrix.push_back(row);
        }
    }
}

int main()
{
    cout << "RREF Calculator v1.0" << endl;
    int width, height;
    vector<vector<double>> matrix;
    while(1)
    {
        try{
            input(matrix, width, height);
            Matrix m(width, height, matrix);
            cout << "You entered: " << endl;
            m.printMatrix();
            m.rref();
            cout << "\nThe reduced row echelon form is: " << endl;
            m.printMatrix(); cout << endl;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            matrix.resize(0);
        } catch (invalid_argument& e) {
            cout << e.what() << endl << endl;
        }
    }
}

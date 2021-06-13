#ifndef MATRIX_H
#define MATRIX_H
class Matrix{
public:
    Matrix(int w, int h, std::vector<std::vector<double>>& m);
    void scale(int row, double scalar);
    void swap(int row1, int row2);
    void rowSum(int rowOrigin, int rowDestination, double scalar);
    void rref(void);
    void printMatrix(void) const;
private:
    const int width; const int height;
    std::vector<std::vector<double>> matrix;
};
#endif
#include<iostream>
using namespace std;
class Matrix {      //定义Matrix类
public:
    int mat[50][50];
    static int m, n;
    Matrix(int x, int y);                    //默认构造函数
    friend Matrix operator +(Matrix a,Matrix b);
    Matrix operator -(Matrix b);
    friend Matrix operator *(Matrix a, Matrix b);
    Matrix operator /(Matrix b);
    void input();                                    //输入数据函数
    void display();                                  //输出数据函数
};
int Matrix::m = 2;
int Matrix::n = 2;
Matrix::Matrix(int x, int y) {                      //定义构造函数
    m = x; n = y;
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            mat[i][j] = 0;
}
//定义重载运算符"+"函数
Matrix operator+(Matrix a, Matrix b) {
    Matrix c(Matrix::m, Matrix::n);
    for (int i = 0; i < a.m; i++)
        for (int j = 0; j < a.n; j++)
            c.mat[i][j] = a.mat[i][j] + b.mat[i][j];
    return c;
}
//定义重载运算符"-"函数
Matrix Matrix::operator-(Matrix b) {
    Matrix c(Matrix::m, Matrix::n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            c.mat[i][j] = mat[i][j] - b.mat[i][j];
    return c;
}
//定义重载运算符"*"函数
Matrix operator*(Matrix a, Matrix b) {
    Matrix c(Matrix::m, Matrix::n);
    for (int i = 0; i < a.m; i++)
        for (int j = 0; j < a.n; j++)
            c.mat[i][j] = a.mat[i][j] * b.mat[i][j];
    return c;
}
//定义重载运算符"/"函数
Matrix Matrix::operator/(Matrix b) {
    Matrix c(Matrix::m, Matrix::n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            c.mat[i][j] = mat[i][j] / b.mat[i][j];
    return c;
}
void Matrix::input() {                              //定义输入数据函数
    cout << "input the value of matrix:" << endl;
    int i, j;
    for (i = 0; i < this->m; i++)
        for (j = 0; j < this->n; j++)
            cin >> mat[i][j];

}
void Matrix::display() {                           //定义输出数据函数
    for (int i = 0; i < this->m; i++) {
        for (int j = 0; j < this->n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}
void main()
{
    cout << "Please input two dimensions of the matrix:  ";
    cin >> Matrix::m >> Matrix::n;
    Matrix a(Matrix::m, Matrix::n), b(Matrix::m, Matrix::n), c(Matrix::m, Matrix::n);
    a.input();  b.input();
    cout << endl << "Matrix a:" << endl;  a.display();    cout << endl << "Matrix b:" << endl;  b.display();
    c = a + b;  cout << endl << "Matrix c = Matrix a + Matrix b :" << endl;  c.display();   //用重载运算符"+"实现两个矩阵相加
    c = a - b;  cout << endl << "Matrix c = Matrix a - Matrix b :" << endl;  c.display();   //用重载运算符"-"实现两个矩阵相减
    c = a * b;  cout << endl << "Matrix c = Matrix a * Matrix b :" << endl;  c.display();   //用重载运算符"*"实现两个矩阵相乘
    c = a / b;  cout << endl << "Matrix c = Matrix a / Matrix b :" << endl;  c.display();   //用重载运算符"/"实现两个矩阵相除
}

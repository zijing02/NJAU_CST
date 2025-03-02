#include<iostream>
using namespace std;
class Rational {
    int m, n;   //分母和分子
public:
    Rational(int nn = 1, int mm = 1);
    friend  Rational  operator  +(Rational& a, Rational& b);      //加法
    friend  Rational  operator  -(Rational& a, Rational& b);      //减法
    friend  Rational  operator  *(Rational& a, Rational& b);      //乘法
    friend  Rational  operator  /(Rational& a, Rational& b);      //除法
    friend bool operator  ==(Rational&, Rational&);
    Rational  operator  -();//取反
    Rational& operator  ++();            //r=++r1
    Rational  operator  ++(int);            //r=r1++
    Rational& operator  --();             //r=--r1
    Rational  operator  --(int);             //r =r1--
    bool operator  <(Rational&);
    operator double();
    void simple();
    void print();
};
Rational::Rational(int nn, int mm) { n = nn;  m = (mm != 0) ? mm : 1; }
Rational operator +(Rational& A, Rational& B) { Rational C(A.n * B.m + A.m * A.n, A.m * B.m);  C.simple();  return C; }
Rational operator -(Rational& A, Rational& B) { Rational C(A.n * B.m - A.m * B.n, A.m * B.m);  C.simple();  return C; }
Rational operator *(Rational& A, Rational& B) { Rational C(A.n * B.n, A.m * B.m);  C.simple();  return C; }
Rational operator /(Rational& A, Rational& B) { Rational C(A.n * B.m, A.m * B.n);  C.simple();  return C; }
bool operator ==(Rational& a, Rational& b) { return double(a.n) / a.m == (double)b.n / b.m ? true : false; }
Rational Rational::operator -() { Rational C(-n, m);    C.simple();    return C; }
Rational& Rational::operator ++() { n = n + m;    return *this; }  //r=++r1;
Rational Rational::operator ++(int) { Rational C(n, m);  n += m;  return C; }  //r=r1++;
Rational& Rational::operator --() { n = n - m;  return *this; }  //r=--r1;
Rational Rational::operator --(int) { Rational C(n, m);  n -= m;  return C; }  //r=r1--;
bool Rational::operator <(Rational& a) { return double(n) / m > (double)a.n / a.m ? true : false; } //r1>r2
Rational::operator double() { return (double)n / m; }
void  Rational::simple() {
    int a = m, b = n, r = 0;
    if (m < n) { a = n;	b = m; }
    r = a % b;
    while (r != 0) { a = b;  b = r;  r = a % b; }
    n /= b;  m /= b;
}
void Rational::print() {
    simple();
    if (m < 0)		cout << "The value is " << -n << '/' << -m << endl;
    else		cout << "The value is " << n << '/' << m << endl;
}
void main() {
    Rational  A(1, 2), B(3, -4), C;    C = A + B;  C.print();    C = A - B;  C.print();    C = A * B;  C.print();    C = A / B;  C.print();
    C = -A;  C.print();    C = ++A;  A.print();  C.print();    C = A++;  A.print();  C.print();
    C = --B;  B.print();  C.print();    C = B--;  B.print();  C.print();
}
#include<iostream>
using namespace std;
class Rational{
public:
	int m, n;   //分母和分子   
	Rational(int nn = 1, int mm = 1);
	Rational  operator  +(Rational &a){ m += a.m; n += a.n; return *this; };                       //加法   
	Rational  operator  -(Rational &a){ m -= a.m; n -= a.n; return *this; };                       //减法   
	friend  Rational  operator  *(Rational &a, Rational &b){ a.m *= b.m; a.n *= b.n; return a; }      //乘法     
	friend  Rational  operator  /(Rational &a, Rational &b){ a.m /= b.m; a.n /= b.n; return a; }   //除法    
	void print();
};
Rational::Rational(int x, int y) { m = x; n = y; }
void Rational::print(){
	if (n == 0)cout << "Wrong";
	if (m*n >= 0)	cout << "The value is " << m << "/" << n;
	else cout << "The value is -" << m << "/" << n;
	cout << endl;
}
void main(){
	Rational  A(2, 6), B(1, -2), C;
	C = A + B; C.print();
	C = A - B; C.print();
	C = A * B; C.print();
	C = A / B; C.print();
}
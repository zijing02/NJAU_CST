#include <iostream>
#include <iomanip>
using namespace std;
class Fraction
{
	int numerator;
	int denominator;
public:
	friend istream & operator >>(istream& in, Fraction& tf);
	friend ostream & operator <<(ostream& out, Fraction& tf);
};
istream& operator >>(istream& in, Fraction& tf)
{
	cout << "请输入分数的分子和分母:  ";
	in >> tf.numerator >> tf.denominator;
	return in;
}
ostream& operator <<(ostream& out, Fraction& tf)
{
	out << "所输入的分数为: " << tf.numerator << "/" << tf.denominator << endl;
	return out;
}
void main()
{
	Fraction f1;
	cin >> f1;
	cout << f1;
}
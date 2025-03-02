#include <iostream>
#include <string>
using namespace std;
double triangle(double a, double b, double c)
{
	double area; string t;
	if (a + b > c&&a + c > b&&b + c > a)
	{
		double s = (a + b + c) / 2;
		area = sqrt(s*(s - a)*(s - b)*(s - c));
	}
	else{
		t = "It’s not a triangle!";
		throw t;
	}
	return area;
}
void main()
{
	double a, b, c;
	cout << "请输入三角形的三边：" << endl;
	cin >> a >> b >> c;
	try
	{
		cout << "三角形面积为：" << triangle(a, b, c) << endl;
		//判断三角形的三边是否均大于0；如是，则求解面积；
	}
	catch (string)
	{
		cout << "输入的三边有误！" << endl;
	}
}
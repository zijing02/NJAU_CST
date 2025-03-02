#include <iostream>
#include <math.h> 
using namespace std;
#define pi 3.14
class Shape{
	int x, y;
	virtual void SetData(int n, int m){ x = n; y = m; };
	virtual void area() = 0{};
	virtual void perimeter() = 0{};

};
class Circle : public Shape{
protected:
	double  r;
public:
	Circle(){};
	void SetData(int n){ r = n; }
	void area(){ cout << "圆的面积是：" << pi*pow(r, 2) << endl; }
	void perimeter(){ cout << "圆的周长是：" << 2 * pi*r << endl; }
};
class Triangle : public Shape{
protected:
	double  a, b, c;
public:
	Triangle(){};
	void SetData(int x, int y, int z) {
		if (x + y <= z || x + z <= y || y + z <= x)
			cout << "wrong" << endl;
		else{
			a = x, b = y, c = z;
		}
	}
	void area(){ int temp = (a + b + c) / 2; cout << "三角形的面积是：" << sqrt(temp*(temp - a)*(temp - b)*(temp - c)) << endl; }
	void perimeter(){ cout << "三角形的周长是：" << a + b + c << endl; }
};
class Quadrilateral :public Shape{
	double rectWidth;   double rectHeight;
public:
	Quadrilateral(int m, int n){ rectHeight = m; rectWidth = n; };
	void SetData(int m, int n) { rectHeight = m; rectWidth = n; }
	virtual void area() = 0{};
	void perimeter(){ cout << "长方形的周长是：" << 2 * rectHeight + 2 * rectWidth << endl; }
};
class Rectangle : public Quadrilateral{
protected:
	double rectWidth1;
public:
	Rectangle(int x):Quadrilateral(x,x){};
	void SetData(int x) { rectWidth1 = x; }
	void area(){ cout << "正方形的面积是：" << rectWidth1*rectWidth1 << endl; }
};
void main(){
	Circle a; a.SetData(1); a.perimeter(); a.area();
	Triangle b; b.SetData(3, 4, 5); b.perimeter(); b.area();
	Rectangle d(10); d.SetData(10);  d.perimeter(); d.area();
}
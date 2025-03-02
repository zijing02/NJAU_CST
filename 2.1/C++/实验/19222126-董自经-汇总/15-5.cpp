#include <iostream>
#include <math.h>
using namespace std;
#define pi 3.14
class Shape{
public:
	void SetData(){}
	virtual void Perimeter() = 0;
	virtual void Area() = 0;

};
class Circle : public Shape{
	int r;
public:
	void SetData(int t){ r = t; }
	void Perimeter(){ cout << "The circle's perimeter is:" << (2*pi*r) << endl; }
	void Area(){ cout << "The triangle's area is:" << pi*r*r << endl; }
};
class Triangle : public Shape{
	int s1, s2, s3;
public:
	void SetData(int t1, int t2, int t3){ s1 = t1; s2 = t2; s3 = t3; }
	void Perimeter(){ cout << "The triangle's perimeter is:" << (s1 + s2 + s3) << endl; }
	void Area(){ int temp = (s1 + s2 + s3) / 2; cout << "The triangle's area is:" << sqrt(temp*(temp - s1)*(temp - s2)*(temp - s3)) << endl; }
};
class Quadrilateral : public Shape{
	int side;
public:
	Quadrilateral(int t1) :side(t1){}
	void Perimeter(){ cout << "The square's perimeter is:" << 4 * side << endl; }
	virtual void Area() = 0; //或者void Area(){}		
};
class Square : public Quadrilateral{
	int side;
public:
	Square(int t1) :Quadrilateral(t1), side(t1){}
	void Area(){ cout << "The sqare's area is:" << side*side << endl; }
};
void main()
{
	Shape* p;
	Circle c; c.SetData(1); p = &c; p->Perimeter(); p->Area();
	Triangle t; t.SetData(6, 8, 10); p = &t; p->Perimeter(); p->Area();
	Square s(10); p = &s; p->Perimeter(); p->Area();
}

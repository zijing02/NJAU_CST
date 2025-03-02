exp1
#include <iostream>
#include <cmath>
using namespace std;
class Point;
class Distance{
public:
	double Distance::MemberDistance(Point p1, Point p2);
	double Calculate(Point p1, Point p2);
};
class Point{
	double x, y;
public:
	Point(){}
	Point(double tempx, double tempy) :x(tempx), y(tempy){}
	friend double ExternalDistance(Point p1,Point p2);						//友元函数
	friend double Distance::MemberDistance(Point p1, Point p2);				//友元成员
	friend class Distance;													//友元类
};
double ExternalDistance(Point p1, Point p2){
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}
double Distance::MemberDistance(Point p1, Point p2){
	return  sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}
double Distance::Calculate(Point p1, Point p2){
	return  sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}


int main(){
	double x1, y1, x2, y2;
	cout << "Please input the coordinate value of two points(x1, y1, x2, y2): ";
	cin >> x1 >> y1 >> x2 >> y2;
	cout << "The two points you inputted are: (" << x1 << "," << y1 << ") and (" << x2 << "," << y2 << ")" << endl;
	Point p1(x1, y1), p2(x2, y2);

	cout << "The distance between two points calculated with friend function is: " << ExternalDistance(p1,p2) << endl;

	cout << "Please input the coordinate value of two points(x1, y1, x2, y2): ";
	cin >> x1 >> y1 >> x2 >> y2;
	cout << "The two points you inputted are: (" << x1 << "," << y1 << ") and (" << x2 << "," << y2 << ")" << endl;
	Point p3(x1, y1), p4(x2, y2);
	Distance d1;
	cout << "The distance between two points calculated with friend member is: " << d1.MemberDistance(p3,p4) << endl;

	cout << "Please input the coordinate value of two points(x1, y1, x2, y2): ";
	cin >> x1 >> y1 >> x2 >> y2;
	cout << "The two points you inputted are: (" << x1 << "," << y1 << ") and (" << x2 << "," << y2 << ")" << endl;
	Point p5(x1, y1), p6(x2, y2);
	Distance d2;
	cout << "The distance between two points calculated with friend class is: " << d2.Calculate(p5,p6) << endl;
	return 0;
}
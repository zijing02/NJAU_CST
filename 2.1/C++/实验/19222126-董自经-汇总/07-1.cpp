#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
class Box {
	int length, width, height;
public:
	Box();
	Box(Box&);
	Box(Box&, Box&);
	Box(int l, int w, int h) :length(l), width(w){
		height = h;
	}
	void compute_perimeter();
	void compute_superficialarea();
	void compute_volume();
};
void Box::compute_perimeter() {
	cout << "周长：" << 4 * (length + width + height) << endl;
}
void Box::compute_superficialarea() {
	cout << "表面积：" << 2 * (length * width + length * height + width * height) << endl;
}
void Box::compute_volume() {
	cout << "体积：" << length * width * height << endl;
}
Box::Box(Box& a) {
	length = 2 * a.length;
	width = 2 * a.width;
	height = 2 * a.height;
}
Box::Box(Box& a, Box& b) {
	length = a.length+b.length;
	width = a.width + b.width;
	height = a.height + b.height;
}
int main() {
	int l, w, h;
	char flag = 'y';
	Box b(1, 1, 1);
	while (flag == 'y') {
		cout << "Please input the length, width and height of the box: ";
		cin >> l >> w >> h;
		Box b1(l, w, h);
		b1.compute_perimeter();
		b1.compute_superficialarea();
		b1.compute_volume();
		Box b2(b1);
		cout << "The perimeter, superficialarea and volume of a box with double length, width and height is as follows:" << endl;
		b2.compute_perimeter();
		b2.compute_superficialarea();
		b2.compute_volume();
		Box b3(b1, b2);
		cout << "The perimeter, superficialarea and volume of a box with merging the length, width and height of box1 and box2 is as follows:" << endl;
		b3.compute_perimeter();
		b3.compute_superficialarea();
		b3.compute_volume();
		cout << "Do you want to continue to compute the perimeter, superficialarea and volume of a box(y or n)? ";
		cin >> flag;
	}
	return 0;
}


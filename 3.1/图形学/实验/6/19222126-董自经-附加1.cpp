#undef UNICODE
#undef _UNICODE
#include<cmath>
#include<codecvt>
#include<conio.h>
#include<graphics.h>		
#include<bits/stdc++.h>
using namespace std;
#define pi 3.1415926
double fun(double t) {
	return t * pi / 180;
}
int main() {
	double rx, ry, r, d = 15, px = 400, py = 300;
	cout << "please input the center coordinates and radius(rx+r<400,rx-r>-400,ry+r<300,ry-r>-300):";
	//cin >> rx >> ry >> r;
	rx = 0, ry = 0, r = 100;
	initgraph(800, 600, 1);
	line(px, 0, px, 600);
	line(0, py, 800, py);
	for (int i = 0; i <= 360 / d; i++) {
		double dx = r * cos(fun(i * d)), dy = r * sin(fun(i * d));
		if (i == 0) {
			line(px + rx + dx, py - (ry + dy), px + rx + dx, py - (ry + dy));
		}
		else {
			double dx2 = r * cos(fun((i - 1) * d)), dy2 = r * sin(fun((i - 1) * d));
			line(px + rx + dx2, py - (ry + dy2), px + rx + dx, py - (ry + dy));
		}
	}
	_getch();
	closegraph();
	return 0;
}
#undef UNICODE
#undef _UNICODE
#include<cmath>
#include<conio.h>
#include<codecvt>
#include<graphics.h>		
#include<bits/stdc++.h>
using namespace std;
#define pi 3.14
double t[5][3] = { 0 };

double cx(double t) {
	return t + 400;
}
double cy(double t) {
	return 300 - t;
}
double cj(double t) {
	return t / 180.0 * pi;
}
void draw(double tmp[][3]) {
	for (int i = 0; i < 4; i++) 
		line(cx(tmp[i][0]), cy(tmp[i][1]), cx(tmp[i + 1][0]), cy(tmp[i + 1][1]));
}
void mul(double a[][3],double b[][3],int flag) {		
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			t[i][j] = 0;
			for (int k = 0; k < 3; k++)
				t[i][j] += a[i][k] * b[k][j];
		}
	}
	if (flag == 1)
		draw(t);
	else
		memcpy(a, t, 15 * sizeof(double));
}
int main() {
	initgraph(800, 600, 1);
	int px = 400, py = 300;
	line(px, 0, px, 600); line(0, py, 800, py);

	double A[][3] = { 0,0,1,
				50,150,1,
				100,0,1,
				75,75,1,
				25,75,1 };
	
	//y=-x
	double c1[][3] = { -1,0,0,0,-1,-1,0,0,1 };
	draw(A); mul(A, c1, 1);
	Sleep(1000); cleardevice();

	//旋转75(逆时针)
	double angle = 75;
	angle = cj(angle);
	double r75[][3] = { cos(angle),sin(angle),0,-sin(angle),cos(angle),0,0,0,1 };
	line(px, 0, px, 600); line(0, py, 800, py);
	draw(A); mul(A, r75, 1);
	Sleep(1000); cleardevice();

	//平移
	double tx = 52, ty = 60;
	double pa[][3] = { 1,0,0,0,1,0,tx,ty,1 };
	line(px, 0, px, 600); line(0, py, 800, py);
	draw(A); mul(A, pa, 1);
	Sleep(1000); cleardevice();

	//放大
	double time = 2;
	double l[][3] = { 2,0,0,0,2,0,0,0,1 };
	line(px, 0, px, 600); line(0, py, 800, py);
	draw(A); mul(A, l, 1);
	Sleep(1000); cleardevice();

	//缩小
	double s[][3] = { 0.5,0,0,0,0.5,0,0,0,1 };
	line(px, 0, px, 600); line(0, py, 800, py);
	draw(A); mul(A, s, 1);
	Sleep(1000); cleardevice();

	//错切15
	angle = 15;
	angle = cj(angle);
	double mat[][3] = { 1,0,0,tan(angle),1,0,0,0,1 };
	line(px, 0, px, 600); line(0, py, 800, py);
	draw(A); mul(A, mat, 1);
	Sleep(1000); cleardevice();

	_getch();
	closegraph();
	return 0;
}
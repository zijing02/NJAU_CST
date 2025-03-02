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
	double A[][3] = { 0,0,1,
				50,150,1,
				100,0,1,
				75,75,1,
				25,75,1 };
	//关于（10，15）转90  
	//平移-->旋转-->平移
	double a[5][3];
	memcpy(a, A, 15 * sizeof(double));
	tx = 10; ty = 15;
	double pa1[][3] = { 1,0,0,0,1,0,-tx,-ty,1 };
	double pa2[][3] = { 1,0,0,0,1,0,tx,ty,1 };
	angle = 90; angle = cj(angle);
	double r[][3] = { cos(angle),sin(angle),0,-sin(angle),cos(angle),0,0,0,1 };
	line(px, 0, px, 600); line(0, py, 800, py);
	draw(a); mul(a, pa1, 0); draw(a); Sleep(1000);
	mul(a, r, 0); draw(a); Sleep(1000);
	mul(a, pa2, 0); draw(a); Sleep(1000); cleardevice();
	
	//关于y=15x+30对称
	//平移-->旋转-->对称-->旋转-->平移
	double b[5][3];
	memcpy(b, A, 15 * sizeof(double));
	tx = 0; ty = 30;
	double pa3[][3] = { 1,0,0,0,1,0,-tx,-ty,1 };
	double pa4[][3] = { 1,0,0,0,1,0,tx,ty,1 };

	angle = 15;
	angle = atan(angle);
	double r2[][3] = { cos(angle),sin(angle),0,-sin(angle),cos(angle),0,0,0,1 };
	angle = -angle;
	double r1[][3] = { cos(angle),sin(angle),0,-sin(angle),cos(angle),0,0,0,1 };

	double c2[][3] = { 1,0,0,0,-1,0,0,0,1 };
	line(px, 0, px, 600); line(0, py, 800, py);
	draw(b); Sleep(1000); mul(b, pa3, 0); draw(b); Sleep(1000);
	mul(b, r1, 0); draw(b); Sleep(1000);
	mul(b, c2, 0); draw(b); Sleep(1000);
	mul(b, r2, 0); draw(b); Sleep(1000);
	mul(b, pa4, 0); draw(b); Sleep(1000); cleardevice();

	_getch();
	closegraph();
	return 0;
}
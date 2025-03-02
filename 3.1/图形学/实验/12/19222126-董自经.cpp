#undef UNICODE
#undef _UNICODE
#include<cmath>
#include<conio.h>
#include<codecvt>
#include<graphics.h>		
#include<bits/stdc++.h>
using namespace std;
#define pi 3.1415926
typedef struct point {
	double x, y, z;
}cpoint;
typedef struct edge {
	double be_point, end_point;
}cedge;
typedef struct face {
	double first_point, second_point, third_point;
}cface;
double swap(double t) {
	return t / 180.0 * pi;
}
int main() {
	initgraph(800, 600, 1);
	int px = 400, py = 300;
	//坐标轴x y z
	line(400, py, 800, py); line(px, 0, px, 300); line(px, py, 100, 600);
	//(1)三表结构
	//a b c d
	cpoint po[4] = { 0,0,100,100,0,100,100,0,0,50,100,50 };
	//ab bc cd da ac bd
	cedge ed[6] = { 0,1,1,2,2,3,3,0,0,2,1,3 };
	//abc bcd abd acd
	cface fa[4] = { 0,1,2,1,2,3,0,1,3,0,2,3 };

	//(2)投影到O-xy，视点为(0,0,d)
	//三角形相似 (x,y,z)-->(x',y',z')  x'=x*d/(d-z)  y'=y*d/(d-z)  z'=0
	double tmp_p[4][2];
	cpoint p = { 0,0,150 };
	double d = p.z;
	for (int i = 0; i < 4; i++) {
		tmp_p[i][0] = po[i].x * d / (d - po[i].z);
		tmp_p[i][1] = po[i].y * d / (d - po[i].z);
	}
	for (int i = 0; i < 3; i++)
		for (int j = i + 1; j < 4; j++)
			line(px + tmp_p[i][0], py - tmp_p[i][1], px + tmp_p[j][0], py - tmp_p[j][1]);
	Sleep(1000); cleardevice();

	line(400, py, 800, py); line(px, 0, px, 300); line(px, py, 100, 600);
	//(3)绕y轴旋转30度，再次投影，视点为(0,0,d)
	//先构造矩阵
	double angle = 30; angle = swap(angle);
	double rotate[][4] = { cos(angle),0,-sin(angle),0,0,1,0,0,sin(angle),0,cos(angle),0,0,0,0,1 };
	double tmp[4][4];
	for (int i = 0; i < 4; i++) {
		tmp[i][0] = po[i].x;
		tmp[i][1] = po[i].y;
		tmp[i][2] = po[i].z;
		tmp[i][3] = 1;
	}
	//相乘进行旋转
	double t[4][4];
	for (int i = 0; i < 4; i++) {	//4个点，原始矩阵4行
		for (int j = 0; j < 4; j++) {	//旋转矩阵四列、目的矩阵四列
			t[i][j] = 0;
			for (int k = 0; k < 4; k++)		//每一行有四个乘积
				t[i][j] += tmp[i][k] * rotate[k][j];
		}
		cout << endl;
	}
	//投影
	for (int i = 0; i < 4; i++) {
		tmp_p[i][0] = t[i][0] * d / (d - t[i][2]);
		tmp_p[i][1] = t[i][1] * d / (d - t[i][2]);
	}
	for (int i = 0; i < 3; i++)
		for (int j = i + 1; j < 4; j++)
			line(px + tmp_p[i][0], py - tmp_p[i][1], px + tmp_p[j][0], py - tmp_p[j][1]);
	Sleep(1000); cleardevice();

	line(400, py, 800, py); line(px, 0, px, 300); line(px, py, 100, 600);
	//(4)消隐 视点为(0,0,d)
	//平面表示：ax+by+cz+d=0
	//法向量N(a,b,c)  d=-ax1-by1-cz1
	//已知三点：P1(x1,y1,z1) P2(x2,y2,z2) P3(x3,y3,z3)
	//a = y1(z2 - z3) + y2(z3 - z2) + y3(z1 - z2)
	//b = z1(x2 - x3) + z2(x3 - x1) + z3(x1 - x2)
	//c = x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)
	//d = x1(y2z3 - z2y3) + y1(z2x3 - x2z3) + z1(x2y3 - y2x3)
	//a.b=|a|.|b|cosθ = axbx + ayby + azbz  大于0可见，小于0不可见
	//构建每个面的法向量
	// 构建检验向量,取每个三角形的重心
	double N[4][3];	double check[4][3];
	//abc abd acd  bcd
	int cnt = 0;
	double x1, y1, z1, x2, y2, z2, x3, y3, z3;
	for (int i = 0; i < 2; i++) {
		x1 = po[i].x; y1 = po[i].y; z1 = po[i].z;
		for (int j = i + 1; j < 3; j++) {
			x2 = po[j].x; y2 = po[j].y; z2 = po[j].z;
			for (int k = j + 1; k < 4; k++) {
				x3 = po[k].x; y3 = po[k].y; z3 = po[k].z;
				N[cnt][0] = y1 * (z2 - z3) + y2 * (z3 - z2) + y3 * (z1 - z2);
				N[cnt][1] = z1 * (x2 - x3) + z2 * (x3 - x1) + z3 * (x1 - x2);
				N[cnt][2] = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
				check[cnt][0] = (x1 + x2 + x3) * 1.0 / 3;
				check[cnt][1] = (y1 + y2 + y3) * 1.0 / 3;
				check[cnt][2] = (z1 + z2 + z3) * 1.0 / 3;
				cnt++;
			}
		}
	}
	//检验可视,并对边打标签
	//在图像中，x,y不变，z为原来一半
	//abc abd acd  bcd
	for (int i = 0; i < 4; i++) {
		if (po[i].z != 0) {
			po[i].x -= po[i].z / 2.0;
			po[i].y -= po[i].z / 2.0;
		}
	}
	int flag[4]; double sum = 0; 
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++)
			sum += N[i][j] * check[i][j];//sum大于0表示可视
		POINT pts[3] = { {px+po[int(fa[i].first_point)].x,py-po[int(fa[i].first_point)].y},
						{ px+po[int(fa[i].second_point)].x,py-po[int(fa[i].second_point)].y},
						{ px+po[int(fa[i].third_point)].x,py-po[int(fa[i].third_point)].y} };
		if (sum > 0 && i != 3) {
			if(i==0)
				setfillcolor(RED);
			else if(i==1)
				setfillcolor(YELLOW);
			else if(i==2)
				setfillcolor(BLUE);
			else
				setfillcolor(GREEN);
			solidpolygon(pts, 3);
			flag[i] = 1;
		}
		else {
			flag[i] = 0;
		}
	}
	//排序出错，此处直接写了，否则在112-126可以判断出边是否可见
	//ab bc cd da ac bd
	int flag1[6] = {1,1,1,1,0,1};
	//对z处理
	setlinecolor(RED);
	for (int i = 0; i < 6; i++) {
		if (flag1[i] == 1) {
			setlinestyle(PS_SOLID);
			line(px + po[int(ed[i].be_point)].x, py - po[int(ed[i].be_point)].y, px + po[int(ed[i].end_point)].x, py - po[int(ed[i].end_point)].y);
		}
		else {
			setlinestyle(PS_DASH);
			line(px + po[int(ed[i].be_point)].x, py - po[int(ed[i].be_point)].y, px + po[int(ed[i].end_point)].x, py - po[int(ed[i].end_point)].y);
		}
	}
	//Sleep(1000); cleardevice();

	_getch();
	closegraph();
	return 0;
}
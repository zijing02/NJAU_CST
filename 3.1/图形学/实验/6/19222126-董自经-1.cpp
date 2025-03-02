#undef UNICODE
#undef _UNICODE
#include<conio.h>
#include<cmath>
#include<graphics.h>		
#include<bits/stdc++.h>
#include <codecvt>
using namespace std;
struct point {
	double x;
	double y;
};
int main() {
	point p1, p2; 
	int px = 400, py = 300; 
	double k; char s[] = "(0,0)";
	cout << "please input two points(-400<=x<=400,-300<=y<=300):";
	cin >> p1.x >> p1.y >> p2.x >> p2.y;
	initgraph(800, 600, 1);
	line(px, 0, px, 600);
	line(0, py, 800, py);
	outtextxy(410, 310, s);
	//垂直于x轴，斜率不存在，直接画，或者在k>1画，但是在计算的时候就已经因为除0而暂停
	if (p1.x == p2.x) {
		line(px + p1.x, py - p1.y, px + p2.x, py - p2.y);
	}
	else {
		k = (p1.y - p2.y) * 1.0 / (p1.x - p2.x);
		//k<=1,以x为基准前进
		if (abs(k) <= 1) {
			//从小x值开始加
			double tx = p1.x > p2.x ? p2.x : p1.x, ty = p1.x == tx ? p1.y : p2.y;
			double maxx = p1.x < p2.x ? p2.x : p1.x;
			while (tx <= maxx) {
				tx += 1;
				ty += k;
				line(px + tx - 1, py - (ty - k), px + tx, py - round(ty));
			}
		}
		//k>=1,以y为基准前进
		else if (abs(k) > 1) {
			//从小y值开始加
			double ty = p1.y > p2.y ? p2.y : p1.y, tx = p1.y == ty ? p1.x : p2.x;
			double maxy = p1.y < p2.y ? p2.y : p1.y;
			while (ty <= maxy) {
				ty += 1;
				tx += 1.0 / k;
				line(px + tx - 1.0 / k, py - (ty - k), px + round(tx), py - ty);
			}
		}
	}
	_getch();				
	closegraph();			
	return 0;
}
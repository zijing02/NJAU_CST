#undef UNICODE
#undef _UNICODE
#include<conio.h>
#include<cmath>
#include<graphics.h>		
#include<bits/stdc++.h>
#include <codecvt>
using namespace std;
#define pi 3.1415926
double fun(double t) {
	return t * 1.0 / 100 * 360 * pi / 180;
}
int main() {
	double n = 0, sum = 0, start = 0, end = 0;
	//cin >> n;
	//int* percentage = new int[n + 1];
	//for (int i = 1; i <= n; i++) {
	//	cin >> percentage[i];
	//	sum += percentage[i];
	//}
	double percentage[] = { 50,20,10,5,10,5 };
	string name[] = { "computer","printer","plotter","scanner","paper","disk" };
	char num[][20] = { "50%","20%","10%","5%","10%","5%"};
	char s[][30] = { "computer :","printer :","plotter :","scanner :","paper :","disk :" };
	n = 6, sum = 100;
	initgraph(800, 600, 1);
	double cx = 300, cy = 300, r = 200, rx = 550, ry = 100;
	setfillcolor(RED);
	for (int i = 0; i < 6; i++) {
		//choose style and draw fans
		setfillstyle(2, i);
		end += percentage[i];
		double st = fun(start), en = fun(end);
		solidpie(100, 100, 500, 500, st, en);
		start += percentage[i];

		//print the percentage of each good
		double half = (st + en) / 2;
		double tx = cx + r * cos(half), ty = cy - r * sin(half);
		//moveto(tx, ty);
		//wchar_t s[100] = L"";
		//wstring num = to_wstring(int(percentage[i]));
		//wcscat_s(s, num.c_str());
		//wchar_t toAdd[] = L"%";
		//wcscat_s(s, toAdd);
		//outtext(s);
		outtextxy(tx, ty, num[i]);

		//draw example of each part
		solidrectangle(rx, ry, rx + 100, ry + 400 * 1.0 / 6);
		ry += 400 * 1.0 / 6;

		//print name of examples
		tx = 660, ty = ry - 400 * 1.0 / 12;
		moveto(tx, ty);
		//wchar_t s1[100] = L"";
		//wstring wstr_a = wstring_convert<codecvt_utf8<wchar_t>>().from_bytes(name[i] + ":");
		//wcscat_s(s1, wstr_a.c_str());
		//outtext(s1);
		//outtext(s);
		outtextxy(tx, ty, s[i]);
		outtextxy(tx + 80, ty, num[i]);
	}
	//print the name of the chart
	//wchar_t s[] = L"the pie chart of market";
	//moveto(350, 550);
	//outtext(s);
	char s1[] = "the pie chart of market";
	outtextxy(350,550, s1);

	_getch();				// 按任意键继续
	closegraph();			// 关闭绘图窗口
	return 0;
}
#undef UNICODE
#undef _UNICODE
#include<graphics.h>		
#include<conio.h>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
int str_to_int(char s[]) {
	int a = 0;
	for (int i = 0; s[i] != '\0'; i++)
		a = a * 10 + (s[i] - '0');
	return a;
}
int main() {
	//the dege of the big rectangle
	int lx = 20, ay = 10, rx = 620, ly = 410;
	int wid = 80, ix = 120;
	//int a[3][2] = { 0 }, year[3] = { 0 };
	char a[3][2][10], year[3][20];
	cout << "please input the years: ";
	for (int i = 0; i < 3; i++)
		cin >> year[i];
	cout << "please input the numbers(because of the limitation of data I use,please do not larger than 400): ";
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 2; j++)
			cin >> a[i][j];
	initgraph(640, 480, 0);
	setbkcolor(WHITE);
	cleardevice();
	setlinecolor(BLACK);
	settextcolor(BLACK);
	for (int i = 0; i < 3; i++) {
		//print the years
		//moveto(ix - 2, 411);
		//wchar_t s[100] = L"";
		//wstring num = to_wstring(int(year[i]));
		//wcscat_s(s, num.c_str());
		//outtext(s);
		outtextxy(ix - 2, 411, year[i]);

		for (int j = 0; j < 2; j++) {
			int tmp=str_to_int(a[i][j]);

			//print the bar before
			if (j == 0) {
				setfillcolor(YELLOW);
				setfillstyle(0, YELLOW);
				//solidrectangle(ix - 80 - 3, ly - a[i][j] - 2, ix, ly);
				//moveto(ix - 40, ly - a[i][j]);
				//wchar_t s[100] = L"";
				//wstring num = to_wstring(int(a[i][j]));
				//wcscat_s(s, num.c_str());
				//outtext(s);
				solidrectangle(ix - 80 - 3, ly - tmp - 2, ix, ly);
				outtextxy(ix - 40, ly - tmp, a[i][j]);
			}

			//print the bar after
			else {
				setfillcolor(RED);
				setfillstyle(0, RED);
				//solidrectangle(ix - 3, ly - a[i][j] - 2, ix + 80, ly);
				//moveto(ix + 40, ly - a[i][j]);
				//wchar_t s[100] = L"";
				//wstring num = to_wstring(int(a[i][j]));
				//wcscat_s(s, num.c_str());
				//outtext(s);
				solidrectangle(ix - 3, ly - tmp - 2, ix + 80, ly);
				outtextxy(ix + 40, ly - tmp, a[i][j]);
			}
		}
		ix += 200;
	}
	//print the example
	setfillcolor(YELLOW);
	setfillstyle(0, YELLOW);
	solidrectangle(25, 15, 65, 45);
	//moveto(70, 30);
	//wchar_t s1[] = L"nation income";
	//outtext(s1);
	char s1[] = "nation income";
	outtextxy(70, 30, s1);

	setfillcolor(RED);
	setfillstyle(0, RED);
	solidrectangle(25, 50, 65, 80);
	//moveto(70, 65);
	//wchar_t s2[] = L"total social product";
	//outtext(s2);
	char s2[] = "total social product";
	outtextxy(70, 65, s2);

	//print the name of the chart
	rectangle(20, 10, 620, 410);
	//moveto(310, 450);
	//wchar_t s3[] = L"chart of production";
	//outtext(s3);
	char s3[] = "chart of production";
	outtextxy(310, 450, s3);

	_getch();
	closegraph();

	return 0;
}


#undef UNICODE
#undef _UNICODE
#include<conio.h>
#include<cmath>
#include<graphics.h>		
#include<bits/stdc++.h>
#include <codecvt>
using namespace std;
int px = 0, py = 0;
void dianzheng() {
	int text[3][16] = {
		//D
		0x0000, 0x0000, 0x0000, 0x1F00,
		0x1080, 0x1040, 0x1020, 0x1020,
		0x1020, 0x1020, 0x1040, 0x1080,
		0x1F00, 0x0000, 0x0000, 0x0000,
		//Z
		0x0000, 0x0000, 0x0000, 0x1FE0,
		0x0020, 0x0040, 0x0080, 0x0100,
		0x0200, 0x0400, 0x0800, 0x1000,
		0x1FE0, 0x0000, 0x0000, 0x0000,
		//J
		0x0000, 0x0000, 0x0000, 0x1FF0,
		0x0100, 0x0100, 0x0100, 0x0100,
		0x0100, 0x0100, 0x0900, 0x0900,
		0x0600, 0x0000, 0x0000, 0x0000,
	};
	int mask[16] = {
		0x8000, 0x4000, 0x2000, 0x1000,
		0x0800, 0x0400, 0x0200, 0x0100,
		0x0080, 0x0040, 0x0020, 0x0010,
		0x0008, 0x0004, 0x0002, 0x0001,
	};

	for (int k = 0; k < 3; k++)
		for (int i = 0; i < 16; i++)  //行
			for (int j = 0; j < 16; j++)  //列
				if ((text[k][i] & mask[j]) != 0)
					putpixel(px + j * 20 + k * 200, py + i * 20 + 10, YELLOW);
}
void shiliangshi() {
	int len = 36;
	int text[3][14] = {
		//坐标的xy反了
		//D
		100,100,100,250,150,300,350,300,400,250,400,100,100,100,
		//Z
		100,350,100,550,400,350,400,550,400,550,400,550,400,550,
		//J
		100,600,100,750,100,675,150,675,400,675,400,625,350,575
	};
	for (int j = 0; j < 3; j++) {
		moveto(px + text[j][1], py + text[j][0]);
		for (int i = 1; i < 7; i++)
			lineto(px + text[j][2 * i + 1], py + text[j][2 * i]);
	}
}
void direcode() {
	int model[8][2] = { { 1,0 }, {1,-1 }, { 0,-1 }, { -1,-1 },{ -1,0 }, { -1,1 }, { 0,1 }, { 1,1 } };
	int dire[3][14] = {
		//D
		0,0,7,6,6,6,5,4,4,2,2,2,2,2,
		//Z
		0,0,0,0,5,5,5,5,0,0,0,0,4,0,
		//J
		0,0,0,0,0,4,4,4,6,6,6,6,4,3
	};
	int size = 50;
	for (int i = 0; i < 3; i++) {
		if (i == 0) moveto(100, 100);
		else if (i == 1) moveto(350, 100);
		else moveto(600, 100);
		for (int j = 0; j < 14; j++) 
			linerel(model[dire[i][j]][0] * size, model[dire[i][j]][1] * size);
	}
}
int main() {
	char s[][30] = { "DianZheng :","ShiLiang :","FangXiangBianMa :" };
	for (int i = 1; i <= 3; i++) {
		initgraph(800, 600, 1);
		outtextxy(0, 0, s[i - 1]);
		if (i == 1)
			dianzheng();
		else if (i == 2)
			shiliangshi();
		else
			direcode();
		_getch();
		closegraph();
	}
	return 0;

}
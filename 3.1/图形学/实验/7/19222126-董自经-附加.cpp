#undef UNICODE
#undef _UNICODE
#define _CRT_SECURE_NO_WARNINGS 1
#include<conio.h>
#include<cmath>
#include<graphics.h>		
#include<bits/stdc++.h>
#include <codecvt>
using namespace std;
int px = 0, py = 0;
int text[3][16] = {
	//D
	0x0420, 0x1FF8, 0x0420, 0x03C0,
	0x0100, 0x0FF0, 0x0100, 0x07E0,
	0x0520, 0x07E0, 0x0520, 0x07E0,
	0x0100, 0x0380, 0x0100, 0x1FF8,
	//Z
	0x0000, 0x0000, 0x0030, 0x00C0,
	0x0300, 0x0FF0, 0x0810, 0x0810,
	0x0FF0, 0x0810, 0x0810, 0x0FF0,
	0x0810, 0x0810, 0x0FF0, 0x0000,
	//J
	0x0000, 0x0000, 0x08FC, 0x1008,
	0x2410, 0x7830, 0x1048, 0x2084,
	0x7902, 0x047C, 0x0810, 0x1010,
	0x2010, 0x407C, 0x0000, 0x0000,
};
void dianzheng() {
	
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
int main() {
	//FILE* fp;
	//fp = fopen("D:\\university\\3.1\\计算机图形学\\实验\\3\\name.txt", "wb");
	//for (int i = 0; i < 3; i++) {
	//	for (int j = 0; j < 16; j++)
	//		fprintf(fp, "%d ", text[i][j]);
	//	fprintf(fp, "\n");
	//}
	fclose(fp);
	//fp = fopen("D:\\university\\3.1\\计算机图形学\\实验\\3\\name.txt", "wb");
	//for (int i = 0; i < 3; i++)
	//	for (int j = 0; j < 16; j++)
	//		fscanf_s(fp, "%d", &text[i][j]);
	//fclose(fp);
	//fwrite(text, sizeof(int), sizeof(text) / sizeof(text[0][0]), fp);
	//fread(text), sizeof(int), sizeof(text) / sizeof(text[0][0]), fp);
	char s[][30] = { "DianZheng :","ShiLiang :","FangXiangBianMa :" };
	initgraph(800, 600, 1);
	outtextxy(0, 0, s[0]);
	dianzheng();

	_getch();
	closegraph();

	return 0;
}
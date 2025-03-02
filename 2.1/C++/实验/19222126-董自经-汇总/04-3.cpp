#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	void rotate(int **a, int d1, int d2, int angle);
	int d1, d2, i, j, n, angle; char c = 'y'; cin >> d1 >> d2;
    int** a,**s;
    n = d1 > d2 ? d1: d2;
	a = (int**)malloc(sizeof(int*) * n);	s = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < d1; i++) {
		*(a + i) = (int*)malloc(sizeof(int) * n);
		*(s + i) = (int*)malloc(sizeof(int) * n);
	}
	if (a == NULL || s == NULL)
        cout << "分配失败\n";

	cout << "输入矩阵:" << endl;
	for (i = 0; i < d1; i++)
		for (j = 0; j < d2; j++)
			cin >> a[i][j];
	cout << "原矩阵是:" << endl;
	for (i = 0; i < d1; i++) {
		for (j = 0; j < d2; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}

	while (c == 'y') {
		for (i = 0; i < d1; i++)
			for (j = 0; j < d2; j++)
				s[i][j] = a[i][j];
		cout << "旋转的角度："; cin >> angle;
		if ((angle != 90) && (angle != 180) && (angle != 270))
			cout << "错误的角度";
		else 	rotate(s, d1, d2, angle);
		cout << "还要继续旋转吗（y/n）：";
		cin >> c;
	}
	return 0;
}
//新矩阵的第i行是原矩阵的第i列倒放
void rotate(int **q, int d1, int d2, int angle) {
	int i, j, b[100][100] = { 0 }, a[100][100] = { 0 },  m, t;
	for (i = 0; i < d1; i++)
		for (j = 0; j < d2; j++)
			a[i][j] = q[i][j];
	t = d1 > d2 ? d1 : d2;
	for (int cnt = 0; cnt < angle / 90; cnt++) {
		for (i = 0; i < d2; i++) {
			m = d1;
			for (j = 0; j < d1; j++) {
				b[i][j] = a[--m][i];
			}
		}
		d2 = d1 + d2; d1 = d2 - d1; d2 = d2 - d1;
		for (i = 0; i < t; i++) {
			for (j = 0; j < t; j++) {
				a[i][j] = b[i][j];
			}
		}
	}
	for (i = 0; i < d1; i++) {
		for (j = 0; j < d2; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}

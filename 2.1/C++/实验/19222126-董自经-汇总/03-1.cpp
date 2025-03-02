#include<iostream>
#include<cstring>
#include<limits.h>
#include<cstdio>
using namespace std;
int main(){
	int d1, d2, a[10000] = { 0 }, t, i,cnt;
	cout << "输入矩阵的维数：(行*列)";	cin >> d1 >> d2;
	cout << "输入矩阵的内容:";
	for (i = 0; i < d1*d2; i++)
		cin >> a[i];
	cout << "输入倍数："; cin >> t;
	cout << "原矩阵是："<<endl;
	cnt = 0;
	for (i = 0; i < d1*d2; i++){
		cout << a[i]<<" ";
		cnt++;
		if (!(cnt%d2))
			cout << endl;
	}
	cout << "改变之后的矩阵是："<<endl;
	cnt = 0;
	for (i = 0; i < d1*d2; i++){
		cout << a[i] * t<<" ";
		cnt++;
		if (!(cnt%d2))
			cout << endl;
	}

	return 0;
}
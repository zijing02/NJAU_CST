#include<iostream>
#include<cstdio>
#include<limits.h>
using namespace std;
int n, m1[30] = { 0 }, m2[30] = { 0 }, m3[30] = { 0 }, ans[15] = { 0 }, mark = 0;
void setvalue(int x, int y, int k) {
	ans[x] = y;				//ans第x行值变为y表示第x行y列
	m1[y] = k;				//同一列的值锁定
	m2[x + y] = k;			//同顺对角线的值锁定
	m3[x - y + n] = k;		//同逆对角线的值锁定
}
void dfs(int step) {//搜索第step行
	if (step > n) {
		mark++;				//结果数目加一
		if (mark <= INT_MAX) {
			for (int j = 1; j<= n; j++) {
				cout << ans[j] << " ";		//每一行的第j列是可以放置的
			}
			cout << endl;
		}
		return;
	}
	for (int j = 1; j <= n; j++){
		if (m1[j] || m2[step + j] || m3[step - j + n])continue;	//如果某一个值不满足就跳过
		setvalue(step, j, 1);	//跳过之后把该点的值变化
		dfs(step + 1); //向下dfs
		setvalue(step, j, 0);
	}
}
int main() {
	//3八皇后,经典dfs
	//规律：以a[i][j]为例，同列的点j的值相同，同逆对角线的i+j值相同，同顺对角线i-j的值相同，所以三个一位数组就够了
	cin >> n;
	dfs(1);
	cout << mark;

	return 0;
}


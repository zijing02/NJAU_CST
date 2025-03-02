#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main() {


	//求阶乘和
	double jiechen(double);
	double j, ans = 0; cin >> j;
	for (double i= 0; i < j; i++) {
		cout << jiechen(i) << "\t";
		ans += jiechen(i);
	}
	cout << "\n" << "和是：" << ans << "\n";
	
	return 0;
}
double jiechen(double i) {
	double ans = 1;
	for (double j = 2; j <= i; j++) {
		ans *= j;
	}
	return ans;
}




















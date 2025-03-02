#include<iostream>
using namespace std;
template<class X>
X*T(X*a,X*b,int n){
	X*c = new X[n];
	for (int i = 0; i < n; i++)
		c[i] = a[i] + b[i];
	return c;
}
int main(){
	int a[5] = { 1, 2, 3, 4, 5 }, b[5] = { 10, 20, 30, 40},*p;
	p = T(a, b, 5);
	for (int i = 0; i < 5; i++)
		cout << p[i] << " ";
	return 0;
}
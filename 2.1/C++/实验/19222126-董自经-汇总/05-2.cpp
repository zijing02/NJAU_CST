#include<iostream>
#include<cstdio>
using namespace std;
class calculator {
	double k1, k2, result; char k3;
public:
	calculator(double x,double y,char z) {
		k1 = x; k2 = y; k3 = z;
	}
	double operators(double a1,double a2,char a3) {
		switch (a3) {
		case('+'):cout << "a1 + a2 = " << a1 + a2 << endl; return a1 + a2;
		case('-'):cout << "a1 - a2 = " << a1 - a2 << endl; return a1 - a2;
		case('*'):cout << "a1 * a2 = " << a1 * a2 << endl; return a1 * a2;
		case('/'):cout << "a1 / a2 = " << a1 / a2 << endl; return a1 / a2;
		default:cout << "运算符错误" << endl;

		}
	}
	void redo(double r1) {
		char a4; cout << "是否继续？（y/n）:"; cin >> a4;
		double r2; char r3;
		if (a4 == 'N' || a4 == 'n') {
			cout << "结束运算";
			exit(0);
		}
		if (a4 == 'y' || a4 == 'Y') {
			cout << "输入新运算数:"; cin >> r2;
			cout << "输入新运算符:"; cin >> r3;
			calculator obj(r1, r2, r3);
			obj.operators(r1, r2, r3);
		}

	}

};
int main() {
	double a1, a2, t1; char a3;
p:
	cout << "输入运算数1:"; cin >> a1;
	cout << "输入运算数2:"; cin >> a2;
	cout << "输入运算符:"; cin >> a3;
	calculator j(a1, a2, a3);
	if ((t1 = j.operators(a1, a2, a3)) == 0) {
		cout << "运算符错误";
		goto p;
	}
	
k:
	j.redo(t1);
	goto k;
	return 0;
}
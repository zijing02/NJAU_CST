#include<iostream>
#include<cstdio>
using namespace std;
class matrix {
public:
	void set(int m, int n, int a[][100]) {
		d1 = m; d2 = n;
	}
	void input(int m,int n,int a[][100]) {
		m = d1; n = d2; cout << "输入矩阵元素：" << endl;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				cin >> a[i][j];		
	}
	void output(int m, int n, int a[][100]) {
		m = d1; n = d2;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				cout << a[i][j] << " ";
			cout << endl;
		}
	
	}
	void multiply(int m, int n, int a[][100]) {
		int t; m = d1; n = d2; 
		cout << "倍数："; cin >> t;
		cout << "加倍后的矩阵："<<"\n";
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				cout << a[i][j] * t << " ";
			cout << endl;
		}
	}
	void transpose(int m, int n, int a[][100]) {
		m = d1; n = d2;
		cout << "转置后的数组:" << "\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << a[j][i] << " ";
			cout << endl;
		}
	}
	void rotate(int m,int n,int a[][100]) {
		int angle; cout << "输入角度:" << endl; cin >> angle; m = d1; n = d2;
		int i, j, b[100][100] = { 0 }, q[100][100] = { 0 } , ti, t;
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
				q[i][j] = a[i][j];
		t = m > n ? m : n;
		for (int cnt = 0; cnt < angle / 90; cnt++) {
			for (i = 0; i < n; i++) {
				ti = m;
				for (j = 0; j < m; j++) {
					b[i][j] = q[--ti][i];
				}
			}
			n = m + n; m = n - m;  n= n - m;
			for (i = 0; i < t; i++) {
				for (j = 0; j < t; j++) {
					q[i][j] = b[i][j];
				}
			}
		}
		cout << "旋转后的矩阵:" << endl;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++)
				cout << q[i][j] << " ";
			cout << endl;
		}
	}
private:
	int d1, d2; int a[100][100];
};
int main() {
	matrix a;
	int m, n, s[100][100]; cin >> m >> n;
	a.set(m, n, s);
	a.input(m, n, s);
	a.output(m, n, s);
	a.multiply(m, n, s);
	a.transpose(m, n, s);
	a.rotate(m, n, s);

	return 0;
}
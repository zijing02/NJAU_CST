#include<iostream>
#include<cstdio>
using namespace std;
class set{
public:
	int a[10];
	void init();
	void output();
	int find(int &x);
};
void set::init() {
	cout << "初始化成功，请输入数组元素（小于十个数）：" << endl;
	for (int i = 0; i < 10; i++) 
		cin >> a[i];
}
int set::find(int &x) {
	for (int i = 0; i < 10; i++) 
		if (a[i] == x) {
			x = i;
			return 1;
		}
	return 0;
}
void set::output() {
	for (int i = 0; i < 10; i++) 
		cout << a[i] << " ";
	cout << endl;
}
int main() {
	set array; int num;
	array.init(); cout << "输入要查找的数字：";
	cin >> num;
	if (array.find(num))
		cout << num;
	else
		cout << "数组中没有该元素";
	return 0;
}
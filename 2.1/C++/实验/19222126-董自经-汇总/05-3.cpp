#include<iostream>
#include<cstdio>
using namespace std;
const int MaxSize = 10;
class A {
	int length, data[MaxSize];
public:
	void in(int n, int a[]) {
		length = n;
		for (int i = 0; i < n; i++)
			data[i] = a[i];
	}
	void display() {
		for (int i = 0; i < length; i++)
			cout << data[i] << " ";
	}
	void sort() {
		for (int i = 0; i < length - 1; i++) {
			for (int j = 0; j < length - i - 1; j++) {
				if (data[j] > data[j + 1]) {
					data[j] = data[j] + data[j + 1];
					data[j + 1] = data[j] - data[j + 1];
					data[j] = data[j] - data[j + 1];
				}
			}
		}
		cout << "排序后的数组：";
		for (int i = 0; i < length; i++)
			cout << data[i] << " ";
	}
	void insert() {
		sort(); cout << endl << "请输入插入的数字:";
		int k; cin >> k;
		if (length + 1 > MaxSize) cout << "无法插入";
		else
			for (int i = 0; i <= length; i++) {
				if (((data[i] < k) && (data[i + 1] > k)) || i == length) {
					for (int j = length + 1; j > i+1; j--)
						data[j] = data[j - 1];
					data[i+1] = k;
					break;
				}
			}
		length++;
		for (int i = 0; i < length; i++)
			cout << data[i] << " ";
	}
	void del() {
		int k; cin >> k; cout << "输入删除的数字：";
		if (length == 0)cout << "表为空，无法删除";
		else
			for (int i = 0; i < length; i++) {
				if (data[i] == k) {
					for (int j = i; j < length; j++) {
						data[j] = data[j + 1];
					}
				}
			}
		length--;
		for (int i = 0; i < length; i++)
			cout << data[i] << " ";
	}
	void find() {
		int i, k; cin >> k;
		for (i = 0; i < length; i++) {
			if (data[i] == k)
				cout << i;
		}
		if (i == length)cout << "没有这个数字";
	}
};
int main() {
	int i, n, olda[10], choose, x, y, location;
	cout << "输入数组长度:"; cin >> n;
	if (n > MaxSize) cout << "超长，请输入小于" << MaxSize << "的数字";
	cout << "输入数组元素:";
	for (i = 0; i < n; i++)
		cin >> olda[i];
	A newa;
	newa.in(n, olda);
	cout << "1.显示 2.排序 3.插入 4.删除 5.查找 6.退出" << endl;
	cin >> choose;
	switch (choose) {
	case 1: newa.display(); break;
	case 2:newa.sort(); break;
	case 3:newa.insert(); break;
	case 4:newa.del(); break;
	case 5:newa.find(); break;
	case 6:exit(1); break;
	default:cout << "输入错误"; break;
	}
	return 0;
}

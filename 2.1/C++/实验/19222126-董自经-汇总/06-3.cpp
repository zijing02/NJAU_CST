#include<iostream>
#include<cstdio>
using namespace std;
class PhoneBook {
public:
	PhoneBook() {
		name = new char[10]; name[9] = '\0';
		address = new char[100]; address[99] = '\0';
		pn = new int[15];
		cout << "请输入姓名，地址，电话号码:";
		cin >> name >> address;
		cin >> *pn;
		cout << "新联系人:" << name << endl;
	}
	PhoneBook(PhoneBook& a) {
		cout << "拷贝联系人:" << a.name << endl;
		pn = a.pn;
		name = a.name;
		address = a.address;
	}
	~PhoneBook() {
		cout << "删除联系人" << name << endl;
	}
private:
	char* name, * address; int* pn;
};
void fn(PhoneBook a) {
	cout << "in functioin fn()" << endl;
}
int main() {
	PhoneBook *a; int n;
	cout << "输入联系人人个数："; cin >> n;
	a = new PhoneBook[n];
	for (int i = 0; i < n; i++) 
		a[i];
	
	cout << "Calling fn()" << endl;
	fn(a[0]);
	cout << "return from f()" << endl;
	return 0;
}

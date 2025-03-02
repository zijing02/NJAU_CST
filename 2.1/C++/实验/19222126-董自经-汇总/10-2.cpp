#include <iostream>
using namespace std;
class Base {
private:
	int x;
protected:
	int y;
public:
	int z;
	void showxyz() { cout << "Base::x=" << x << "  Base::y=" << y << "  Base::z=" << z << endl; }
	Base(int t1, int t2, int t3) :x(t1), y(t2), z(t3) {}
};
class Derive :public Base {
private:
	int dx;
protected:
	int dy;
public:
	int dz;
	Derive(int i1, int i2, int i3, int i4, int i5, int i6) :Base(i1, i2, i3) { dx = i4; dy = i5; dz = i6; }

};
void main() {
	Base b(1, 2, 3);
	cout << "公有派生类对象赋值给基类对象前，基类对象的数据状态如下：" << endl;
	b.showxyz();
	Derive d(11, 12, 13, 14, 15, 16);
	b = d;
	cout << "公有派生类对象赋值给基类对象后，基类对象的数据状态如下：" << endl;
	b.showxyz();
	Base& rb = d;
	cout << "公有派生类对象初始化基类对象引用后，基类对象的数据状态如下：" << endl;
	rb.showxyz();
	Base* pb = &d;
	cout << "公有派生类对象地址赋值给基类对象指针后，基类对象的数据状态如下：" << endl;
	pb->showxyz();
}

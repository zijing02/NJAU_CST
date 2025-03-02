#include <iostream>
#include <iomanip>
using namespace std;
void main()
{
	cout << "域宽为14, 以数据符号左对齐、数据本身右对齐方式输出整数9999为:  " << endl;
	//cout.width(14);
	cout.fill(' ');
	cout.setf(ios::internal);
	cout.setf(ios::showpos);
	cout << 9999 << endl;
	cout.unsetf(ios::showpos);
	cout.setf(ios::right);
	cout << "域宽为12, 打印无符号数和有符号数999, 如下所示:  " << endl;
	cout << setw(12) << 999;
	cout.setf(ios::showpos);
	cout << setw(12) << 999 << endl;
	cout << "域宽为10, 将十进制整数99以0x开头的十六进制格式输出为:  " << endl;
	cout.setf(ios::showpos);
	cout << setw(10) << hex << 99 << endl;
	cout << "域宽为8, 用前导符号$格式打印9.999为:  " << endl;
	cout.fill('$');
	cout.unsetf(ios::showpos);
	cout << setw(8) << 9.999 << endl;
}
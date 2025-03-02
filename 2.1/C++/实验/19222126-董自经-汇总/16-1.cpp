16-1-1
# include < iostream>
# include < iomanip>
using namespace std;
void main()
{
	int x = 30, y = 300, z = 1024;
	cout << "Decimal:" << x << ' ' << y << ' ' << z << endl;	     //按十进制输出	
	cout << "Octal:" << oct << x << ' ' << y << ' ' << z << endl;           	// 按八进制输出	
	cout << "Hexadecimal : " << hex << x << ' ' << y << ' ' << z << endl;        //按十六进制输出
	cout << setiosflags(ios::uppercase);	                      //设置数值中字母大写输出	
	cout << "Hexadecimal:" << x << ' ' << y << ' ' << z << endl;	             // 仍按十六进制输出	
	cout << resetiosflags(ios::uppercase);	                // 设置数值中字母小写输出	
	cout << "Hexadecimal:" << x << ' ' << y << ' ' << z << endl;	           //仍按十六进制输出	
	cout << "Decimal:" << dec << x << ' ' << y << ' ' << z << endl;	           // 恢复按十进制输出	
}
16-1-2
# include < iostream>
# include < iomanip>
using namespace std;
void main()
{
	int a = 10; int b = 1000;
	cout << setw(5) << a << "\n"; cout << setw(2) << b;
}*/
16-1-3
# include < iostream>
# include < iomanip>
using namespace std;
void main()
{
	cout << setfill('*')	// 设置填充符号为"*"	
		<< setw(2) << "0K" << endl << setw(3) << "0K" << endl << setw(4) << "0K" << endl;
	cout << setfill(' ');
}
16-1-4
# include < iostream>
# include < iomanip>
using namespace std;
void main()
{
	double test = 22.0 / 7; cout << test << endl;       // C++语言默认的流输出数值有效位为六位
	cout << setprecision(0) << test << endl           // C++语言最小有效位数为一位,此处取1
		<< setprecision(1) << test << endl << setprecision(2) << test << endl << setprecision(3) << test << endl << setprecision(4) << test << endl; cout << setiosflags(ios::fixed);
	cout << setprecision(8) << test << endl;              // setiosflags(ios::fixed)与setprecision(8)合用,控制小数点右边的数字个数为八少	//重新设置成C++语言默认流输出数值有效位数	
	cout << setprecision(6);
}
16-1-5
# include < iostream>
# include < iomanip>
using namespace std;
void main()
{
	cout << setiosflags(ios::right)
		<< setw(5) << 1 << setw(5) << 2 << setw(5) << 3 << endl;
	cout << setiosflags(ios::left)
		<< setw(5) << 1 << setw(5) << 2 << setw(5) << 3 << endl;
}
16-1-6
# include < iostream>
# include < iomanip>
using namespace std;
void main()
{
	double x = 66, y = -8.246; cout << x << " " << y << endl;
	cout << setiosflags(ios::showpoint);	// 设置强制显示小数点和无效0	
	cout << x << " " << y << endl;
}
16-1-7
# include < iostream>
# include < iomanip>
using namespace std;
void main()
{
	double x = 66, y = -8.246; cout << x << " " << y << endl;
	cout << setiosflags(ios::showpos);	// 设置强制显示正号	
	cout << x << " " << y << endl;
}
16-1-8
# include < iostream>
# include < iomanip>
using namespace std;
void main()
{
	char str[250];
	cout << "请输入一字符串:\n";
	cin.getline(str, sizeof(str), ',');
	cout << "输入的字符串为:" << str << endl;
}
16-1-9
# include < iostream>
# include < iomanip>
using namespace std;
void main()
{
	int x = 123;
	double y = -3.456789; cout << "x= ";
	cout.width(10);	// 设置输出下一个数据的域宽为10	
	cout << x;	//按默认的右对齐输出,剩余位置填充空格字符	
	cout << "y = ";
	cout.width(10);	// 设置输出下一个数据的域宽为10	
	cout << y << endl;
	cout.setf(ios::left);	// 设置按左对齐输出	
	cout << "x= "; cout.width(10); cout << x; cout << "y = "; cout.width(10); cout << y << endl;
	cout.fill('*');	// 设置填充字符为'*'	
	cout.precision(3);	// 设置浮点数输出精度为3	
	cout.setf(ios::showpos);	// 设置正数的正号输出	
	cout << "x= "; cout.width(10); cout << x; cout << "y = "; cout.width(10); cout << y << endl;
	cout.setf(ios::scientific);	// 设置按科学表示法输出	
	cout << x << ' ' << y << endl;
	cout.setf(ios::fixed);	// 设置按定点表示法输出	
	cout << x << ' ' << y << endl;
}
16-1-10
#include <iomanip>
#include<iostream>
using namespace std;
class RMB {
public:
	RMB(double v = 0.0) {
		yuan = unsigned(v);
		jf = unsigned((v - yuan) * 100.0 + 0.5);
	}
	operator double() {
		//类类型转换函数
		return yuan + jf / 1000;
	}
	void display(ostream& out) {
		cout << yuan << " ." << setfill('0') << setw(2) << jf << setfill(' ');
	}
protected:
	unsigned int yuan;
	unsigned int jf;
};
ostream& operator << (ostream& ot, RMB& d) {
	d.display(ot);
	return ot;
}
void main(){
	RMB rmb(2.3);
	cout << "Initially rmb = " << rmb << "\n";
	rmb = 2.0 * rmb;
	cout << "then rmb = " << rmb << "\n";
}
16-1-11
#include <iomanip>
#include<iostream>
using namespace std;
class complex {
	float real, imag;
public:
	complex(float r = 0, float i = 0) {
		real = r;
		imag = i;
	}
	friend ostream& operator <<(ostream&, complex&);
	friend istream& operator >>(istream&, complex&);
};
ostream& operator <<(ostream& output, complex& obj) {
	output << obj.real;
	if (obj.imag > 0) output << "+";
	if (obj.imag != 0) output << obj.imag << "i";
	return output;
}
istream& operator >>(istream& input, complex &obj) {
	cout << "Input the real , imag of the complex: n";
	input >> obj.real;
	input >> obj.imag;
	return input;
}
void main() {
	complex c1(2.3, 4.6), c2(3.6, 2.8), c3;
	cout << "the value of cl is :" << c1 << "n";
	cout << "the value of c2 ig ." << c2 << "n";
	cin >> c3;
	cout << "the value of c3 is : " << c3 << "n";
}
16-1-12
#include<iomanip>
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
void main() {
	ofstream myf("d:\ myabc.txt");
	char txt[255];
	while (1) {
		cin.getline(txt, 255);
		if (strlen(txt) == 0)
			break;
		myf << txt << endl;
	}
}
16-1-13
#include<iomanip>
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
void main() {
	char txt[255];
	ifstream myf("d: myabctxt", sizeof(txt));
	if (myf.fail()) {
		//如果要检查文件是否打开,则须调用成员函数 fail()
		//判断是否正确打开文件
		cout << "fileno exist!" << endl;
		return;
	}
	myf >> txt;
	while (!myf.eof()) {
		cout << txt << endl;
		myf >> txt;
	}
}
16-1-14
#include<iomanip>
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<cstdlib>
using namespace std;
int main()
{
	ifstream ifile;//(2)建立文件流对象
	ofstream ofile;
	ifile.open("d: lfileIn,txt");//(3)打开D盘根目录下的 fileIntxt 文件
	ofile.open("d: fileOut,txt");
	if (ifile.fail() || ofile.fail()) {// 测试打开操作是否成功
		cerr << "open file fail\n";
		return EXIT_FAILURE; //返回值EXITFAILURE(在cstdlib库中定义)
	}//用于向操作系统报告终止不成功
	char ch;	ch = ifile.get();//(4)进行读写操作
	while (!ifile.eof()) {
		ofile.put(ch);// 将字符输出到输出文件流对象中
		ch = ifile.get();//从输人文件流对象中读取一个字符
		ifile.close();//(5)关闭文件
		ofile.close();
	}
	return 0;
}
16-1-15
#include<iomanip>
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<cstdlib>
using namespace std;
class student {
public:	char name[10];
	  int num;
	  int age;
	  char addr[15];
	  friend ostream& operator <<(ostream& out, student& g);
	  friend istream& operator >>(istream & in, student & s);
};
ostream& operator <<(ostream& out, student& s) {
	out << s.name << " " << s.num << " " << s.age << " " << s.addr << '\n';
	return out;
}
istream& operator >>(istream& in, student& s) {
	in >> s.name >> s.num >> s.age >> s.addr;
	return in;
}
void main() {
	ofstream ofile;
	ifstream ifile;
	ofile.open("d: ls,txt");
	student s;
	for (int i = 1; 1 <= 3; i++) {
		cout << "请输人第" << i << "个学生的姓名学号、年龄、住址" << endl;
		cin >> s;//调用>>运算符重载函数，输人学生信息
		ofile << s;// 调用<<运算符重载函数将学生信息写人到文件中
	}
	ofile.close();
	cout << "n读出文件内容" << endl;
	ifile.open("d: s,txt");
	ifile >> s;
	while (!ifile.eof()) {
		cout << s;
		ifile >> s;
	}
	ifile.close();
}
16-1-16
#include<iomanip>
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<cstdlib>
#include<math.h>
using namespace std;
void sort(int[], int);
void main() {
	fstream dat, out;
	int i, a[20], b[20];	// 定义文件流对象
	dat.open("filedat", ios::binary|ios::out|ios::in); //为读写打开二进制文件
	if (!dat) {
		cout << ("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < 20; i++) {
		a[i] = rand();
		dat.write((char*)&a[i], sizeof(int));		//将20个数写入文件
	}
	dat.seekg(0);		// 将文件指针移至文件头
	for (i = 0; i < 20; i++) {
		dat.read((char*)&b[i], sizeof(int));		// 读出 20个数
	}
	sort(b, 20);		//调用排序函数
	out.open("file out", ios::out);		//为输出打开文本文件
	if (!out) {
		cout << "cannot open fileln";
		exit(0);
	}
	for (i = 0; i < 20; i++) {
		out << b[i] << ' ';				//将排序后数据写人文本文件
	}
	out << '\n';
	for (i = 0; i < 20; i++) {
		cout << setw(10) << b[1];
		if ((i + 1) % 5 == 0) cout << endl;
	}
	out.close();//关闭文件
	dat.close();
}
void sort(int x[], int m) {				// 排序函数
	int i, j, k, t;
	for (i = 0; i < m - 1; i++) {
		k = i;
		for (j = i + 1; j < m; j++)
			if (x[j] < x[k])
				k = j;
		if (k != i)
			t = x[i], x[i] = x[k], x[k] = t;
	}
}
16-1-17
#include<iomanip>
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<cstdlib>
#include<math.h>
using namespace std;
void main() {
	fstream f("DATA", ios::in | ios::out | ios::binary);
	int i;
	for (i = 0; i < 20; i++)//先向文件中写 20 个二进制位表示的整数无格式
		f.write((char*)&i, sizeof(int));
	streampos pos = f.tellp();	//记录下当前的写指针
	for (i = 20; i < 40; i++)		//再向文件中写20 个二进制位表示的整数无格式
		f.write((char*)&i, sizeof(int));
	f.seekg(pos);// 将读指针定位在 pos 所指的位置
	f.read((char*)&i, sizeof(int));
	cout << "the data stored is " << i << endl;
	f.seekg(0, ios::beg);// 移到文件开始
	for (i = 100; i < 140; i++)	// 重写文件中的内容
		f.write((char*)&i, sizeof(int));
	f.seekg(pos);
	f.read((char*)&i, sizeof(int));//将读指针定位在 pos 所指的位置
	cout << "the data stored is " << i << endl;
}





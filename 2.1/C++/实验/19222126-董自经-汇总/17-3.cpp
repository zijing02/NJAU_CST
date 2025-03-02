#include <iostream>
#include <string>
using namespace std;
int fac(int n)
{
	int result = 1;
	if (n<0)
		throw "Argument for factorial negative";
	else if (n>16)
		throw n;
	while (n)
	{
		result *= n;
		n--;
	}
	return result;
}
void main()
{
	int n;
	char h = 'Y';
	while (h == 'Y' || h == 'y')
	{
		cout << "Please input a number n to calculte n!:";	cin >> n;
		try{
			cout << n << "!=" << fac(n) << endl;
		}
		catch (int){
			cout << "数字太大" << endl;
		}
		cout << "是否继续输入？Y/N" << endl;
		cin >> h;
	}
}
17-4
//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <string>
//using namespace std;
//#define SIZE 10
//class Stack
//{
//private:
//	int stack[SIZE];
//	int tos;
//public:
//	friend class Full;
//	friend class Empty;
//	Stack(){ tos = -1; }
//	~Stack(){}
//	void push(int a)
//	{
//		if (tos >= SIZE - 1)
//			throw Full(a);
//		stack[++tos] = a;
//	}
//	int pop()
//	{
//		if (tos<0)
//			throw Empty();
//		return stack[tos--];
//	}
//	int top()const { return tos; }
//};
//class Empty
//{
//public:
//	Empty(){}
//	void show(){ cout << "stack is empty!" << endl; }
//};
//class Full
//{
//private:
//	int a;
//public:
//	Full(int i) :a(i){}
//	int getValue(){ return a; }
//};
//void main()
//{
//	Stack s;
//	char b[200], i = 0;
//	ifstream infile("data.txt",ios::in);
//	infile >> b;
//	if (!infile)
//	{
//		s.push(b[i++]);
//		cerr << "open data.txt error!" << endl;
//		exit(1);
//	}
//
//}

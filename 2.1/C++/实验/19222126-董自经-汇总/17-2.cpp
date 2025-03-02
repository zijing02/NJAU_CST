#include <iostream>
#include <string>
using namespace std;
double squareroot(double &a)
{
	double n; int i = 0;
	if (a >= 0)//判断输入的数是否为负数；如是，则抛出异常；
		n = sqrt(a);
	else
		throw i;
	throw n;
}
void main()
{
	double m; cin >> m;
	char h = 'Y';
	try
	{
		squareroot(m);
	}
	catch (int)
	{
		cout << "输入的数为负数，无法开方！" << endl;
	}
	catch (double n){
		cout << "平方根是：" << n << endl;
	}
	system("pause");
}
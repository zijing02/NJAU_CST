#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main() {

	//输出100以内的素数
	for (int n = 2; n <= 100; n++) {
		int flag = 0;
		for (int i = 2; i <= n / 2; i++) {
			if (n % i == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) 
			cout << n<<"\t";
	}
	 
	//连续判断素数
	//int n;  char c = 'y';
	//while (c == 'y') {
	//	cout << "请输入一个数字:";
	//	cin >> n;
	//	int flag = 0;
	//		for (int i = 2; i <= n / 2; i++) {
	//			if (n % i == 0) {
	//				flag = 1;
	//				break;
	//			}
	//		}
	//		if (flag == 0) cout << "是素数"<<"\n";
	//		else cout << "不是素数"<<"\n";
	//	cout << "是否继续判断？(y/n)";
	//	cin >> c;
	//}
	// 
	return 0;
}



















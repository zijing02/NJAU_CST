#include<iostream>
#include<cstdio>
#include<string>
#include<iomanip>
#include<stdlib.h>
#define NUM 3
using namespace std;
class Singer {
	string name, gender, song; int age;
public:
	Singer() { cout << "提示信息：调用Singer构造函数!" << endl; }
	~Singer() { cout << "提示信息：调用Singer析构函数!" << endl; }
	void Enroll() {
		cout << "请输入这次报名选手的信息(姓名、性别、年龄、演唱曲目)：";
		cin >> name >> gender >> age >> song;
		cout << endl;
	}
	void Display() {
		cout << name << " " << gender << " " << age << " " << song << endl;

	}
	void Modify() {
		int choose;
		cout << "1.姓名  2.性别  3.年龄  4.演唱曲目" << endl << "请选择需要修改的选项：";
		cin >> choose;
		switch (choose) {
		case 1: cin >> name; break;
		case 2: cin >> gender; break;
		case 3: cin >> age; break;
		case 4: cin >> song; break;
		}
		cout << "歌手信息修改成功！" << endl;
	}
};
void main() {
	int i, num; Singer s[NUM]; char flag1 = 'y', flag2 = 'y';
	while (tolower(flag1) == 'y') {
		cout << "*************************************************************************" << endl;
		cout << "请输入这次报名歌手的数量（<=3）：";
		cin >> num;
		for (i = 0; i < num; i++) 
			s[i].Enroll(); 
		cout << "报名歌手的信息如下所示：" << endl;
		for (i = 0; i < num; i++) 
			s[i].Display(); 
		cout << "是否需要修改报名歌手的信息(Y/N)：";
		cin >> flag2;
		if (tolower(flag2) == 'y') {
			cout << "请输入需要修改的歌手信息序号：";
			int seq;	cin >> seq;
			s[seq - 1].Modify();
			cout << "修改后的歌手信息如下所示：" << endl;
			s[seq - 1].Display();
		}
		cout << "是否继续输入报名歌手的信息?(Y/N) ";
		cin >> flag1;
	}
}
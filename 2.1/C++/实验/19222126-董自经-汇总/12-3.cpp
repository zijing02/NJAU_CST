#include <iostream>
using namespace std;
class student {
public:
	int sno, proclass; string name, gender;
	student() {}
	student(int tempsno, int tempclass, string tempname, string tempgender) :sno(tempsno), proclass(tempclass), name(tempname), gender(tempgender) { cout << name << " " << sno << " " << gender << " " << proclass << " "; }
	void show() { cout << name << " " << sno << " " << gender << " " << proclass << " "; }
	void selectcourse() {}
	void study() {}
	void exam() {}
	void train() {}
	void rest() {}
};
class master:public student {
public:
	int	experimentnum;
	master(int tempsno, int tempclass, string tempname, string tempgender, int tempnum1) :student(tempsno, tempclass, tempname, tempgender), experimentnum(tempnum1) { cout << experimentnum << " "; }
	void show() { cout << experimentnum; }
};
class doctor :public master, public student {
public:
	int papernum;
	doctor(int tempsno, int tempclass, string tempname, string tempgender, int tempnum1, int tempnum2) :master(tempsno, tempclass, tempname, tempgender, tempnum1), papernum(tempnum2) { cout << papernum << " "; }
	void show() { cout << papernum; }
};
int main() {
	doctor d(19222122, 2, "李华", "男", 80, 90); cout << endl;
	master m(19222123, 4, "张三", "女", 100); cout << endl;
	student s(19222124, 6, "王五", "无"); cout << endl;

	return 0;
}

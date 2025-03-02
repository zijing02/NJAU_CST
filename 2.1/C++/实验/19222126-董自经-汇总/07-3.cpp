#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;
const int cnumber = 2;
class Course {
	string cno, cname;
public:
	Course() {}
	Course(string cn, string name) :cno(cn), cname() {}
	void course_show();
};
void Course::course_show() {
	cout << " " << cno << " " << cname;
}
class Score {
	int score;
public:
	Score() {}
	Score(int sco) :score(sco) {}
	void score_show();
};
void Score::score_show() {
	cout << " " << score;
}
class Student {
	int sno; string sname, gender, grade;	Course scourse;	Score sscore;
public:
	Student() {}
	void student_show();
	Student(int tempsno, string tempsname ,string tempgender, string tempgrade,	Course tempscourse,	Score tempsscore) :
		sno(tempsno), sname(tempsname), gender(tempgender), grade(tempgrade), scourse(tempscourse), sscore(tempsscore) {}
};
void Student::student_show(){
	cout << sno << "  " << sname << "  " << gender << "  " << grade << "  ";
	scourse.course_show(); sscore.score_show(); cout << endl;
}
int main() {
	Student  st[cnumber];	Course  cs[cnumber];	Score  ss[cnumber];
	char flag = 'Y';
	while (toupper(flag) == 'Y') {
		cout << "请输入" << cnumber << "个课程及其分数信息（例如：2016116101 张三 男 计科161 COST3114 C++ 90）:" << endl;
		int i, msno, mscore;	string msname, mgender, mgrade, mcno, mcname;
		for (i = 0; i < cnumber; i++) {
			cin >> msno >> msname >> mgender >> mgrade >> mcno >> mcname >> mscore;
			Course tcs(mcno, mcname);		cs[i] = tcs;
			Score tss(mscore);		ss[i] = tss;
			Student tst(msno, msname, mgender, mgrade, tcs, tss);		st[i] = tst;
		}
		cout << "学生课程成绩信息如下:" << endl;
		for (i = 0; i < cnumber; i++) 	st[i].student_show(); 
		cout << "----------------------------------------------------------------------" << endl;
		cout << "继续输入课程成绩吗?(Y/N)";
		cin >> flag;
	}
	return 0;
}
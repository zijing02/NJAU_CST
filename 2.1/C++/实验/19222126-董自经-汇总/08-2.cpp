
exp2-1
#include <iostream>
#include <string>
using namespace std;
class Course{
public:
	int cno;   string cname;
	Course(int cno1, string cname1);
	friend void course_show(Course c){
		cout << " " << c.cno << " " << c.cname;
	}
};
Course::Course(int cno1, string cname1) :cno(cno1), cname(cname1){}
class Score{
	int score;
public:
	friend void score_show(Score ss){
		cout << " " << ss.score << " ";
	}
	Score(int s);
};
Score::Score(int s) :score(s){}
class Student{
	int sno;	string sname, gender, grade;	Course sc;	Score  ss;
public:
	Student(int tempsno, string tempsname, string tempgender, string tempgrade, Course tempsc, Score tempss) : sno(tempsno), sc(tempsc), ss(tempss) {
		sname = tempsname; gender = tempgender; grade = tempgrade;
	}
	void student_show(){
		cout << sno << " " << sname << " " << gender << " " << grade;
		course_show(sc); score_show(ss);
		cout << "\n";
	}
};
void main(){
	Course cs1(19218120, "C++");	Score sc1(90);
	Student st1(201811219, "张三", "男", "计科161", cs1, sc1);
	st1.student_show();
}


exp2-2

#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;
const int cnumber = 2;
class Course{
	string cno, cname;
public:
	Course(){};
	Course(string tempcno, string tempcname) :cno(tempcno), cname(tempcname){}
	friend void course_show(Course sc){
		cout << " " << sc.cno << " " << sc.cname;
	}
};
class Score{
	int score;
	friend class Student;
public:
	Score(){};
	Score(int tempss) :score(tempss){}
	void score_show(){
		cout << " " << score << " ";
	}
};
class Student{
	int sno; string sname, gender, grade;	Course sc;	Score ss;
public:
	Student(){};
	Student(int tempsno, string tempsname, string tempgender, string tempgrade, Course tempsc, Score tempss) : sno(tempsno), sc(tempsc), ss(tempss) {
		sname = tempsname; gender = tempgender; grade = tempgrade;
	}
	void student_show(){
		cout << sno << " " << sname << " " << gender << " " << grade;
		course_show(sc); ss.score_show();
		cout << "\n";
	}
};

//2019119101 李四 男 计科191 COST3113 C++ 95
//2019219201 王五 女 网工192 COST3114 C++ 90
void main(){
	Student  st[cnumber];	Course  cs[cnumber];	Score  ss[cnumber];
	char flag = 'Y';
	while (toupper(flag) == 'Y'){
		cout << "请输入" << cnumber << "个课程及其分数信息（2016116101 张三 男 计科161 COST3114 C++ 90）:" << endl;
		int i, msno, mscore;	string msname, mgender, mgrade, mcno, mcname;
		for (i = 0; i<cnumber; i++)	{
			cin >> msno >> msname >> mgender >> mgrade >> mcno >> mcname >> mscore;
			Course tcs(mcno, mcname);		cs[i] = tcs;
			Score tss(mscore);		ss[i] = tss;
			Student tst(msno, msname, mgender, mgrade, tcs, tss);		st[i] = tst;
		}
		cout << "学生课程成绩信息如下:" << endl;
		for (i = 0; i<cnumber; i++)	{ st[i].student_show(); }
		cout << "----------------------------------------------------------------------" << endl;
		cout << "继续输入课程成绩吗?(Y/N)";
		cin >> flag;
	}
}
2.1
#include <iostream>
#include <string>
using namespace std;
class Course {
public:
	int cno;    string cname;
	Course(int tempcno, string tempcname) :cno(tempcno), cname(tempcname) {}
	void course_show();
};
void Course::course_show() {
	cout << " " << cno << " " << cname;
}
class Score {
	int score;
public:
	Score(int tempss) :score(tempss) {}
	void score_show();
};
void Score::score_show() {
	cout << " " << score << endl;
}
class Student {
	int sno;string sname, gender, grade;Course sc;	Score  ss;
public:
	Student(int tempsno, string tempsname, string tempgender, string tempgrade, Course tempsc, Score tempss) :
		sno(tempsno), sname(tempsname), gender(tempgender), grade(tempgrade), sc(tempsc), ss(tempss) {}
	void student_show();
};
void Student::student_show() {
	cout << sno << " " << sname << " " << gender; sc.course_show(); ss.score_show();
}

void main() {
	Course cs1(19218120, "C++");	Score sc1(90);
	Student st1(201811219, "张三", "男", "计科161", cs1, sc1);
	st1.student_show();
}
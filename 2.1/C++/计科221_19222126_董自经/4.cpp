#define strmax 32
#include<iostream> 
using namespace std;
class MyClass {       
	char name[strmax]; 	int dailyscore;   
public:       
	MyClass(char str[strmax], int x):dailyscore(x){ strcpy_s(name, str); }       
	int Strlength() { return strlen(name); }
	friend int Score(MyClass);    //要求；不准写出形参。                                   
	friend void Print(MyClass);    //要求；不准写出形参。
}; 
int  Score(MyClass c1) { return c1.dailyscore + c1.Strlength(); }
void Print(MyClass c2) { 
	cout << "The CourseName  is: " << c2.name<< endl;    
	cout << "The CourseScore is: " << Score(c2) << endl; 
}
void  main() { 
	char str[strmax] = "C++ Programing!";  
	MyClass c(str, 80); Print(c); }
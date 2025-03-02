#include<iostream>
#include<cstdio>
#include<stdlib.h>
using namespace std;
int cnt=1;
int main(){
	//2汉诺塔
	void hanoi(int,char,char,char);
	void move(char,int,char);
	int n;cin>>n;
	char x='A',y='B',z='C';
	hanoi(n,x,y,z);
	return 0;
}	
void move(char a,int n,char b){
	cout<<cnt++<<":"<<n<<" "<<a<<"->"<<b<<endl;
}
void hanoi(int n,char x,char y,char z){
	if(n==1)move(x,1,z);//如果只有一个直接移动
	else{
		hanoi(n-1,x,z,y);//将x塔上的n-1个盘子移动到y塔上，z作为辅助塔
		move(x,n,z);//将x塔上的第n个盘子移动到塔上
		hanoi(n-1,y,z,x);//将y盘上的n-1个盘子移动到z塔上，x作为辅助塔
	}
}
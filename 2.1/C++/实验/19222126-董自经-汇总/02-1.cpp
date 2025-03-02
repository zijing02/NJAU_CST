#include<iostream>
#include<cstdio>
#include<stdlib.h>
using namespace std;
int cnt=1;
int main(){
	//1水仙花统计与判断
/*	int i,t=0,m;
	for(i=100;i<1000;i++){
		m=i;t=0;
		while(m){
			t+=(m%10)*(m%10)*(m%10);
			m=m/10;
		}
		if(t==i) cout<<t<<"\t";
	}
*/
/*
	int i,t,m,n,s=0;
	for(i=100;i<1000;i++){
		t=i%10;m=i/100;n=(i/10)%10;
		s=t*t*t+m*m*m+n*n*n;
		if(s==i) cout<<s<<"\t";
	}
*/
/*
	int i,m,t;cin>>i;m=i;t=0;
	while(m){
		t+=(m%10)*(m%10)*(m%10);
		m=m/10;
	}
	if(t==i) cout<<"yes"<<"\t";
	return 0；
}
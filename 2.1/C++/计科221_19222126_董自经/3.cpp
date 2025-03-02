#include<iostream>
using namespace std;
class  A{ 
public:       
	int  i, j, *p;      
	A(){ i = 10; j = 10;p=&i; }
};
int A::*p = &A::j;
void  main(){
	A  a, b;    
	(b.*p)++;   
	--*a.p;  
	cout << "A:" << *a.p << "  B:" << *b.p << "  ";
	cout << "A:" << a.*p << "  B:" << b.*p << "\n";    
} 

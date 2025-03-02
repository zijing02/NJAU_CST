package T2_t2;

public class Fact {
	int num,den;
	Fact(){}
	Fact(int n,int d){num=n;den=d;concise();}
	public void set(int n,int d) {num=n;den=d;}
	public void get() {p();}
	public void compare(Fact t) {
		double i1=num/den,i2=t.num/t.den;
		if(i1>i2)
			System.out.print(i1>i2);
		else 
			System.out.print(i2>i1);
	}
	public void concise() {
		int c;
		int a=num,b=den;
		while(b!=0) {
			c=a%b;a=b;b=c;			
		}
		num/=a;den/=a;
	}
	public void tongfen(Fact t) {
		int m=den%t.den;//a是最小公约数
		int a=den,b=t.den;
		while(b!=0) {
			m=a%b;a=b;b=m;
		}
		int x=den*t.den/a;//x是最大公倍数
		num=num*x/den;t.num=t.num*x/t.den;
		den=x;t.den=x;
	}
	public void add(Fact t) {tongfen(t);num+=t.num;concise();System.out.print("+:");p();}
	public void min(Fact t) {tongfen(t);num-=t.num;concise();System.out.print("-:");p();}
	public void div(Fact t) {num*=t.den;den*=t.num;concise();System.out.print("*:");p();}
	public void mul(Fact t) {num*=t.num;den*=t.den;concise();System.out.print("\\:");p();}
	public void p() {System.out.print(""+num+"/"+den+"\n");}

}

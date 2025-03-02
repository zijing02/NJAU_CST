package T2_t1;

public class complex {
	private double real,img;
	public complex() {}
	public complex(double r,double i) {real = r;img = i;}
	void set(double r,double i) {real=r;img=i;}
	void get() {p();}
	public void add(complex a) {
		real=real + a.real;
		img=img + a.img;
		p();
	}
	public void min(complex a) {
		real=real - a.real;
		img=img - a.img;
		p();
	}
	public void mul(complex a) {
		real=real*a.real - img*a.img;
		img=real*a.img + img*a.real;
		p();
	}
	public void div(complex a) {
		real=(real*a.real+img*a.img)/(a.img*a.img + a.real*a.real);
		img=(img*a.real-real*a.img)/(a.img*a.img + a.real*a.real);
		p();
	}
	void p() {System.out.print("("+real+","+img+")");System.out.println();}

}

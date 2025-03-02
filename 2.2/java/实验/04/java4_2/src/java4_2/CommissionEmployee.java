package java4_2;

import java.util.Scanner;

public class CommissionEmployee extends Employee{
	Scanner sc=new Scanner(System.in);
	private int rate,sal,ybonus,salpm;
	public CommissionEmployee() {}
	public CommissionEmployee(int tr,int ts,int ty,int ts1){
		rate=tr;sal=ts;ybonus=ty;salpm=ts1;
	}
	public void setfkb() {
		rate=sc.nextInt();sal=sc.nextInt();
		ybonus=sc.nextInt();salpm=sc.nextInt();
	}
	public int getrate() {return rate;}
	public int getsal() {return sal;}
	public int getybonus() {return ybonus;}
	public int getsalpm() {return salpm;}
	public int cal_off() {return sal/100;}
	public int cal_bonus() {return sal*salpm/1000;}
	public void Print() {System.out.println(rate+" "+sal+" "+ybonus+" "+salpm);}
}

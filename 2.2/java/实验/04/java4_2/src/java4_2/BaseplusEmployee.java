package java4_2;

import java.util.Scanner;

public class BaseplusEmployee extends CommissionEmployee{
	Scanner sc=new Scanner(System.in);
	private int weeksalary;
	public BaseplusEmployee(int t,int s1,int s2,int s3,int s4) {super(s1,s2,s3,s4);weeksalary=t;}
	public int cal_off() {int s=super.getsal();return s/100;}
	public int cal_bonus() {int s=super.getsal()*super.getsalpm();
		return s/1000;}
	public void set(int t) {weeksalary=t;}
	public int getw() {return weeksalary;}
	public void print() {System.out.println(weeksalary);}
}

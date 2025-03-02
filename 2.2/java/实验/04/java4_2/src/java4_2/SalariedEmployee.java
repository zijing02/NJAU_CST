package java4_2;
import java.util.Scanner;

public class SalariedEmployee extends Employee {
	Scanner sc=new Scanner(System.in);
	private int salary,allowance,year,bonus;
	public SalariedEmployee(){}
	public SalariedEmployee(int ts,int ta,int ty,int tb) {
		salary=ts;allowance=ta;year=ty;bonus=tb;}
	public int getsalary() {return salary;}
	public int getallowance() {return allowance;}
	public int getyear() {return year;}
	public int getbonus() {return bonus;}
	public void set(int ts,int ta,int ty,int tb) {
		salary=ts;allowance=ta;year=ty;bonus=tb;}
	public void setfkb() {
		salary=sc.nextInt();allowance=sc.nextInt();
		year=sc.nextInt();bonus=sc.nextInt();
	}

}

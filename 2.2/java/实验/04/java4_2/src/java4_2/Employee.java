package java4_2;
import java.util.Scanner;

public class Employee {
	Scanner sc=new Scanner(System.in);
	private String name,gender;private int num,year;
	public Employee(){}
	public Employee(String tname,int tnum,String tgender,int tyear) {
		name=tname;num=tnum;gender=tgender;year=tyear;}
	public String getname() {System.out.println(name);return name;}
	public String getgender() {System.out.println(gender); return gender;}
	public int getnum() {System.out.println(num); return num;}
	public int getyear() {System.out.println(year); return year;}
	public void setfromkeyboard() {
		System.out.println("请依次输入姓名、性别、保险号、工作年限");
		name=sc.nextLine();gender=sc.nextLine();num=sc.nextInt();year=sc.nextInt();}
	public void set(String tname,int tnum,String tgender,int tyear) {
		name=tname;num=tnum;gender=tgender;year=tyear;}
	public void Print() {
		System.out.println(name+" "+gender+" "+num+" "+year);}
}

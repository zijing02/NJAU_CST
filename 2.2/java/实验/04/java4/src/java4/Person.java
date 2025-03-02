package java4;

public class Person {
	private String name;
	private int ID;
	public Person(){}//补充无参的构造函数
	public Person(String theName) {	this.name = theName;}
	public Person(String tname,int tID){name=tname;ID=tID;}//补充2个参数的构造函数
	public String getName() {return name;}
	public void set(String tName,int tid){name=tName;ID=tid;}
	public int getID(){return ID;}//补充一组set方法和一组get方法
	void print() {	System.out.println("name :"+name+"ID:"+ID);}
}

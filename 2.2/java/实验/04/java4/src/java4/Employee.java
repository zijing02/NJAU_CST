package java4;

public class Employee extends Person {
	private String company;
	Employee(){}//补充无参的构造函数
	public Employee(String name, int ID, String	company) {	
		//this.name = name;	this.ID=ID;		//error, 请修改
		this.set(name, ID);
		this.company = company;
	}
	//补充set方法
	public String getCompany () {	return company;}//company是String，不能使用int返回
	void print(){}//补充能输出所有属性
}

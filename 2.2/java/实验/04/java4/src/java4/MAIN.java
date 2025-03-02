package java4;

public class MAIN {
	public static void main(String args[]) {
		Person p1=new Person("Mike",123453);//创建 Person类的对象 p1,他的名字是 Mike,ID 是 123453
		System.out.println(p1.getName()); //Mike
		Person p2=new Person("Dani",123456);//创建 Person类的对象 p2,他的名字是 Dani,ID 是 123456
		System.out.println(p2.getName()); //输出什么? ans:Dani
		System.out.println(p2.getID());		// 输出什么 ans:123456
		Person p3 = new Employee("Tom", 1211,"Microsoft");
		System.out.println(p3.getName()); //输出什么? ans:Tom
		System.out.println(p3.getID());		// 输出什么 ans:1211
		//Employee p4 = new Person("Mike"); //error为什么?	ans:子类不能向父类转换，父类可以向子类转换
		Employee emp = new Employee("Dani", 213223,"DEC");
		System.out.println(emp.getName()); ///输出什么? ans:Dani
		System.out.println(emp.getID());		///输出什么? ans:213223

	}
}

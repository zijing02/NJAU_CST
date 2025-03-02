package t1;

public class master {
	private int age; double weight; String name; 
	public animal a;food f; 
	public master(int a,double w,String n) {age=a;weight=w;name=n;}
	public void feed(animal a,food f) {System.out.println("主人用" + f.name + "喂了" + a.name);a.eat(f);pic();}	
	public void pic() {}
}

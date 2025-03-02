package t1;

public class animal {
	public String name;int weight;String fa;int age;int state=0;int volume;
	public void eat(food f) {
		if(f.check()==1)
			if (fa==f.name){
				System.out.println(name+"吃了"+f.name);
				cry(f);
			}
			else 
				System.out.println("喂错了");			
		else {
			System.out.println("该换了");
			System.out.println(name+"没吃到东西冲你叫了两声");		
		}

	}
	public void setname(String n) {name=n; }
	public void setage(int a) {age = a; }
	public void setweight(int w) {weight = w;}
	public void cry(food f) {if(volume<f.use){System.out.print(name+"吃饱了并发出了开心的呼呼声\n");act();}else { System.out.println(name+"没吃饱，想要再吃一点");}}
	public void act(){if (name=="猫")System.out.println(name+"在你怀里伸了一个懒腰");else System.out.println(name+"尾巴摇的更快了");}

}

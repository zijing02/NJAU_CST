package t1;

public class food {
	public String name;int pd;int sd;int total;int use;
	public int check() {
		if(sd>pd){
			System.out.print("食物已经过期，无法使用");
			return 0;
		}
		else {
			System.out.println("食物可以使用");
			return 1;}
		}
	public void min() {total-=use;int t=total;if(t<=0)System.out.println("食物已经吃完，请补充");}
}

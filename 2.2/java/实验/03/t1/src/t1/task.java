package t1;
import java.util.Scanner;
public class task {
	public static void main(String args[]) {
	Scanner sc=new Scanner(System.in);
	master m= new master(20,70,"李华");
	dog d=new dog("狗",30,4,"骨头");
	cat c=new cat("猫",4,"鱼",2);
	bone b=new bone("骨头",1008,2980,780,10);
	fish f= new fish("鱼",340,76,100,0);
	m.feed(d, b);m.feed(c, f);
	}
}

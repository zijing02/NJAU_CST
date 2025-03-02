package T2_t2;
import java.security.PublicKey;
import java.util.Scanner;
public class task {
	public static void main(String args[]) {
		Scanner sc=new Scanner(System.in);
		int i=sc.nextInt(),j=sc.nextInt(),m=sc.nextInt(),n=sc.nextInt();
		Fact a = new Fact();
		Fact b = new Fact();
		a.set(i, j);b.set(m,n);
		a.get();b.get();a.p();b.p();
		a.set(i, j);a.add(b);
		a.set(i, j);a.min(b);
		a.set(i, j);a.div(b);
		a.set(i, j);a.mul(b);
		
	}
}

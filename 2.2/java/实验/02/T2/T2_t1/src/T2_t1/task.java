package T2_t1;
import java.security.PublicKey;
import java.util.Scanner;
public class task {
	public static void main(String args[]) {
		Scanner sc=new Scanner(System.in);
		double i=sc.nextDouble();double j=sc.nextDouble();
		complex a = new complex(i,j);
		complex b = new complex(3,4);
		a.get();
		a.set(i, j);a.add(b);
		a.set(i, j);a.min(b);
		a.set(i, j);a.div(b);
		a.set(i, j);a.mul(b);
	}

}

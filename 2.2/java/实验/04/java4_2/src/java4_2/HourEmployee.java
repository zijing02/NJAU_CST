package java4_2;

public class HourEmployee extends Employee{
	private int hour,hs;
	public HourEmployee(int h1,int h2) {hour=h1;hs=h2;}
	public void set(int h1,int h2) {hour=h1;hs=h2;}
	public int gethour() {return hour;}
	public int geths() {return hs;}
	public void print() {System.out.println(hour+" "+hs);}
}

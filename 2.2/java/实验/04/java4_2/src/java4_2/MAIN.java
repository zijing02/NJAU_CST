package java4_2;

public class MAIN {
	public static void main(String args[]) {
		Employee p1=new Employee("jac",123,"男",12);
		p1.Print();
		CommissionEmployee p2=new CommissionEmployee(1,2,3,4);
		p2.setfkb();p2.Print();p2.cal_bonus();p2.cal_off();
		SalariedEmployee p3=new SalariedEmployee(9,10,11,12);
		p3.setfkb();p3.Print();
		HourEmployee p4=new HourEmployee(17,18);
		p4.print();
		BaseplusEmployee p5=new BaseplusEmployee(19,20,21,22,23);
		p5.print();p5.setfkb();p5.cal_bonus();p5.cal_off();
		
	}
}

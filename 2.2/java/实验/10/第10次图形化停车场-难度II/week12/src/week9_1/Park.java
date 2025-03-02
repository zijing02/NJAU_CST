package week9_1;

import java.util.Scanner;

public class Park {
	private String ParkName;
	private String ParkID;
	private String ParkManagement;
	private String Staff;
	private int Capacity;
	private int	EnterNum;
	private Car cars[];
	private int turnover;
	
	public Park(){
		ParkName = new String ("Park");
		ParkID = new String ("123456");
		ParkManagement = new String ("Company");
		Staff = new String ("Peter");
		this.Capacity = 100 ;
		this.EnterNum = 0;
		this.cars = new Car[Capacity];
		this.turnover = 0;
	}
	
	public Park(	String name,
					String id,
					String manage,
					String st,
					int c,
					int en,
					Car car[],
					int t){
		this.ParkName = name;
		this.ParkID = id;
		this.ParkManagement = manage;
		this.Staff = st;
		this.Capacity = c;
		this.EnterNum = en;
		this.cars = car;
		this.turnover = t;
	}
	
	public void InputName(){
		System.out.print("输入停车场名称：");
		Scanner in = new Scanner(System.in);
		this.ParkName = in.nextLine();
		in.close();
	}
	public void ShowName(){
		System.out.println("停车场名称："+this.ParkName);
	}
	
	public void InputID(){
		System.out.println("输入停车场ID：");
		Scanner in = new Scanner(System.in);
		this.ParkID = in.nextLine();
		in.close();
	}
	public void ShowID(){
		System.out.println("停车场ID："+this.ParkID);
	}
	
	public void InputManage(){
		System.out.println("输入停车场管理单位：");
		Scanner in = new Scanner(System.in);
		this.ParkManagement = in.nextLine();
		in.close();
	}
	public void ShowManage(){
		System.out.println("停车场管理单位："+this.ParkManagement);
	}
	
	public void InputCapacity(){
		System.out.println("输入停车场容量："+this.Capacity);
		Scanner in = new Scanner(System.in);
		this.Capacity = in.nextInt();
		in.close();
	}
	public void ShowCapacity(){
		System.out.println("输出停车场容量："+this.Capacity);
	}
	
	public void InputStaff(){
		System.out.println("输入值班人员名称：");
		Scanner in = new Scanner(System.in);
		this.Staff = in.nextLine();
		in.close();
	}
	public void ShowStaff(){
		System.out.println("输入值班人员名称："+this.Staff);
	}
	
	public int GetCapacity(){
		return this.Capacity;
	}
	
	public String GetCarID(int i) {
		return this.cars[i].getCarID();
	}
	
	public String GetCarInTime(int i) {
		return this.cars[i].getInTime();
	}
	public void CarIn(Car car){
		car.setFare(0);
		for(int i=0;i<this.Capacity;i++){
			if (cars[i]==null){
				this.cars[i]=car;
				break;
			}
		}
		this.EnterNum++;
	}
	

	public void CarIn(int i,Car car) {
		if(this.cars[i]!=null) {
			return;
		}
		car.setFare(0);
		this.cars[i]=car;
		this.EnterNum++;
	}
	
	public Car CarOut(String id,String time){
		for (int i=0;i<this.Capacity;i++){
			if(this.cars[i]!=null&&this.cars[i].getCarID()==id){
				Car c = this.cars[i];
				c.setOutTime(time);
				if(c.getMF()==true){
					c.MonthlyBill();
				}
				else{
					c.HourlyBill();
					//c.showFare();
				}
				this.turnover+=c.getFare();
				//System.out.println(c.getFare());
				this.cars[i] = null;
				this.EnterNum--;
				return c;
			}
		}
		return null;
	}
	
	public Car CarOut(int i,String time) {
		if(this.cars[i]==null) {
			return null;
		}
		Car c = cars[i];
		cars[i] = null;
		c.setOutTime(time);
		if(c.getMF()==true){
			c.MonthlyBill();
		}
		else{
			c.HourlyBill();
			//c.showFare();
		}
		this.turnover+=c.getFare();
		//System.out.println(c.getFare());
		this.EnterNum--;
		return c;
	}
	
	public boolean IsEmpty(){
		if (this.EnterNum==0){
			return true;
		}
		return false;
	}
	
	public boolean IsEmpty(int i) {
		if (cars[i]==null) {
			return true;
		}
		return false;
	}
	
	public boolean IsFull(){
		if(this.EnterNum==this.Capacity){
			return true;
		}
		return false;
	}
	public void ShowEmpty(){
		System.out.println("空车位:");
		for (int i=0;i<this.Capacity;i++){
			if(this.cars[i]==null){
				System.out.print(""+i+"\t");
			}
			else{
				System.out.print("\t");
			}
			if((i+1)%4==0){
				System.out.println("");
			}
		}
	}
	public void ShowEmptyNum(){
		System.out.println("空车位个数："+(this.Capacity-this.EnterNum));
	}
	public int getEmptyNum() {
		return (this.Capacity-this.EnterNum);
	}
	public boolean[] GetEmpty(){			//空为true，有车为false
		boolean e[] = new boolean[this.Capacity];
		for (int i=0;i<this.Capacity;i++){
			if (this.cars[i]==null)
				e[i]=true;
			else {
				e[i]=false;
			}
		}
		return e;
	}
}

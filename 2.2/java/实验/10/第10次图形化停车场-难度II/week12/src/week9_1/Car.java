package week9_1;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

public class Car {
	private String CarID;
	private SimpleDateFormat df;
	private Date  InTime;
	private Date  OutTime;
	private boolean MF;			//按月缴费标志
	private float fare;
	
	public Car(){
		this.CarID = new String ("00000");
		this.df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		try{
			this.InTime = df.parse("2018-10-10 10:10:10");
			this.OutTime = df.parse("0000-00-00 00:00:00");
		}catch(Exception e){
			e.printStackTrace();
		}
		this.MF=false;
		this.fare = 0;
	}
	public Car(	String id,
				String  it,
				String  ot,
				boolean mf,
				float f){
		this.CarID=id;
		try{
			this.InTime=df.parse(it);
			this.OutTime=df.parse(ot);
		}catch (Exception e){
			e.printStackTrace();
		}
		this.MF=mf;
		this.fare=f;
	}
	public void setCarID(String id){
		this.CarID=id;
	}
	public String getCarID(){
		return this.CarID;
	}
	public void inputCarID(){
		Scanner in =new Scanner(System.in);
		System.out.print("���복�ƺţ�");
		String id = in.nextLine();
		in.close();
		this.CarID=id;
	}
	public void setInTime(String  it){
		try{
			this.InTime=this.df.parse(it);
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	public String  getInTime(){
		return this.InTime.toString();
	}
	public void inputInTime(){
		Scanner in =new Scanner(System.in);
		System.out.print("输入入场时间(yyyy-mm-dd HH::mm:ss)：");
		String str = in.nextLine();
		in.close();
		try{
			this.InTime=this.df.parse(str);
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	public void setOutTime(String  ot){
		try{
			this.OutTime=this.df.parse(ot);
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	public String  getOutTime(){
		return this.OutTime.toString();
	}
	public void inputOutTime(){
		Scanner in =new Scanner(System.in);
		System.out.print("输入出场时间(yyyy-mm-dd HH::mm:ss)：");
		String str = in.nextLine();
		in.close();
		try{
			this.OutTime=this.df.parse(str);
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	public void setMF(boolean mf){
		this.MF=mf;
	}
	public boolean getMF(){
		if(this.OutTime.getTime()-this.InTime.getTime()>24*60*60*1000*300) MF = true;
		else MF = false;
		return this.MF;
	}
	public void inputMF(){
		Scanner in =new Scanner(System.in);
		System.out.print("输入按月缴费标志（按月true，不按月false）：");
		boolean mf = in.nextBoolean();
		in.close();
		this.MF=mf;
		
	}
	public void setFare(float f){
		this.fare = f;
	}
//	public void setFare(){
//		if(this.OutTime.getTime()-this.InTime.getTime()>24*60*60*1000*300) MonthlyBill();
//		else HourlyBill();
//	}
	public float getFare(){
		return this.fare;
	}
	public void inputFare(){
		Scanner in =new Scanner(System.in);
		System.out.print("输入应缴停车费：");
		float f = in.nextFloat();
		in.close();
		this.fare=f;
	}
	public void showFare() {
		System.out.println("Fare��"+this.fare);
	}
	public void displayAll(){
		System.out.print(	"车牌号: "+this.CarID+
							"\t入场时间："+this.InTime.toString()+
							"\t出场时间："+this.OutTime.toString()+
							"\t停车费用："+this.fare+
							"\r\n");	
	}
	public void RegInInfo(	String id,
							String  it,
							boolean mf){
		this.CarID=id;
		try{
			this.InTime=this.df.parse(it);
		}catch(Exception e){
			e.printStackTrace();
		}
		this.MF=mf;
		
	}
	public void RegOutInfo(	String  ot,
							float f){
		try{
			this.OutTime=this.df.parse(ot);
		}catch(Exception e){
			e.printStackTrace();
		}
		this.fare=f;
		
	}
	public void MonthlyBill(){
		long l = this.OutTime.getTime()-this.InTime.getTime();
		System.out.println(l);
		long days = (long) l / (24 * 60 * 60 * 1000);
		long month = days / 30;
		System.out.println(month);
		this.fare = ((int)month) * 800;
		System.out.println(fare);
	}
	public void HourlyBill(){
		float f = 0;
		double dayf = 0;
		dayf = 1.5*(4*6-1)+8*4*2+10*0.5;
		long intime = this.InTime.getTime()+8*60*60*1000;
		long outtime = this.OutTime.getTime()+8*60*60*1000;
		long l = outtime - intime;
		long day = l/(24*60*60*1000);
		int inhour =(int) (intime %( 24*60*60*1000))/(60*60*1000);
		int outhour =(int) (outtime %( 24*60*60*1000))/(60*60*1000);
		int inminute = (int) (intime %( 60*60*1000))/(60*1000);
		int outminute = (int) (outtime %( 60*60*1000))/(60*1000);
		int insecond = (int) (intime %( 60*1000))/(1000);
		int outsecond = (int) (outtime %( 60*1000))/(1000);
		//System.out.println(""+inhour+"\t"+inminute+"\t"+insecond);
		//System.out.println(""+outhour+"\t"+outminute+"\t"+outsecond);
		if(day>=1){
			for(;day>=1;day--){
				f +=dayf;
			}
		}
		if(day ==0){
			this.fare=f;
			
		}
		if(inhour < outhour){
			
			if (inhour >= 20 || outhour < 6){
				this.fare += (outhour-inhour)*0.5;
				if (outminute > inminute || outminute == inminute && outsecond > insecond){
					this.fare += 0.5;
				}
				return;
			}
			if (inhour < 6){
				this.fare += (6-inhour)*0.5;
				inhour = 6;
				inminute = 0;
			}
			if (outhour >20){
				this.fare += (outhour - 20)*0.5;
				if(outminute > 0 || outsecond > 0){
					this.fare += 0.5;
				}
				outhour = 20 ;
				outminute = 0;
			}
			int diffminute = (outhour-inhour)*60+outminute-inminute;
			if (outsecond > insecond){
				diffminute ++;
			}
			for(int i=0;i<24&&diffminute>0;i++ ){
				diffminute -= 15;
				if (i!=0){
					this.fare += 1.5;
				}
			}
			for(int i=0;i<32&&diffminute>0;i++){
				diffminute -= 15;
				this.fare += 2;
			}
			
			return ;
		}
		else if (inhour > outhour){
			if (outhour >= 20){
				this.fare+=(6+24-inhour)*0.5;
				this.fare+=(outhour-20)*0.5;
				if (outminute > 0){
					this.fare+=0.5;
				}
				int diffminute = (20-6)*60;
				for(int i=0;i<24&&diffminute>0;i++ ){
					diffminute -= 15;
					if (i!=0){
						this.fare += 1.5;
					}
				}
				for(int i=0;i<32&&diffminute>0;i++){
					diffminute -= 15;
					this.fare += 2;
				}
				return;
			}
			if (inhour<6){
				this.fare += (outhour+24-20)*0.5;
				this.fare += (6-inhour)*0.5;
				if (outminute > 0){
					this.fare+=0.5;
				}
				int diffminute = (20-6)*60;
				for(int i=0;i<24&&diffminute>0;i++ ){
					diffminute -= 15;
					if (i!=0){
						this.fare += 1.5;
					}
				}
				for(int i=0;i<32&&diffminute>0;i++){
					diffminute -= 15;
					this.fare += 2;
				}
				return;
			}
			if (inhour<20){
				int diffminute = (20-inhour)*60-inminute;
				for(int i=0;i<24&&diffminute>0;i++ ){
					diffminute -= 15;
					if (i!=0){
						this.fare += 1.5;
					}
				}
				for(int i=0;i<32&&diffminute>0;i++){
					diffminute -= 15;
					this.fare += 2;
				}
				inhour = 20;
				inminute = 0;
			}
			if (outhour>6||outhour==6&&outminute>0){
				int diffminute = (outhour-6)*60+outminute;
				for(int i=0;i<24&&diffminute>0;i++ ){
					diffminute -= 15;
					if (i!=0){
						this.fare += 1.5;
					}
				}
				for(int i=0;i<32&&diffminute>0;i++){
					diffminute -= 15;
					this.fare += 2;
				}
				outhour = 6;
				outminute = 0 ;
			}
			this.fare += (outhour+24-inhour)*0.5;
			if (outminute>inminute){
				this.fare++;
			}
		}
		else if (inhour == outhour){
			if(outminute > inminute){
				if (outhour<6||outhour>=20){
					this.fare+=0.5;
				}
				else{
					int diffminute = outminute-inminute;
					for(int i =0 ; diffminute >0;i++){
						diffminute -= 15;
						if(i!=0){
							this.fare+=1.5;
						}
					}
				}
			}
			else if (outminute < inminute){
				if(outhour<6||outhour>=20){
					this.fare+=dayf;
					return;
				}
				else {
					this.fare += (6+24-20)*0.5;
					int diffminute = (20-inhour)*60-inminute;
					for(int i=0;i<24&&diffminute>0;i++ ){
						diffminute -= 15;
						if (i!=0){
							this.fare += 1.5;
						}
					}
					for(int i=0;i<32&&diffminute>0;i++){
						diffminute -= 15;
						this.fare += 2;
					}
					diffminute = (outhour-6)*60+outminute;
					for(int i=0;i<24&&diffminute>0;i++ ){
						diffminute -= 15;
						if (i!=0){
							this.fare += 1.5;
						}
					}
					for(int i=0;i<32&&diffminute>0;i++){
						diffminute -= 15;
						this.fare += 2;
					}
				}
			}
			else{
				if(outsecond < insecond){
					this.fare+=dayf;
				}
			}
		}
	}
	
}

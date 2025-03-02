package week9_1;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class CarOutJFrame extends JFrame implements ActionListener{
	//����
	Park park;
	int parki;
	JLabel jlbwel;
	JLabel jlbInTime;
	JLabel jlbYear = new JLabel("年");
	JLabel jlbMonth = new JLabel("月");
	JLabel jlbDay = new JLabel("日");
	JLabel jlbHour = new JLabel("时");
	JLabel jlbMinute = new JLabel("分");
	JLabel jlbSecond = new JLabel("秒");
	
	JTextField jtfYear = new JTextField(4);
	JTextField jtfMonth = new JTextField(2);
	JTextField jtfDay = new JTextField(2);
	JTextField jtfHour = new JTextField(2);
	JTextField jtfMinute = new JTextField(2);
	JTextField jtfSecond = new JTextField(2);
	
	JButton jbnconfirm = new JButton("确认出场");
	JButton jbncancel = new JButton("取消出场");
	
	public CarOutJFrame (Park p , int i) {
		super("车辆出场界面");
		this.park=p;
		this.parki=i;
		init();
		setVisible(true); 
		this.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
	}
	
	public void init() {
		jlbwel = new JLabel(""+parki+"号停车位停的车的车牌号是"+park.GetCarID(parki));
		jlbInTime = new JLabel("入场时间是："+park.GetCarInTime(parki));
		
		//jlbwel = new JLabel(""+parki+"号停车位停的车的车牌号是");
		//jlbInTime = new JLabel("入场时间是：");

		
		Container  con=this.getContentPane();
		this.setSize(400,180);
		Dimension dim = new Dimension(400,50);
		JPanel jpNorth = new JPanel();
		JPanel jpSouth = new JPanel();
		JPanel jpCenter = new JPanel();
		
		con.setLayout(new BorderLayout());
		con.add(jpNorth,"North");
		con.add(jpCenter,"Center");
		
		jpSouth.setPreferredSize(dim);
		jpSouth.setLayout(new FlowLayout());
		jpSouth.add(jbnconfirm);
		jpSouth.add(jbncancel);
		con.add(jpSouth,"South");
		
		JPanel jpnNorth = new JPanel();
		JPanel jpnCenter = new JPanel();
		jpNorth.setLayout(new BorderLayout());
		jpNorth.add(jpnNorth,"North");
		jpNorth.add(jpnCenter,"Center");
		jpnNorth.setLayout(new FlowLayout());
		jpnCenter.setLayout(new FlowLayout());
		jpnNorth.add(jlbwel);
		jpnCenter.add(jlbInTime);
		
		JPanel jpcNorth = new JPanel();
		JPanel jpcCenter = new JPanel();
		jpCenter.setLayout(new BorderLayout());
		jpCenter.add(jpcNorth,"North");
		jpCenter.add(jpcCenter,"Center");
		
		jpcNorth.setLayout(new FlowLayout());
		JLabel jlbOutTime = new JLabel("出场时间:");
		jpcNorth.add(jlbOutTime);
		jpcNorth.add(jtfYear);
		jpcNorth.add(jlbYear);
		jpcNorth.add(jtfMonth);
		jpcNorth.add(jlbMonth);
		jpcNorth.add(jtfDay);
		jpcNorth.add(jlbDay);
		jpcNorth.add(jtfHour);
		jpcNorth.add(jlbHour);
		jpcNorth.add(jtfMinute);
		jpcNorth.add(jlbMinute);
		jpcNorth.add(jtfSecond);
		jpcNorth.add(jlbSecond);
		
		//����
		jbnconfirm.addActionListener(this);
		jbncancel.addActionListener(this);
		
	}
	
	public void actionPerformed (ActionEvent e) {
		if(e.getSource()==jbnconfirm) {
			String Year = jtfYear.getText();
			String Month = jtfMonth.getText();
			String Day = jtfDay.getText();
			String Hour = jtfHour.getText();
			String Minute = jtfMinute.getText();
			String Second = jtfSecond.getText();
			
			int year = Integer.parseInt(Year);
			int month = Integer.parseInt(Month);
			int day = Integer.parseInt(Day);
			int hour = Integer.parseInt(Hour);
			int minute = Integer.parseInt(Minute);
			int second = Integer.parseInt(Second);
			
			Pattern pYear = Pattern.compile("^[0-9]{4}$");
			Pattern pMonth = Pattern.compile("^[0-9]{2}$");
			Pattern pDay = Pattern.compile("^[0-9]{2}$");
			Pattern pHour = Pattern.compile("^[0-9]{2}$");
			Pattern pMinute = Pattern.compile("^[0-9]{2}$");
			Pattern pSecond = Pattern.compile("^[0-9]{2}$");
			Matcher mYear = pYear.matcher(Year);
			Matcher mMonth = pMonth.matcher(Month);
			Matcher mDay = pDay.matcher(Day);
			Matcher mHour = pHour.matcher(Hour);
			Matcher mMinute = pMinute.matcher(Minute);
			Matcher mSecond = pSecond.matcher(Second);
			
			if(	mYear.matches()&&mMonth.matches()&&mDay.matches()
				&&mHour.matches()&&mMinute.matches()&&mSecond.matches()) {
				if(	month>=1&&month<=12&&day>=1&&day<=31
					&&hour>=0&&hour<=24&&minute>=0&&minute<=60&&second>=0&&second<=60) {
					String str = Year+"-"+Month+"-"+Day+" "+Hour+":"+Minute+":"+Second;

					// ����
					Car car = new Car();
					car.setOutTime(str);
					car.setCarID(park.GetCarID(parki));
					car = this.park.CarOut(parki, str);
					MyJFrame mjf = new MyJFrame(park);
					CarOutSuccessJFrame cisijf = new CarOutSuccessJFrame(car,park.getEmptyNum());
					dispose();
				}
			}
			else {
				CarInFailureJFrame cifjf = new CarInFailureJFrame();
				this.jtfYear.setText("");
				this.jtfMonth.setText("");
				this.jtfDay.setText("");
				this.jtfHour.setText("");
				this.jtfMinute.setText("");
				this.jtfSecond.setText("");
			}
		}
		if(e.getSource()==jbncancel) {
			MyJFrame mjf = new MyJFrame(park);
			dispose();
		}
	}
	
}

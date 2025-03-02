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

public class CarInJFrame extends JFrame implements ActionListener{
	Park park;
	int parki;
	JLabel jlbwel = new JLabel("欢迎来到停车场");
	JLabel jlbcarID = new JLabel("车牌号码");
	JLabel jlbInTime = new JLabel("入场时间:");
	JLabel jlbYear = new JLabel("年");
	JLabel jlbMonth = new JLabel("月");
	JLabel jlbDay = new JLabel("日");
	JLabel jlbHour = new JLabel("时");
	JLabel jlbMinute = new JLabel("分");
	JLabel jlbSecond = new JLabel("秒");
	
	JTextField jtfcarID = new JTextField(15);
	JTextField jtfYear = new JTextField(4);
	JTextField jtfMonth = new JTextField(2);
	JTextField jtfDay = new JTextField(2);
	JTextField jtfHour = new JTextField(2);
	JTextField jtfMinute = new JTextField(2);
	JTextField jtfSecond = new JTextField(2);
	
	JButton jbnconfirm = new JButton("确认入场");
	JButton jbncancel = new JButton("取消入场");
	
	
	public CarInJFrame (Park p,int i) {
		super("车辆入场界面");
		this.park=p;
		this.parki=i;
		init();
		setVisible(true); 
		this.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
	}

	public void init() {
		Container  con=this.getContentPane();
		this.setSize(400,180);
		Dimension dim = new Dimension(400,50);
		JPanel jpNorth = new JPanel();
		JPanel jpSouth = new JPanel();
		JPanel jpCenter = new JPanel();
		JPanel jpcNorth = new JPanel();
		JPanel jpcCenter = new JPanel();
		
		con.setLayout(new BorderLayout());
		jpNorth.setLayout(new FlowLayout());
		//jpNorth.setPreferredSize(dim);
		jpNorth.add(jlbwel);
		con.add(jpNorth,"North");
		
		jpSouth.setPreferredSize(dim);
		jpSouth.setLayout(new FlowLayout());
		jpSouth.add(jbnconfirm);
		jpSouth.add(jbncancel);
		con.add(jpSouth,"South");
		
		//jpCenter.setPreferredSize(new Dimension(400,100));
		jpCenter.setLayout(new BorderLayout());
		jpcNorth.setLayout(new FlowLayout());
		jpcCenter.setLayout(new FlowLayout());
		jpcNorth.add(jlbcarID);
		jpcNorth.add(jtfcarID);
		jpcCenter.add(jlbInTime);
		jpcCenter.add(jtfYear);
		jpcCenter.add(jlbYear);
		jpcCenter.add(jtfMonth);
		jpcCenter.add(jlbMonth);
		jpcCenter.add(jtfDay);
		jpcCenter.add(jlbDay);
		jpcCenter.add(jtfHour);
		jpcCenter.add(jlbHour);
		jpcCenter.add(jtfMinute);
		jpcCenter.add(jlbMinute);
		jpcCenter.add(jtfSecond);
		jpcCenter.add(jlbSecond);
		jpCenter.add(jpcNorth,"North");
		jpCenter.add(jpcCenter,"Center");
		con.add(jpCenter,"Center");
		
		jbnconfirm.addActionListener(this);
		jbncancel.addActionListener(this);
	}
	
	public void actionPerformed(ActionEvent e) {
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
					Car car = new Car();
					car.setInTime(str);
					car.setCarID(jtfcarID.getText());
					this.park.CarIn(parki, car);
					MyJFrame mjf = new MyJFrame(park);
					CarInSuccessJFrame cisjf = new CarInSuccessJFrame(car.getCarID(),car.getInTime(),parki,park.getEmptyNum());
					
					dispose();
				}
			}
			else {
				CarInFailureJFrame cifjf = new CarInFailureJFrame();
				
                                                                     //补充
			}
			
		}
		if (e.getSource()==jbncancel) {
			MyJFrame mjf = new MyJFrame(park);
			dispose();
		}
	}
}

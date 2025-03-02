package week9_1;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class CarInSuccessJFrame extends JFrame implements ActionListener{
	
	JButton jbnconfirm = new JButton("确认");
	
	public CarInSuccessJFrame(String id,String intime,int parki,int emptynum) {
		super("停车成功界面");	
		init(id,intime,parki,emptynum);
		setVisible(true); 
		this.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
	}
	
	public void init(String id,String intime,int parki,int emptynum) {
		Container  con=this.getContentPane();
		this.setSize(500,200);
		
		JPanel jpNorth = new JPanel();
		JPanel jpCenter = new JPanel();
		JPanel jpcNorth = new JPanel();
		JPanel jpcCenter = new JPanel();
		
		con.setLayout(new BorderLayout());
		con.add(jpNorth,"North");
		con.add(jpCenter,"Center");
		
		JPanel jplbn1 = new JPanel();
		JPanel jplbn2 = new JPanel();
		JLabel lbn1 = new JLabel("车牌号为"+id+"的车于"+intime);
		JLabel lbn2 = new JLabel("停入"+parki+"号车位(还有"+emptynum+"个车位)");
		jplbn1.setLayout(new FlowLayout());
		jplbn2.setLayout(new FlowLayout());
		jplbn1.add(lbn1);
		jplbn2.add(lbn2);
		jpNorth.setLayout(new BorderLayout());
		jpNorth.add(jplbn1,"North");
		jpNorth.add(jplbn2,"Center");
		
		jpCenter.setLayout(new BorderLayout());
		jpCenter.add(jpcNorth,"North");
		jpCenter.add(jpcCenter,"Center");
		
		JPanel jplbc1 = new JPanel();
		JPanel jplbc2 = new JPanel();
		JLabel lbc1 = new JLabel("停车单价：上午8:00-下午20:00 8元/小时");
		JLabel lbc2 = new JLabel("下午20:00后 1元/小时");
		jplbc1.setLayout(new FlowLayout());
		jplbc2.setLayout(new FlowLayout());
		jplbc1.add(lbc1);
		jplbc2.add(lbc2);
		jpcNorth.setLayout(new BorderLayout());
		jpcNorth.add(jplbc1,"North");
		jpcNorth.add(jplbc2,"Center");
		
		jpcCenter.setLayout(new FlowLayout());
		jpcCenter.add(jbnconfirm);
		
		jbnconfirm.addActionListener(this);
	}
	
	public void actionPerformed (ActionEvent e) {
		if(e.getSource()==jbnconfirm) {
//			System.out.println("入场成功");
			dispose();
		}
	}

}

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

public class CarOutSuccessJFrame extends JFrame implements ActionListener{

	JButton jbnconfirm = new JButton("确认");
	
	public CarOutSuccessJFrame(Car c,int emptynum) {
        //补充
		super("出库成功界面");
		init(c,emptynum);
		setVisible(true);
		this.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
	}
	public void init(Car c,int emptynum) {
		String carID = c.getCarID();
		JLabel jlb1 = new JLabel("车牌号为"+c.getCarID()+"的车于"+c.getOutTime()+"成功出场");
		JLabel jlb2 = new JLabel("费用为"+c.getFare());
		JLabel jlb3 = new JLabel("剩余车位:"+emptynum+"个");
		
		Container  con=this.getContentPane();
		this.setSize(500,180);
		
		JPanel jpNorth = new JPanel();
		JPanel jpCenter = new JPanel();
		con.setLayout(new BorderLayout());
		con.add(jpNorth,"North");
		con.add(jpCenter,"Center");
		
		JPanel jpnNorth = new JPanel();
		JPanel jpnCenter = new JPanel();
		jpNorth.setLayout(new BorderLayout());
		jpNorth.add(jpnNorth,"North");
		jpNorth.add(jpnCenter,"Center");
		
		jpnNorth.setLayout(new FlowLayout());
		jpnNorth.add(jlb1);
		
		jpnCenter.setLayout(new FlowLayout());
		jpnCenter.add(jlb2);
		
		JPanel jpcNorth = new JPanel();
		JPanel jpcCenter = new JPanel();
		jpCenter.setLayout(new BorderLayout());
		jpCenter.add(jpcNorth,"North");
		jpCenter.add(jpcCenter,"Center");
		
		jpcNorth.setLayout(new FlowLayout());
		jpcNorth.add(jlb3);
		
		jpcCenter.setLayout(new FlowLayout());
		jpcCenter.add(jbnconfirm);
		
		jbnconfirm.addActionListener(this);
		
	}
	public void actionPerformed (ActionEvent e) {
		if (e.getSource()==jbnconfirm) {
			dispose();
		}
		
	}
}

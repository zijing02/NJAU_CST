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

public class CarInFailureJFrame extends JFrame implements ActionListener{

	JButton jbnconfirm = new JButton("确认");
	
	public CarInFailureJFrame() {
		super("错误界面");
		init();
		setVisible(true); 
		this.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
	}
	
	public void init() {
		Container  con=this.getContentPane();
		this.setSize(200,120);
		
		JPanel jpNorth = new JPanel();
		JPanel jpCenter = new JPanel();
		
		con.setLayout(new BorderLayout());
		con.add(jpNorth,"North");
		con.add(jpCenter,"Center");
		
		JLabel jlb = new JLabel("时间格式输入错误");
		jpNorth.setLayout(new FlowLayout());
		jpNorth.add(jlb);
		
		jpCenter.setLayout(new FlowLayout());
		jpCenter.add(jbnconfirm);
		
		jbnconfirm.addActionListener(this);
	}
	
	public void actionPerformed (ActionEvent e) {
		if(e.getSource()==jbnconfirm) {
			dispose();
		}
	}
}

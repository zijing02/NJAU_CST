package week9_1;

import java.awt.Container;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;

public class MyJFrame extends JFrame implements ActionListener{
	Park park;
	JPanel jp1 = new JPanel(); 			//显示停车位
	JButton jbpark[];
	
	public MyJFrame(Park p){
		super("停车场");
		park = p;
		jbpark = new JButton[park.GetCapacity()];
		init();
		setVisible(true); 
    	setDefaultCloseOperation(EXIT_ON_CLOSE);
	}
	public void init(){
		int capacity = park.GetCapacity();
		
		initJbpark();
		
		Container  con=this.getContentPane();
		this.setSize(800,600);
		
		double x = Math.sqrt(capacity);
		int y = (int)x;
		if(x>y)
			y++;
		con.setLayout(new GridLayout((int)x,y));
		for(int i=0;i<capacity;i++){
			con.add(jbpark[i]);
		}
		
	}
	public void initJbpark(){
		boolean e[] = park.GetEmpty();
		for(int i=0;i<park.GetCapacity();i++){
			if(e[i])
				jbpark[i] = new JButton("无车");
			else{
				jbpark[i] = new JButton("有车");
			}
			jbpark[i].addActionListener(this);
		}
	}
	public void actionPerformed(ActionEvent e){
		int capacity = park.GetCapacity();
		int i=0;
		for(i=0;i<capacity;i++){
			if(e.getSource()==jbpark[i])
				break;
		}
		if(i<capacity){
			if(park.IsEmpty(i)) {
				CarInJFrame cif = new CarInJFrame(park,i);
				dispose();
			}
			else {
				CarOutJFrame cof = new CarOutJFrame(park,i);
				dispose();
			}
			return;
		}
	}
}

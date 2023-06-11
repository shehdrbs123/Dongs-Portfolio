package graphics.study;

import graphics.EnglishStudyMain;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.event.KeyListener;
import java.awt.event.KeyEvent;
import java.io.FileNotFoundException;
import java.util.Calendar;
import javax.swing.*;

public class StudyMainPane extends JDialog{
	private JButton look, write, cancel;
	private volatile static StudyMainPane instance;
	private Calendar date;
	private StudyMainPane(){
		setView();
		this.date=date;
	}
	private void setView(){
		setLayout(new BoxLayout(this.getContentPane(), BoxLayout.Y_AXIS));
		look = new JButton("����");
		write = new JButton("����");
		cancel = new JButton("���");
		
		SMPHandler hand = new SMPHandler();
		look.addActionListener(hand);
		write.addActionListener(hand);
		cancel.addActionListener(hand);
		look.addKeyListener(hand);
		write.addKeyListener(hand);
		cancel.addKeyListener(hand);
		
		JPanel firstPane = new JPanel();
		firstPane.setAlignmentX(JPanel.CENTER_ALIGNMENT);
		firstPane.add(new JLabel("���� ����� �����ϼ���"));
		
		JPanel selectPane = new JPanel();
		selectPane.add(look);
		selectPane.add(write);
		selectPane.add(cancel);
		
		add(firstPane);
		add(selectPane);
		pack();
		EnglishStudyMain.setSubInit(this);
		System.out.println("System Log : StudyMainPane is View Setting is completed");
	}
	public void firstInit(Calendar date){
		System.out.println("System Log : StudyMainPane is initialized");
		this.date = date;
		setVisible(true);
	}
	public static StudyMainPane getInstance(){
		if(instance == null){
			synchronized(StudyMainPane.class){
				if(instance == null) instance = new StudyMainPane();
				System.out.println("System Log : StudyMainPane instance is created");
			}
		}
		return instance;
	}
	class SMPHandler extends WindowAdapter implements ActionListener, KeyListener{
		public void actionPerformed(ActionEvent e){
			String select = e.getActionCommand();
			try{
				if(select.equals("����")){
					BlinkStudyPane.getInstance().firstInit(date);
				}else if(select.equals("����")){
					WriteStudyPane.getInstance().firstInit(date);
				}else if(select.equals("���")){
					setVisible(false);//StudyMainPane�� �޼ҵ���
				}
			}catch(FileNotFoundException e1){
				JOptionPane.showMessageDialog(StudyMainPane.instance, "�ش� ��¥�� �ܾ ��ϵ��� �ʾҽ��ϴ�");
			}catch(Exception e1){
				e1.printStackTrace();
			}
		}
		public void keyPressed(KeyEvent e){
			if(e.getKeyCode() == KeyEvent.VK_LEFT){
				leftFocus();
			}else if(e.getKeyCode() == KeyEvent.VK_RIGHT){
				rightFocus();
			}else if(e.getKeyCode() == KeyEvent.VK_ENTER){
				JButton btn = whoIsFocused();
				btn.doClick();
			}else if(e.getKeyCode() == KeyEvent.VK_ESCAPE){
				setVisible(false);//StudyMainPane�� �޼ҵ���
			}
		}
		public void keyReleased(KeyEvent e){}
		public void keyTyped(KeyEvent e){}
		public void windowClosing(WindowEvent e){
		}
		private JButton whoIsFocused(){
			if(look.isFocusOwner()){
				return look;
			}else if(write.isFocusOwner()){
				return write;
			}else if(cancel.isFocusOwner()){
				return cancel;
			}
			return null;
		}
		private void leftFocus(){
			if(look.isFocusOwner()){
				cancel.requestFocus();
			}else if(write.isFocusOwner()){
				look.requestFocus();
			}else if(cancel.isFocusOwner()){
				write.requestFocus();
			}
		}
		private void rightFocus(){
			if(look.isFocusOwner()){
				write.requestFocus();
			}else if(write.isFocusOwner()){
				cancel.requestFocus();
			}else if(cancel.isFocusOwner()){
				look.requestFocus();
			}
		}
	}
}
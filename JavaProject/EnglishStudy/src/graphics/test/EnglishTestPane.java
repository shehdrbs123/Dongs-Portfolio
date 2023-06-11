package graphics.test;

import graphics.EnglishStudyMain;
import graphics.study.SelectFileListPane;

import java.awt.FlowLayout;

import javax.swing.*;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;


public class EnglishTestPane extends JDialog{
	private static volatile EnglishTestPane instance;
	private EnglishTestPane() {
		setView();
		TestPanel.getInstance();
	}

	public static EnglishTestPane getInstance() {
		if (instance == null) {
			synchronized (EnglishTestPane.class) {
				if (instance == null) {
					instance = new EnglishTestPane();
					System.out.println("System Log : EnglishTestPane instance is created");
				}
			}
		}
		return instance;
	}
	public void firstInit(){
		System.out.println("System Log : EnglishTestPane is initialized");
		setVisible(true);
	}
	private void setView(){
		JPanel first, middle;
		
		first =  new JPanel();
		first.setLayout(new FlowLayout(FlowLayout.CENTER));
		first.setAlignmentX(JPanel.CENTER_ALIGNMENT);
		first.add(new JLabel("� ������ ���ðڽ��ϱ�?"));
		
		ETPHandler hand = new ETPHandler(this);
		middle = new JPanel();
		middle.setLayout(new FlowLayout(FlowLayout.CENTER));
		middle.setAlignmentX(JPanel.CENTER_ALIGNMENT);
		JButton[] choice = new JButton[3];
		choice[0] = new JButton("���ǰ��");
		choice[1] = new JButton("�������");
		choice[2] = new JButton("���");
		for(JButton i : choice){
			i.addActionListener(hand);
			middle.add(i);
		}
		add(first);
		add(middle);
		
		setLayout(new BoxLayout(this.getContentPane(), BoxLayout.Y_AXIS));
		EnglishStudyMain.setSubInit(this);
		System.out.println("System Log : EnglishTestPane View setting is completed");
	
	}
	
	private void mockTest(){
		TestPanel.getInstance().firstInit(true);
	}
	private void test(){
		TestPanel.getInstance().firstInit(false);
	}
	class ETPHandler implements ActionListener{
		private EnglishTestPane target;
		public ETPHandler(EnglishTestPane a){
			target = a;
		}
		public void actionPerformed(ActionEvent e){
			String com = e.getActionCommand();
			if(com.equals("���ǰ��")){
				setVisible(false);
				target.mockTest();
			}else if(com.equals("�������")){
				setVisible(false);
				target.test();
			}else if(com.equals("���")){
				setVisible(false);
			}
		}
	}
}

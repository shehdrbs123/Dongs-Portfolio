package graphics.study;

import graphics.EnglishStudyMain;

import javax.swing.*;

import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.*;
import java.io.FileNotFoundException;
import java.util.Calendar;

import bin.StudyManager;


public class BlinkStudyPane extends JDialog implements Runnable{
	private int numberOfWords, presentNum;
	private JButton goon, stop;
	private JLabel number, english, korean;
	private volatile static BlinkStudyPane instance;
	private Calendar date;
	private StudyManager manager;
	private Thread thread=null;
	
	private BlinkStudyPane(){
		setView();
		manager = StudyManager.getInstance();
	}
	
	public static BlinkStudyPane getInstance(){
		if(instance == null){
			synchronized(BlinkStudyPane.class){
				if(instance == null){
					instance = new BlinkStudyPane();
					System.out.println("System Log : BlinkStudyPane is created");
				}
			}
		}
		return instance;
	}
	private void setView(){
		JPanel main = new JPanel();
		main.setLayout(new BoxLayout(main,BoxLayout.Y_AXIS));
		main.setBorder(BorderFactory.createEmptyBorder(0, 5, 0, 5));
		JPanel first, middleRap, bottom;
		JPanel[] middle = new JPanel[2];
		
		first = new JPanel();
		first.setAlignmentX(JPanel.CENTER_ALIGNMENT);
		first.setLayout(new FlowLayout(FlowLayout.TRAILING));
		numberOfWords = 0;
		presentNum = 0;
		number = new JLabel(" ");
		first.add(number);
		
		middleRap = new JPanel();
		middleRap.setBorder(BorderFactory.createEtchedBorder());
		middleRap.setAlignmentX(JPanel.CENTER_ALIGNMENT);
		middleRap.setLayout(new GridLayout(1,0));
		
		middle[0] = new JPanel();
		english = new JLabel(" ");
		english.setAlignmentX(JLabel.CENTER_ALIGNMENT);
		middle[0].add(english);
		
		middle[1] = new JPanel();
		korean = new JLabel(" ");
		korean.setAlignmentX(JLabel.CENTER_ALIGNMENT);
		middle[1].add(korean);
		
		middleRap.add(middle[0]);
		middleRap.add(middle[1]);
		
		bottom = new JPanel();
		bottom.setAlignmentX(JPanel.CENTER_ALIGNMENT);
		bottom.setLayout(new FlowLayout(FlowLayout.TRAILING,5,8));
		goon = new JButton("계속");
		stop = new JButton("그만");
		BSPHandler hand = new BSPHandler();
		goon.addActionListener(hand);
		goon.setEnabled(false);
		stop.addActionListener(hand);
		goon.addKeyListener(hand);
		stop.addKeyListener(hand);
		bottom.add(goon);
		bottom.add(stop);
		goon.requestFocus();
		
		main.add(first);
		main.add(middleRap);
		main.add(bottom);
		add(main);
		EnglishStudyMain.setSubInit(this);
		setSize(getWidth()+80,getHeight()-5);
		addWindowListener(hand);
		System.out.println("System Log : BlinkStudyPane View setting is completed");
	}
	public void firstInit(Calendar date)throws Exception{
		if(thread == null){
			this.date = date;
			reset();
			thread = new Thread(this);
			thread.start();
			System.out.println("System Log : BlinkStudyPane instance is initialized");
			setVisible(true);
		}
	}
	public void reset() throws Exception{
		StudyManager.getInstance().startStudy(date);
		english.setText(" ");
		korean.setText(" ");
		number.setText("단어 수     ");
		goon.setEnabled(false);
	}
	
	public void run(){
		StringBuffer[] words;
		numberOfWords = manager.getLength();
		presentNum = 0;
		number.setText("단어 수 " + presentNum + " / " + numberOfWords);
		while(!Thread.currentThread().interrupted()){
			try{
				presentNum++;
				words= manager.nextWords();
				if(words == null){break;}
				Thread.sleep(800);
				number.setText("단어 수 " + presentNum + "/" + numberOfWords);
				korean.setText(" ");
				english.setText(words[0].toString());
				Thread.sleep(1000);
				korean.setText(words[1].toString());
			}catch(NullPointerException e){
				try{
					Thread.currentThread().interrupt();
				}catch(NullPointerException e1){}
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				try{
					Thread.currentThread().interrupt();
				}catch(NullPointerException e1){
				}
			}
		}
		goon.setEnabled(true);
		System.out.println("System Log : Thread is closed");
		thread = null;
		return;
	}
	class BSPHandler extends KeyAdapter implements ActionListener, WindowListener{
		public void actionPerformed(ActionEvent e){
			String a = e.getActionCommand();
			if(a.equals("계속")){
				try {
					if(thread == null){
						manager.repeat();
						thread = new Thread(instance);
						thread.start();							
						goon.setEnabled(false);
					}else{
						return;
					}
				} catch (Exception e1) {
						// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}else if(a.equals("그만")){
				if(thread != null && thread.isAlive()){
					thread.interrupt();
					thread = null;
				}
				setVisible(false);
				manager.stopStudy();
			}
		}
		public void KeyPressed(KeyEvent e){
			
		}
		@Override
		public void windowActivated(WindowEvent arg0) {
			// TODO Auto-generated method stub
			
		}
		@Override
		public void windowClosed(WindowEvent arg0) {
			// TODO Auto-generated method stub
			
		}
		@Override
		public void windowClosing(WindowEvent arg0) {
			// TODO Auto-generated method stub
			if(thread !=null){
				thread.interrupt();
				thread = null;
			}
			manager.stopStudy();
		}
		@Override
		public void windowDeactivated(WindowEvent arg0) {
			// TODO Auto-generated method stub
		}
		@Override
		public void windowDeiconified(WindowEvent arg0) {
			// TODO Auto-generated method stub
		}
		@Override
		public void windowIconified(WindowEvent arg0) {
			// TODO Auto-generated method stub
			
		}
		@Override
		public void windowOpened(WindowEvent arg0) {
			// TODO Auto-generated method stub
			
		}
	}
}
package graphics.study;

import graphics.EnglishStudyMain;

import javax.swing.*;

import java.awt.event.*;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.util.Calendar;
import java.util.LinkedList;

import bin.StudyManager;

public class WriteStudyPane extends JDialog {
	private JLabel number, lEnglish, lKorean;
	private JTextField wEnglish, wKorean;
	private JButton goon, stop;
	private int numberOfWords, presentNum;
	private volatile static WriteStudyPane instance;
	private StudyManager manager;

	private WriteStudyPane(){
		setView();
		manager= StudyManager.getInstance();
	}
	public static WriteStudyPane getInstance(){
		if(instance == null){
			synchronized(WriteStudyPane.class){
				if(instance == null){
					instance = new WriteStudyPane();
					System.out.println("System Log : WriteStudyPane instance is created");
				}
			}
		}
		return instance;
	}

	public void setView() {
		JPanel main = new JPanel();
		main.setLayout(new BoxLayout(main, BoxLayout.Y_AXIS));
		main.setBorder(BorderFactory.createEmptyBorder(0, 5, 0, 5));

		JPanel first, bottom;
		JPanel[] middle = new JPanel[4];
		setLayout(new BoxLayout(this.getContentPane(), BoxLayout.Y_AXIS));

		WSPHandler hand = new WSPHandler();

		first = new JPanel();
		first.setAlignmentX(JPanel.LEFT_ALIGNMENT);
		first.setLayout(new FlowLayout(FlowLayout.TRAILING));
		number = new JLabel("단어 수 : " + presentNum + " / " + numberOfWords);
		first.add(number);

		JPanel middleRap = new JPanel();
		middleRap.setLayout(new GridLayout(2, 2));
		middleRap.setBorder(BorderFactory.createEtchedBorder());

		middle[0] = new JPanel();
		lEnglish = new JLabel(" ");
		middle[0].setAlignmentX(JPanel.CENTER_ALIGNMENT);
		middle[0].add(lEnglish);

		middle[1] = new JPanel();
		wEnglish = new JTextField(10);
		wEnglish.addKeyListener(hand);

		middle[1].setAlignmentX(JPanel.CENTER_ALIGNMENT);
		middle[1].add(wEnglish);

		middle[2] = new JPanel();
		lKorean = new JLabel(" ");
		middle[2].setAlignmentX(JPanel.CENTER_ALIGNMENT);
		middle[2].add(lKorean);

		middle[3] = new JPanel();
		wKorean = new JTextField(10);
		wKorean.addKeyListener(hand);
		middle[3].setAlignmentX(JPanel.CENTER_ALIGNMENT);
		middle[3].add(wKorean);

		for (JPanel i : middle) {
			middleRap.add(i);
		}

		bottom = new JPanel();
		bottom.setAlignmentX(JPanel.CENTER_ALIGNMENT);
		bottom.setLayout(new FlowLayout(FlowLayout.TRAILING));
		goon = new JButton("계속");
		stop = new JButton("그만");
		goon.addActionListener(hand);
		stop.addActionListener(hand);
		bottom.add(goon);
		bottom.add(stop);

		main.add(first);
		main.add(middleRap);
		main.add(bottom);
		add(main);
		pack();
		EnglishStudyMain.setSubInit(this);
		addWindowListener(hand);
		System.out.println("System Log : WriteStudyPane Setting is completed");
	}

	public void firstInit(Calendar date) throws Exception {
		reset();
		manager.startStudy(date);
		numberOfWords = manager.getLength();
		System.out.println("System Log : WriteStudyPane is initialized");
		update();
	}

	public void reset() {
		presentNum = 0;
		number.setText("단어 수 0/0");
		lEnglish.setText(" ");
		lKorean.setText(" ");
		wEnglish.setText("");
		wKorean.setText("");
	}

	public void update() {
		StringBuffer[] words;
		wEnglish.getText();
		wKorean.getText();
		wEnglish.setText("");
		wKorean.setText("");
		wEnglish.requestFocus();
		words = manager.nextWords();
		if (words == null) {
			return;
		}
		presentNum++;
		lEnglish.setText(words[0].toString());
		lKorean.setText(words[1].toString());
		number.setText("단어 수 " + presentNum + "/" + numberOfWords);
		setVisible(true);
	}

	public boolean isEnd() {
		if (numberOfWords == presentNum)
			return true;
		return false;
	}

	class WSPHandler extends KeyAdapter implements ActionListener,
			WindowListener {
		public void actionPerformed(ActionEvent e) {
			Object a = e.getActionCommand();
			if (a.equals("계속")) {
				if (isEnd()) {
					setVisible(false);
				} else {
					wEnglish.getText();
					wKorean.getText();
					if(wEnglish.getText().equals("")){
						JOptionPane.showMessageDialog(instance,"단어를 입력해주세요");
						wEnglish.requestFocus();
						return;
					}
					if(!wEnglish.getText().equals(lEnglish.getText())){
						JOptionPane.showMessageDialog(instance, "단어 철자가 틀렸습니다");
						wEnglish.requestFocus();
						return;
					}
					if(wKorean.getText().equals("")){
						JOptionPane.showMessageDialog(instance,"뜻를 입력해주세요");
						wKorean.requestFocus();
						return;
					}
					if(!wKorean.getText().equals((lKorean.getText().trim()))){
						JOptionPane.showMessageDialog(instance, "뜻 철자가 틀렸습니다.");
						wKorean.requestFocus();
						return;
					}
					update();
				}
			} else if (a.equals("그만")) {
				setVisible(false);
			}
		}

		public void keyPressed(KeyEvent e) {
			switch (e.getKeyCode()) {
				case KeyEvent.VK_ENTER:
					if(wEnglish.hasFocus()){
						wKorean.requestFocus();
					}else if(wKorean.hasFocus()){
						goon.doClick();
					}
					break;
					

			}
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
		}

		@Override
		public void windowDeactivated(WindowEvent arg0) {
			// TODO Auto-generated method stub
			if (!instance.isVisible()) {
				manager.stopStudy();
				reset();
			}
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

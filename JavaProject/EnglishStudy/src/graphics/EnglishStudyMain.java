package graphics;

import javax.swing.*;

import bin.StudyManager;
import bin.TestManager;
import graphics.registry.*;
import graphics.study.*;
import graphics.test.EnglishTestPane;

import java.awt.event.*;
import java.awt.*;
import java.util.Calendar;
import java.util.Date;

public class EnglishStudyMain extends JFrame {
	public JButton[] button;
	private ESMHandler handle;
	static Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
	public EnglishStudyMain() {
		super();
		setMainWindowInit();
		StudyManager.getInstance();
		TestManager.getInstance();
		WordsRegistryPane.getInstance();
		StudyMainPane.getInstance();
		BlinkStudyPane.getInstance();
		WriteStudyPane.getInstance();
		SelectFileListPane.getInstance();
		EnglishTestPane.getInstance();
		System.out.println("System Log : System is initialized");
	}

	public void setMainWindowInit() {
		System.out.println("System Log : System is initializing");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(new BoxLayout(this.getContentPane(), BoxLayout.Y_AXIS));
		button = new JButton[5];
		button[0] = new JButton("오늘의단어 등록");
		button[1] = new JButton("오늘의단어 복습");
		button[2] = new JButton("어제의단어 복습");
		button[3] = new JButton("지난날단어 복습");
		button[4] = new JButton("영어단어 테스트");
		JLabel title = new JLabel("영어공부");
		title.setAlignmentX(CENTER_ALIGNMENT);
		add(title);
		// addFocusListener();
		handle = new ESMHandler(button);

		for (JButton i : button) {
			i.setAlignmentX(CENTER_ALIGNMENT);
			i.addMouseListener(handle);
			add(i);
		}
		pack();
		setLocation((int) screenSize.getWidth() / 2 - getWidth() / 2,
				(int) screenSize.getHeight() / 2 - getHeight() / 2 - 50);
		setResizable(false);
		setVisible(true);
	}

	public static void setSubInit(JDialog frm) {
		frm.pack();
		locateCenter(frm);
		frm.setModal(true);
		frm.setResizable(false);
	}
	public static void locateCenter(JDialog frm){
		frm.setLocation((int) (screenSize.getWidth() / 2 - frm.getWidth() / 2),
				(int) (screenSize.getHeight() / 2 - frm.getHeight() / 2 - 50));
	}
}

class ESMHandler extends MouseAdapter {
	private JButton[] btn;
	private JFrame mf;

	ESMHandler(JButton[] btn) {
		this.btn = btn;
	}

	public void mousePressed(MouseEvent e) {
		Object o = e.getSource();
		int act = 0;
		for (; act < btn.length; act++) {
			if (btn[act] == o) {
				break;
			}
		}
		answer(act);
	}

	public void answer(int act) {
		final int REGISTRY = 0;
		final int STUDY = 1;
		final int REVIEW = 2;
		final int ANREVIEW = 3;
		final int REPORT = 4;
		Calendar date = Calendar.getInstance();
		switch (act) {
			case REGISTRY:
				WordsRegistryPane.getInstance().firstInit();
				break;
			case STUDY:
				StudyMainPane.getInstance().firstInit(date);
				break;
			case REVIEW:
				int day = date.get(Calendar.DAY_OF_MONTH);
				date.set(Calendar.DAY_OF_MONTH, day - 1);
				StudyMainPane.getInstance().firstInit(date);
				break;
			case ANREVIEW:
				try{
					SelectFileListPane.getInstance().firstInit(false);
				}catch(NullPointerException e){
					e.printStackTrace();
				}
				break;
			case REPORT:
				EnglishTestPane.getInstance().firstInit();
				break;
		}
	}
}

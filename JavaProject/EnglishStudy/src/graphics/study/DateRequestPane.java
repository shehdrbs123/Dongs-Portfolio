package graphics.study;

import graphics.EnglishStudyMain;

import javax.swing.*;
import javax.swing.border.*;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.KeyListener;
import java.util.Calendar;

public class DateRequestPane extends JDialog {
	public static volatile DateRequestPane instance;
	private final int FIRST_YEAR = 2010;
	JComboBox<String> year = new JComboBox<String>();
	JComboBox<String> month = new JComboBox<String>();
	JComboBox<String> day = new JComboBox<String>();
	JButton confirm, cancel;
	Calendar date = Calendar.getInstance();

	private DateRequestPane() {
		setView();
	}

	public static DateRequestPane getInstance() {
		if (instance == null) {
			synchronized (DateRequestPane.class) {
				if (instance == null) {
					instance = new DateRequestPane();
				}
			}
		}
		return instance;
	}

	public void setView() {


		int yearNum = Calendar.getInstance().get(Calendar.YEAR);

		for (int i = yearNum; i >=FIRST_YEAR ; i--) {
			year.addItem(String.valueOf(i));
		}

		for (int i = 1; i <= 12; i++) {
			month.addItem(String.valueOf(i));
		}

		for (int i = 1; i <= 31; i++) {
			day.addItem(String.valueOf(i));
		}
		dialogInit();
		setLayout(new BoxLayout(this.getContentPane(), BoxLayout.Y_AXIS));
		JPanel first, middle, bottom;
		DRPHandler hand = new DRPHandler();

		first = new JPanel();
		first.setAlignmentX(JPanel.CENTER_ALIGNMENT);
		first.add(new JLabel("공부한 날짜는?"));

		middle = new JPanel();
		middle.setAlignmentX(JPanel.CENTER_ALIGNMENT);
		EmptyBorder b = new EmptyBorder(5,10,5,10);
		middle.setBorder(b);
		middle.add(year);
		middle.add(new JLabel("년"));
		middle.add(month);
		middle.add(new JLabel("월"));
		middle.add(day);
		middle.add(new JLabel("일"));

		bottom = new JPanel();
		bottom.setAlignmentX(JPanel.CENTER_ALIGNMENT);
		confirm = new JButton("확인");
		cancel = new JButton("취소");
		confirm.addActionListener(hand);
		cancel.addActionListener(hand);
		bottom.setLayout(new FlowLayout(FlowLayout.TRAILING));
		bottom.add(confirm);
		bottom.add(cancel);

		add(first);
		add(middle);
		add(bottom);
		EnglishStudyMain.setSubInit(this);
	}
	public Calendar firstInit(){
		System.out.println("System Log : DateRequestPane is created");
		setVisible(true);
		instance = null;
		return date;
	}

	class DRPHandler extends WindowAdapter implements KeyListener,
			ActionListener {

		@Override
		public void keyPressed(KeyEvent arg0) {
			// TODO Auto-generated method stub

		}

		@Override
		public void keyReleased(KeyEvent arg0) {
			// TODO Auto-generated method stub

		}

		@Override
		public void keyTyped(KeyEvent arg0) {
			// TODO Auto-generated method stub

		}

		@Override
		public void actionPerformed(ActionEvent arg0) {
			String name = arg0.getActionCommand();
			if(name.equals("확인")){
				date.set(Calendar.YEAR, Integer.parseInt((String)year.getSelectedItem()));
				date.set(Calendar.MONTH,Integer.parseInt((String)month.getSelectedItem())-1);
				date.set(Calendar.DAY_OF_WEEK, Integer.parseInt((String)day.getSelectedItem()));
				setVisible(false);
			}else if(name.equals("취소")){
				setVisible(false);
			}

		}
	}
}

package graphics.study;

import graphics.EnglishStudyMain;
import graphics.test.TestPanel;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.KeyEvent;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.WindowAdapter;
import java.awt.event.ActionListener;
import java.awt.event.KeyListener;
import java.awt.event.WindowEvent;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Calendar;
import java.util.Date;
import java.util.List;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import javax.swing.border.LineBorder;

import bin.*;

public class SelectFileListPane extends JDialog {
	private static volatile SelectFileListPane instance;
	private JList<String> fileList;
	private JButton choice, cancel;
	private boolean mode;// false : single Selecting Mode , true : Multiple
							// Selecting Mode

	private SelectFileListPane() {
		setView();
	}

	public static SelectFileListPane getInstance() {
		if (instance == null) {
			synchronized (SelectFileListPane.class) {
				if (instance == null) {
					instance = new SelectFileListPane();
					System.out
							.println("System Log : SelectFileListPane is created");
				}
			}
		}
		return instance;
	}

	private void setView() {
		setLayout(new BoxLayout(this.getContentPane(), BoxLayout.Y_AXIS));
		JPanel first, bottom;
		JScrollPane middle;

		first = new JPanel();
		first.setLayout(new FlowLayout(FlowLayout.CENTER));
		first.setAlignmentX(JPanel.CENTER_ALIGNMENT);
		first.add(new JLabel("공부할 파일을 선택하세요"));

		SFLPHandler hand = new SFLPHandler();
		middle = new JScrollPane();
		middle.setAlignmentX(JPanel.CENTER_ALIGNMENT);
		middle.setBorder(BorderFactory.createCompoundBorder(new EmptyBorder(0,
				10, 5, 10), new LineBorder(Color.black)));
		middle.setMaximumSize(new Dimension(200, 100));
		fileList = new JList<String>();
		middle.setViewportView(fileList);
		fileList.addMouseListener(hand);

		bottom = new JPanel();
		bottom.setAlignmentX(JPanel.CENTER_ALIGNMENT);
		choice = new JButton("선택");
		cancel = new JButton("취소");
		choice.addActionListener(hand);
		choice.addKeyListener(hand);
		cancel.addActionListener(hand);
		cancel.addKeyListener(hand);
		bottom.add(choice);
		bottom.add(cancel);

		add(first);
		add(middle);
		add(bottom);

		EnglishStudyMain.setSubInit(this);
		setSize(getWidth(), getHeight() - 30);
		System.out
				.println("System Log : SelectFileListPane View setting is completed");
	}

	private void reset() {
		String[] file = FileManager.getInstance().fileList();
		fileList.setListData(file);
	}

	public void firstInit(boolean mode) {
		reset();
		if (fileList.getModel().getSize() == 0) {
			JOptionPane.showMessageDialog(this, "영어단어를 등록해 주세요");
			return;
		}
		this.mode = mode;
		if (mode) {
			fileList.setSelectionMode(ListSelectionModel.MULTIPLE_INTERVAL_SELECTION);
		} else {
			fileList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		}
		System.out.println("System Log : SelectFileListPane instance is initialized");
		setVisible(true);
	}

	class SFLPHandler extends WindowAdapter implements ActionListener,
			KeyListener, MouseListener {
		Date clickTime = new Date();

		public void actionPerformed(ActionEvent e) {
			String a = e.getActionCommand();
			if (a.equals("선택")) {
				if (mode) {
					List<String> list = fileList.getSelectedValuesList();
					int listSize = list.size();
					Calendar[] date = new Calendar[listSize];
					for(int i = 0 ; i < listSize ; i++ ){
						date[i] = Calendar.getInstance();
						parseDate(date[i], list.get(i).toString());
					}
					TestPanel.getInstance().getManager().startTest(date);
					setVisible(false);
				} else {
					Calendar date = Calendar.getInstance();
					parseDate(date, fileList.getSelectedValue());
					setVisible(false);
					StudyMainPane.getInstance().firstInit(date);
				}
			} else if (a.equals("취소")) {
				setVisible(false);
			}
		}

		public void windowClosing(WindowEvent e) {
			fileList = null;
		}

		@Override
		public void keyPressed(KeyEvent e) {
			// TODO Auto-generated method stub
		}

		@Override
		public void keyReleased(KeyEvent e) {
			// TODO Auto-generated method stub

		}

		@Override
		public void keyTyped(KeyEvent e) {
			// TODO Auto-generated method stub

		}

		@Override
		public void mouseClicked(MouseEvent arg0) {
			// TODO Auto-generated method stub;
			if (Calendar.getInstance().getTime().getTime()
					- clickTime.getTime() < 180) {
				if (mode) {
				} else {
					Calendar date = Calendar.getInstance();
					parseDate(date, fileList.getSelectedValue());
					setVisible(false);
					StudyMainPane.getInstance().firstInit(date);
				}
			} else {
				clickTime = Calendar.getInstance().getTime();
			}
		}

		@Override
		public void mouseEntered(MouseEvent arg0) {
			// TODO Auto-generated method stub

		}

		@Override
		public void mouseExited(MouseEvent arg0) {
			// TODO Auto-generated method stub

		}

		@Override
		public void mousePressed(MouseEvent arg0) {
			// TODO Auto-generated method stub
		}

		@Override
		public void mouseReleased(MouseEvent arg0) {
			// TODO Auto-generated method stub

		}

		private void parseDate(Calendar date ,String fileName) {
			char[] cYear = new char[4];
			char[] cMonth = new char[2];
			char[] cDay = new char[2];
			fileName.getChars(12, 16, cYear, 0);
			int year = (cYear[0] - 48) * 1000 + (cYear[1] - 48) * 100
					+ (cYear[2] - 48) * 10 + (cYear[3] - 48);
			fileName.getChars(16, 18, cMonth, 0);
			int month = (cMonth[0] - 48) * 10 + (cMonth[1] - 48) - 1;
			fileName.getChars(18, 20, cDay, 0);
			int day = (cDay[0] - 48) * 10 + (cDay[1] - 48);
			date.set(Calendar.YEAR, year);
			date.set(Calendar.MONTH, month);
			date.set(Calendar.DAY_OF_MONTH, day);
			return;
		}
	}
}

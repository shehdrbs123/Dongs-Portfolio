package graphics.test;

import graphics.EnglishStudyMain;
import graphics.study.SelectFileListPane;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import javax.swing.border.LineBorder;

import bin.FileManager;
import bin.TestManager;

import java.awt.CardLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.*;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Random;

public class TestPanel extends JDialog {
	private String testWordsNum = "단어 수 0/0";
	private String wordsLabel;
	private JPanel mainPane;
	private int numberOfWords, presentNum;
	private static volatile TestPanel instance;
	private static volatile ResultPane RPinstance;
	private FourChoiceTest one;
	private WriteTest two;
	private CardLayout a;
	private ArrayList<StringBuffer[]> words;
	private boolean mode;
	public static int EorK = 0;

	private TestPanel() {
		setView();
	}

	private void setView() {
		a = new CardLayout();

		mainPane = new JPanel();
		mainPane.setLayout(a);

		one = new FourChoiceTest();
		two = new WriteTest();
		mainPane.add(one);
		mainPane.add(two);
		a.addLayoutComponent(one, "four");
		a.addLayoutComponent(two, "write");

		TPHandler hand = new TPHandler();
		add(mainPane);
		addWindowListener(hand);
		EnglishStudyMain.setSubInit(this);
		setSize(getWidth() + 200, getHeight());
		EnglishStudyMain.locateCenter(this);
		System.out.println("System Log : TestPanel View setting is completed");
	}

	private void update() {
		testWordsNum = "단어 수 " + (presentNum + 1) + "/" + numberOfWords;
		Random rand = new Random();
		EorK = rand.nextInt(2);
		wordsLabel = words.get(presentNum)[EorK].toString();
		if (presentNum == numberOfWords / 2) {
			mode = !mode;
			a.show(mainPane, "write");
		}
		if (mode) {
			one.updatePane();
		} else {
			two.updatePane();
		}
	}

	public static TestPanel getInstance() {
		if (instance == null) {
			synchronized (TestPanel.class) {
				if (instance == null) {
					instance = new TestPanel();
					System.out
							.println("System Log : TestPanel instance is created");
				}
			}
		}
		return instance;
	}

	public void firstInit(boolean isMock) {
		SelectFileListPane.getInstance().firstInit(true);
		words = TestManager.getInstance().getWords();
		if (words == null) {
			return;
		}
		numberOfWords = words.size();
		presentNum = 0;
		mode = true;
		update();
		setVisible(true);
	}

	public TestManager getManager() {
		return TestManager.getInstance();
	}

	public void endTest() {
		JOptionPane.showMessageDialog(this,
				"당신의 점수는 "
						+ (int) ((double) TestManager.getInstance().getScore()
								/ words.size() * 100) + "점 입니다");
		if(presentNum != 0){
			showResultPane();
		}
		words = null;
		a.show(mainPane, "four");
		TestManager.getInstance().stopTest();
		setVisible(false);
	}

	private void showResultPane() {
		new ResultPane();
	}

	class ResultPane extends JDialog {
		ResultPane() {
			setLayout(new BoxLayout(this.getContentPane(), BoxLayout.Y_AXIS));

			JLabel title = new JLabel("결과");
			title.setAlignmentX(JPanel.CENTER_ALIGNMENT);
			add(title);
			
			
			JPanel middle = new JPanel();
			middle.setAlignmentX(JPanel.CENTER_ALIGNMENT);
			middle.setLayout(new GridLayout(0,2));
			for (int i = 0; i < presentNum; i++) {
				JPanel a = new JPanel();
				ArrayList<String> answers = TestManager.getInstance()
						.getAnswers();
				a.setAlignmentX(JPanel.CENTER_ALIGNMENT);
				a.setLayout(new GridLayout(1,4,5,5));
				
				a.setBorder(BorderFactory.createLineBorder(Color.black));
				a.add(new JLabel(words.get(i)[0].toString()));
				a.add(new JLabel(words.get(i)[1].toString()));
				a.add(new JLabel("  내가 쓴 답 : " + answers.get(i)));
				middle.add(a);
			}
			middle.setBorder(BorderFactory.createCompoundBorder(BorderFactory.createEmptyBorder(5,10,5,10),new LineBorder(Color.black)));

			JPanel bottom = new JPanel();
			bottom.setAlignmentX(JPanel.CENTER_ALIGNMENT);
			bottom.setLayout(new FlowLayout(FlowLayout.TRAILING));
			
			JButton confirm = new JButton("확인");
			confirm.setAlignmentX(JPanel.LEFT_ALIGNMENT);
			RPHandler hand = new RPHandler();
			confirm.addActionListener(hand);
			bottom.add(confirm);
			
			add(middle);
			add(bottom);

			EnglishStudyMain.setSubInit(this);
			System.out.println("System Log : ResultPane is created");
			setVisible(true);
		}

		class RPHandler implements ActionListener {
			public void actionPerformed(ActionEvent e) {
				dispose();
			}
		}
	}

	class FourChoiceTest extends JPanel {
		private JButton[] answer = new JButton[4];
		private JLabel wordsNum, question;

		FourChoiceTest() {
			setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
			JPanel first, middle, bottom;

			first = new JPanel();
			first.setLayout(new FlowLayout(FlowLayout.TRAILING));
			first.setAlignmentX(JPanel.CENTER_ALIGNMENT);
			wordsNum = new JLabel(testWordsNum);
			first.add(wordsNum);

			middle = new JPanel();
			middle.setBorder(BorderFactory.createCompoundBorder(
					BorderFactory.createEmptyBorder(5, 5, 5, 5),
					new LineBorder(Color.black)));
			question = new JLabel(wordsLabel);
			middle.add(question);

			bottom = new JPanel();
			bottom.setLayout(new GridLayout(2, 2, 5, 5));
			bottom.setBorder(BorderFactory.createEmptyBorder(5, 5, 5, 5));
			int length = answer.length;
			FCTHandler hand = new FCTHandler();
			for (int i = 0; i < length; i++) {
				answer[i] = new JButton("");
				answer[i].addActionListener(hand);
				bottom.add(answer[i]);
			}

			add(first);
			add(middle);
			add(bottom);
		}

		public void updatePane() {
			wordsNum.setText(testWordsNum);
			question.setText(wordsLabel);
			buttonSet();
		}

		public void buttonSet() {
			if (words.isEmpty()) {
				return;
			} else {
				int[] index = new int[4];
				Random rand = new Random();
				int wordsLength = words.size();
				int randNum;
				int indexSize = index.length;
				index[0] = presentNum;
				for (int i = 1; i < indexSize; i++) {
					randNum = rand.nextInt(wordsLength);
					if (wordsLength > indexSize) {
						for (int o = 0; o < i; o++) {
							if (randNum == index[o]) {
								i--;
								break;
							}
							if (o == i - 1) {
								index[i] = randNum;
							}
						}
					} else {
						index[i] = randNum;
					}
				}
				{
					int temp = index[0];
					int pos = rand.nextInt(4);
					index[0] = index[pos];
					index[pos] = temp;
				}

				for (int i = 0; i < indexSize; i++) {
					int eork = 0;
					if (EorK == 0)
						eork = 1;
					answer[i].setText(words.get(index[i])[eork].toString());
				}
				return;
			}
		}

		class FCTHandler implements ActionListener {
			public void actionPerformed(ActionEvent e) {
				String answer = e.getActionCommand().trim();
				int eork = 0;
				if (TestPanel.EorK == 0) {
					eork = 1;
				}
				String a = words.get(presentNum++)[eork].toString();

				if (answer.equals(a)) {
					TestManager.getInstance().plusScore();
				}
				TestManager.getInstance().storeAnswer(answer);
				TestPanel.getInstance().update();
			}
		}
	}

	class WriteTest extends JPanel {
		JTextField answer;
		JLabel wordsNum, question;

		WriteTest() {
			setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
			JPanel first, middle, bottom;

			first = new JPanel();
			first.setLayout(new FlowLayout(FlowLayout.TRAILING));
			first.setAlignmentX(JPanel.CENTER_ALIGNMENT);
			wordsNum = new JLabel(testWordsNum);
			first.add(wordsNum);

			middle = new JPanel();
			middle.setAlignmentX(JPanel.CENTER_ALIGNMENT);
			middle.setLayout(new GridLayout(2, 1));
			middle.setBorder(BorderFactory.createCompoundBorder(
					BorderFactory.createEmptyBorder(0, 10, 5, 10),
					new LineBorder(Color.black)));

			JPanel middle1 = new JPanel();
			JPanel middle2 = new JPanel();
			question = new JLabel(wordsLabel);
			middle1.add(question);
			answer = new JTextField(10);
			WTHandler hand = new WTHandler();
			answer.addKeyListener(hand);
			middle2.add(answer);
			middle.add(middle1);
			middle.add(middle2);

			bottom = new JPanel();
			bottom.setAlignmentX(JPanel.CENTER_ALIGNMENT);
			bottom.setLayout(new FlowLayout(FlowLayout.TRAILING));
			JButton input = new JButton("입력");
			input.addActionListener(hand);
			bottom.add(input);
			bottom.setBorder(BorderFactory.createEmptyBorder(0, 5, 0, 5));

			add(first);
			add(middle);
			add(bottom);
		}

		public void updatePane() {
			wordsNum.setText(testWordsNum);
			question.setText(wordsLabel);
			answer.getText();
			answer.setText("");
		}

		class WTHandler extends KeyAdapter implements ActionListener {
			public void actionPerformed(ActionEvent e) {
				checkWords();
			}

			public void keyPressed(KeyEvent e) {
				int key = e.getKeyCode();
				if (key == KeyEvent.VK_ENTER) {
					checkWords();
				}
			}

			private void checkWords() {
				answer.getText();
				String word = answer.getText();
				int eork = 0;
				if (EorK == 0)
					eork = 1;
				if (word.equals(words.get(presentNum++)[eork].toString())) {
					TestManager.getInstance().plusScore();
				}
				TestManager.getInstance().storeAnswer(answer.getText());
				if (presentNum == numberOfWords) {
					endTest();
					return;
				}
				TestPanel.getInstance().update();
			}
		}
	}

	class TPHandler extends WindowAdapter {
		public void windowClosing(WindowEvent e) {
			endTest();
		}
	}
}
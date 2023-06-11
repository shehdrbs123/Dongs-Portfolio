package graphics.registry;

import bin.FileManager;
import graphics.EnglishStudyMain;

import java.awt.FlowLayout;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Calendar;

import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class WordsRegistryPane extends JDialog {
	private volatile static WordsRegistryPane instance;// �̱��� ���� ����� ���� instance
														// �������
	private JButton registry, cancel;// ��ư
	private JTextField english, korean;// ����� �ܾ�� ��
	private int numberOfRegistry = 0, presentNum = 0;// ����� �ܾ��� ��, ���� ��ϵ� �ܾ� ��
	private JLabel upperChar;// â�� ǥ���� ���� �ܾ��
	TWRHandler hand;// �� �������� ��Ʈ�ѷ�

	private WordsRegistryPane() {
		setView();// �����ÿ� �ڵ����� �׸��� �׷�����
	}
	public void firstInit() {
		reset();
		if (hand.checkWordsNum() == null || numberOfRegistry == 0) {
			return;
		}
		String wordsNum = " �ܾ� �� " + presentNum + " / " + numberOfRegistry;
		upperChar.setText(wordsNum);// ���� �ܾ�� ����
		System.out.println("System Log : WordsRegistryPane is initialized.");
		setVisible(true);
	}
	public void reset() {
		english.getText();
		korean.getText();
		english.setText("");
		korean.setText("");
		english.requestFocus();// �ڵ����� �����Է� �κ����� ��Ŀ�� �Ǿ� ���ϰ� ���� �Է��Ҽ� �ְ���
	}
	public void update() {
		reset();
		String wordsNum = " �ܾ� �� " + presentNum + " / " + numberOfRegistry;
		upperChar.setText(wordsNum);
	}

	public void setView() {// main���� ���� â���� ����� ������
		JPanel upper, middle1, middle2, down;
		hand = new TWRHandler();

		// ���� �ܾ�� �׷��� �ʱ�ȭ
		upper = new JPanel();
		upper.setLayout(new FlowLayout(FlowLayout.TRAILING, 10, 0));
		upperChar = new JLabel("");
		upper.add(upperChar);

		// ���� �Էºκ� �׷��� �ʱ�ȭ
		middle1 = new JPanel();
		middle1.setAlignmentX(JPanel.CENTER_ALIGNMENT);
		english = new JTextField(10);
		english.addKeyListener(hand);
		middle1.add(new JLabel(" �ܾ� "));
		middle1.add(english);

		// �� �Է� �κ� �׷��� �ʱ�ȭ
		middle2 = new JPanel();
		middle2.setAlignmentX(JPanel.CENTER_ALIGNMENT);
		korean = new JTextField(10);
		korean.addKeyListener(hand);
		middle2.add(new JLabel(" ��    "));
		middle2.add(korean);

		// ��ư �ʱ�ȭ
		down = new JPanel();
		down.setLayout(new FlowLayout(FlowLayout.TRAILING, 10, 0));
		registry = new JButton("���");
		cancel = new JButton("���");
		registry.addMouseListener(hand);
		registry.addKeyListener(hand);
		cancel.addMouseListener(hand);
		down.add(registry);
		down.add(cancel);

		// ����ȭ�� ��ŷ
		this.setLayout(new BoxLayout(this.getContentPane(), BoxLayout.Y_AXIS));
		this.add(upper);
		this.add(middle1);
		this.add(middle2);
		this.add(down);
		this.addWindowListener(hand);// ȭ���� ���������� �Ͼ�� �ൿ���� ������� deactivated �ÿ�
										// ���ϸŴ����� unlink
		EnglishStudyMain.setSubInit(this);
		setSize(getWidth(),getHeight()+40);
		System.out.println("System Log : WordsRegistryPane View setting is completed");
	}
	public static WordsRegistryPane getInstance() {
		if (instance == null) {
			synchronized (WordsRegistryPane.class) {
				if (instance == null) {
					instance = new WordsRegistryPane();
					System.out.println("System Log : WordsRegistryPane instance is created.");
				}
			}
		}
		return instance;
	}
	public boolean isEnd() {// �ܾ �� �ԷµǾ��� Ȯ���ϴ� �޼ҵ�
		if (numberOfRegistry == presentNum) {
			numberOfRegistry = 0;
			presentNum = 0;
			return true;
		}
		return false;
	}
	class TWRHandler extends MouseAdapter implements KeyListener, WindowListener {// WordsRegistryPane ��Ʈ�ѷ�
		private FileManager fm;
		TWRHandler() {
			fm = FileManager.getInstance();
		}
		private String checkWordsNum() {// "�Է��� �ܾ��� ���� ���ϴ� Ŭ����" �μ� String�� ����
										// ShowInputDialog�� Ư������ ���� ��ҳ� X��ư�� ������
			// �ش� String�� ���� ���� ���� ���� ���� �ȵ��� ��Ȳ�� �����ϱ� ������
			String num = null;
			boolean isNum = false;
			while (!isNum) {
				try {
					num = JOptionPane.showInputDialog("����� ������ �ܾ�� �?");
					if(num == null){
						break;
					}
					numberOfRegistry = Integer.parseInt(num);
					isNum = true;
				} catch (NumberFormatException e) {// ���ڰ� �ƴ� �ٸ� ���ڸ� �־������� ����ó��
					JOptionPane.showMessageDialog(WordsRegistryPane.instance,
							"���ڸ� �־��ֽʽÿ�");
					isNum = false;
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
			return num;
		}
		private int checkWords() {// "��ĭ�� ���� Ȯ���ϰ� �ܾ Ȯ���ϱ� ���� �޼ҵ�" ��ȯ���� int�� ������
									// ShowConfirmDialog�� Ư���� ����
			// yes = 0 no =1 x=-1�� �����ϱ� �����̴�.
			if (english.getText().equals("")) {// ����ó���� �κ��� �׳� ���ǹ����� �ѱ���� ���߿� ����
												// �ڵ带 ��Ƴ��� ���� ���� ����
				JOptionPane.showMessageDialog(WordsRegistryPane.instance,
						"�ܾ �Է��� �ֽʽÿ�!");
				return -1;
			} else if (korean.getText().equals("")) {
				JOptionPane.showMessageDialog(WordsRegistryPane.instance,
						"���� �Է��� �ֽʽÿ�!");
				return -1;
			}
			return JOptionPane.showConfirmDialog(WordsRegistryPane.instance,
					english.getText() + " " + korean.getText() + "�� �½��ϱ�?",
					"Ȯ��", JOptionPane.YES_NO_OPTION);
		}
		private boolean writeData(){// ������ �Է� �غ� ���� �޼ҵ�
			int a = checkWords();// �ܾ� Ȯ�� ����â
			if (a == -1 || a == 1) {
				return false;
			}// �ܾ� Ȯ�ν� �亯���� �޾Ƽ� x��ư�̳� �ƴϿ� Ŭ���ÿ� �����͸� �������� ���ϰ� ��
			if (!fm.getIsLinked()) {// ��ũ�� ���� ���θ� Ȯ���Ͽ� Ȥ�ó� ������ ������ ���� �ϱ� ���� ���ǹ�
				try{
					fm.setLink(Calendar.getInstance(), true);
				}catch (Exception e) {
					// TODO Auto-generated catch block
					JOptionPane.showMessageDialog(instance,"�����ڵ� 01 : ���α׷� �����ڿ��� ���� �Ͻʽÿ�!" + FileManager.getInstance().path);
					System.out.println("System err : The file has a matter");
					return false;
				}
				
				// ���ϸŴ����� ���ϰ� link�� �ϰ���, �ѹ� �Է½ÿ� ����ؼ� �Է��ϱ� ������ ������� �ִٰ�, ������
				// unlink�ϰ� ����
			}
			StringBuffer data = new StringBuffer();// ����ÿ� �� String���� �����ϱ� ������
													// StringBuffer�� ����Ͽ���
			english.getText();
			korean.getText();

			data.append(english.getText());
			data.append('/');
			data.append(korean.getText());

			fm.fileWrite(data.toString());// ������ ������ ���ϸŴ����� �̿��Ͽ� ������ ����.
			presentNum++;// �ܾ� ���� �߰��Ͽ� �Է��� ������ŭ�� �Է� �ǰԲ���.
			if (isEnd()) {// isEnd() ������ �ܾ ��� �Է�������쿡 ���ǹ������� ��
				instance.setVisible(false);
				unLinking();
			}
			return true;
		}
		private void unLinking() {// ���� �Ŵ����� ���ϰ� unlink�Ͽ� ���������� ������ ������
			if (fm.getIsLinked()) {
				fm.endLink();
			}
		}

		// @override

		// ���콺 ������
		public void mousePressed(MouseEvent e) {
			Object o = e.getSource();
			if (o == registry) {
				if (writeData()) {// writeDate���� �����͸� ������ ��쿡�� ȭ���� ������Ʈ �ϰ� �ٸ�����
									// ������Ʈ�� ���ϰ� �ϱ����� ���ǹ�
					update();
					english.requestFocus();
				}
			} else if (o == cancel) {
				instance.setVisible(false);
				unLinking();
			}
		}

		// Ű���� ������
		public void keyPressed(KeyEvent e) {
			Object o = e.getSource();
			if (e.getKeyCode() == KeyEvent.VK_ENTER) {
				if (o == english) {
					korean.requestFocus();
				} else if (o == korean) {
					if (writeData()) {// �����Ͱ� �ԷµǾ����� WordsRegistryPane update�� ��
						update();
						english.requestFocus();
					}
				} else if (o == registry) {// �����Ͱ� �ԷµǾ����� WordsRegistryPane
											// update�� ��
					if (writeData()) {
						update();
						english.requestFocus();
					}
				}
			}
		}

		public void keyTyped(KeyEvent e) {}
		public void keyReleased(KeyEvent e) {}
		@Override
		public void windowActivated(WindowEvent e) {
		}

		public void windowClosed(WindowEvent e) {
		}

		public void windowClosing(WindowEvent e) {
		}

		public void windowDeactivated(WindowEvent e) {
			if (!WordsRegistryPane.instance.isVisible()) {
				unLinking();
			}
		}

		public void windowDeiconified(WindowEvent e) {
		}

		public void windowIconified(WindowEvent e) {
		}

		public void windowOpened(WindowEvent e) {
		}
	}
}
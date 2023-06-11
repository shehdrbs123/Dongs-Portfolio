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
	private volatile static WordsRegistryPane instance;// 싱글턴 패턴 사용을 위한 instance
														// 멤버변수
	private JButton registry, cancel;// 버튼
	private JTextField english, korean;// 등록할 단어와 뜻
	private int numberOfRegistry = 0, presentNum = 0;// 등록할 단어의 수, 현재 등록된 단어 수
	private JLabel upperChar;// 창에 표시할 남은 단어수
	TWRHandler hand;// 이 프레임의 컨트롤러

	private WordsRegistryPane() {
		setView();// 생성시에 자동으로 그림을 그려놓음
	}
	public void firstInit() {
		reset();
		if (hand.checkWordsNum() == null || numberOfRegistry == 0) {
			return;
		}
		String wordsNum = " 단어 수 " + presentNum + " / " + numberOfRegistry;
		upperChar.setText(wordsNum);// 남은 단어수 세팅
		System.out.println("System Log : WordsRegistryPane is initialized.");
		setVisible(true);
	}
	public void reset() {
		english.getText();
		korean.getText();
		english.setText("");
		korean.setText("");
		english.requestFocus();// 자동으로 영어입력 부분으로 포커싱 되어 편하게 글을 입력할수 있게함
	}
	public void update() {
		reset();
		String wordsNum = " 단어 수 " + presentNum + " / " + numberOfRegistry;
		upperChar.setText(wordsNum);
	}

	public void setView() {// main에서 서브 창들의 사이즈를 통합함
		JPanel upper, middle1, middle2, down;
		hand = new TWRHandler();

		// 남은 단어수 그래픽 초기화
		upper = new JPanel();
		upper.setLayout(new FlowLayout(FlowLayout.TRAILING, 10, 0));
		upperChar = new JLabel("");
		upper.add(upperChar);

		// 영어 입력부분 그래픽 초기화
		middle1 = new JPanel();
		middle1.setAlignmentX(JPanel.CENTER_ALIGNMENT);
		english = new JTextField(10);
		english.addKeyListener(hand);
		middle1.add(new JLabel(" 단어 "));
		middle1.add(english);

		// 뜻 입력 부분 그래픽 초기화
		middle2 = new JPanel();
		middle2.setAlignmentX(JPanel.CENTER_ALIGNMENT);
		korean = new JTextField(10);
		korean.addKeyListener(hand);
		middle2.add(new JLabel(" 뜻    "));
		middle2.add(korean);

		// 버튼 초기화
		down = new JPanel();
		down.setLayout(new FlowLayout(FlowLayout.TRAILING, 10, 0));
		registry = new JButton("등록");
		cancel = new JButton("취소");
		registry.addMouseListener(hand);
		registry.addKeyListener(hand);
		cancel.addMouseListener(hand);
		down.add(registry);
		down.add(cancel);

		// 메인화면 패킹
		this.setLayout(new BoxLayout(this.getContentPane(), BoxLayout.Y_AXIS));
		this.add(upper);
		this.add(middle1);
		this.add(middle2);
		this.add(down);
		this.addWindowListener(hand);// 화면이 꺼졌을때에 일어나는 행동들을 적어놓음 deactivated 시에
										// 파일매니저와 unlink
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
	public boolean isEnd() {// 단어가 다 입력되었나 확인하는 메소드
		if (numberOfRegistry == presentNum) {
			numberOfRegistry = 0;
			presentNum = 0;
			return true;
		}
		return false;
	}
	class TWRHandler extends MouseAdapter implements KeyListener, WindowListener {// WordsRegistryPane 컨트롤러
		private FileManager fm;
		TWRHandler() {
			fm = FileManager.getInstance();
		}
		private String checkWordsNum() {// "입력할 단어의 수를 정하는 클래스" 로서 String은 명목상
										// ShowInputDialog의 특성으로 인해 취소나 X버튼을 누르면
			// 해당 String에 값이 들어가지 않음 따라서 값이 안들어가는 상황을 방지하기 위함임
			String num = null;
			boolean isNum = false;
			while (!isNum) {
				try {
					num = JOptionPane.showInputDialog("등록할 오늘의 단어는 몇개?");
					if(num == null){
						break;
					}
					numberOfRegistry = Integer.parseInt(num);
					isNum = true;
				} catch (NumberFormatException e) {// 숫자가 아닌 다른 문자를 넣었을때의 예외처리
					JOptionPane.showMessageDialog(WordsRegistryPane.instance,
							"숫자를 넣어주십시오");
					isNum = false;
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
			return num;
		}
		private int checkWords() {// "빈칸이 없다 확인하고 단어를 확인하기 위한 메소드" 반환형이 int인 이유는
									// ShowConfirmDialog의 특성에 따라
			// yes = 0 no =1 x=-1을 반형하기 위함이다.
			if (english.getText().equals("")) {// 예외처리할 부분을 그냥 조건문으로 넘기겠음 나중에 에러
												// 코드를 모아놓는 곳을 만들 거임
				JOptionPane.showMessageDialog(WordsRegistryPane.instance,
						"단어를 입력해 주십시오!");
				return -1;
			} else if (korean.getText().equals("")) {
				JOptionPane.showMessageDialog(WordsRegistryPane.instance,
						"뜻을 입력해 주십시오!");
				return -1;
			}
			return JOptionPane.showConfirmDialog(WordsRegistryPane.instance,
					english.getText() + " " + korean.getText() + "가 맞습니까?",
					"확인", JOptionPane.YES_NO_OPTION);
		}
		private boolean writeData(){// 데이터 입력 준비를 위한 메소드
			int a = checkWords();// 단어 확인 물음창
			if (a == -1 || a == 1) {
				return false;
			}// 단어 확인시 답변값을 받아서 x버튼이나 아니오 클릭시에 데이터를 저장하지 못하게 함
			if (!fm.getIsLinked()) {// 링크의 연결 여부를 확인하여 혹시나 끈어져 있을때 연결 하기 위한 조건문
				try{
					fm.setLink(Calendar.getInstance(), true);
				}catch (Exception e) {
					// TODO Auto-generated catch block
					JOptionPane.showMessageDialog(instance,"에러코드 01 : 프로그램 관리자에게 문의 하십시오!" + FileManager.getInstance().path);
					System.out.println("System err : The file has a matter");
					return false;
				}
				
				// 파일매니저가 파일과 link를 하게함, 한번 입력시에 계속해서 입력하기 때문에 열어놓고 있다가, 닫을때
				// unlink하게 만듬
			}
			StringBuffer data = new StringBuffer();// 저장시에 한 String으로 저장하기 때문에
													// StringBuffer를 사용하였음
			english.getText();
			korean.getText();

			data.append(english.getText());
			data.append('/');
			data.append(korean.getText());

			fm.fileWrite(data.toString());// 데이터 조합후 파일매니저를 이용하여 데이터 저장.
			presentNum++;// 단어 수를 추가하여 입력한 갯수만큼만 입력 되게끔함.
			if (isEnd()) {// isEnd() 정해진 단어를 모두 입력했을경우에 조건문안으로 들어감
				instance.setVisible(false);
				unLinking();
			}
			return true;
		}
		private void unLinking() {// 파일 매니저가 파일과 unlink하여 안정적으로 파일을 저장함
			if (fm.getIsLinked()) {
				fm.endLink();
			}
		}

		// @override

		// 마우스 리스너
		public void mousePressed(MouseEvent e) {
			Object o = e.getSource();
			if (o == registry) {
				if (writeData()) {// writeDate에서 데이터를 저장한 경우에만 화면을 업데이트 하고 다른때는
									// 업데이트를 안하게 하기위한 조건문
					update();
					english.requestFocus();
				}
			} else if (o == cancel) {
				instance.setVisible(false);
				unLinking();
			}
		}

		// 키보드 리스너
		public void keyPressed(KeyEvent e) {
			Object o = e.getSource();
			if (e.getKeyCode() == KeyEvent.VK_ENTER) {
				if (o == english) {
					korean.requestFocus();
				} else if (o == korean) {
					if (writeData()) {// 데이터가 입력되었을때 WordsRegistryPane update를 함
						update();
						english.requestFocus();
					}
				} else if (o == registry) {// 데이터가 입력되었을때 WordsRegistryPane
											// update를 함
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
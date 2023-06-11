package bin;

import java.util.ArrayList;
import java.util.Calendar;

public class TestManager {
	private static volatile TestManager instance;
	private StudyManager manager;
	private ArrayList<StringBuffer[]> words;
	private int score = 0;
	private ArrayList<String> answers;

	private TestManager() {
		manager = StudyManager.getInstance();
		answers = new ArrayList<String>();
	}

	public static TestManager getInstance() {
		if (instance == null) {
			synchronized (TestManager.class) {
				if (instance == null) {
					instance = new TestManager();
					System.out.println("System Log : TestManager is created");
				}
			}
		}
		return instance;
	}

	public ArrayList<StringBuffer[]> getWords() {
		// TODO Auto-generated method stub
		return words;
	}

	public void setWords(Calendar[] dates) {
		for(Calendar i : dates){
			try {
				manager.startStudy(i);
				if(words == null){
					words = new ArrayList<StringBuffer[]>();
				}
				words.addAll(manager.getWords());
				manager.stopStudy();
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
	}
	public void startTest(Calendar[] dates){
		setWords(dates);
		System.out.println("System Log : TestManager is started");
	}
	public void stopTest(){
		words = null;
		score = 0;
		answers.clear();
		System.out.println("System Log : TestManager is zeroized");
	}
	public int getScore(){
		return score;
	}
	public void plusScore(){
		score++;
	}
	public void storeAnswer(String answer){
		answers.add(answer);
	}
	public ArrayList<String> getAnswers(){
		return answers;
	}
}

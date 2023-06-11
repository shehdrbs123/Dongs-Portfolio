package bin;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Calendar;
import java.util.Random;

public class StudyManager {
	private static volatile StudyManager instance;
	private volatile LinkedList<StringBuffer[]> words;
	private StudyManager(){}
	private int pt = 0;
	private void readWords(Calendar date)throws Exception{
		FileManager file = FileManager.getInstance();
		if(words != null){return;}
		file.setLink(date, false);
		words = file.fileRead(date);
		file.endLink();
		assemblingWords(words);
	}
	private ArrayList<StringBuffer[]> changeArray(LinkedList<StringBuffer[]> words){
		Object[] arr = words.toArray();
		ArrayList<StringBuffer[]> word = new ArrayList<StringBuffer[]>();
		for(Object i : arr){
			word.add((StringBuffer[])i);
		}
		return word;
	}
	private LinkedList<StringBuffer[]> assemblingWords(LinkedList<StringBuffer[]> words){
		Random rand = new Random();
		int one, other;
		if(words.size() <= 1){
			return words;
		}
		for(int i = 0; i < (int)words.size()*2.5; i++){
			do{
				one = rand.nextInt(words.size());
				other = rand.nextInt(words.size());
			}while(one == other);
			changePosition(words, one, other);
		}
		return words;
	}
	private void changePosition(LinkedList<StringBuffer[]> words, int one, int other){
		StringBuffer[] buf = words.get(one);
		words.set(one, words.get(other));
		words.set(other, buf);
	}
	public void startStudy(Calendar date) throws Exception{
		readWords(date);
		System.out.println("System Log : StudyManager is started");
	}
	public StringBuffer[] nextWords(){
		StringBuffer[] sWords;
		if(words.size() > pt && words.get(pt) != null){
			sWords = words.get(pt++);
		}else{
			sWords = null;
		}
		return sWords;
	}
	public static StudyManager getInstance(){
		if(instance == null){
			synchronized(StudyManager.class){
				if(instance ==null){
					instance = new StudyManager();
					System.out.println("System Log : StudyManager is created");
				}
			}
		}
		return instance;
	}
	public void repeat(){
		pt = 0;
	}
	public void stopStudy(){
		words = null;
		pt = 0;
		System.out.println("System Log : StudyManager is zeroized");
	}
	public int getLength(){
		if(words != null){
			return words.size();
		}
		return 0;
	}
	public LinkedList<StringBuffer[]> getWords(){
		return words;
	}
}

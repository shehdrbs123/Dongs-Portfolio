package bin;

import java.util.Calendar;
import java.util.LinkedList;
import java.util.Date;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;

public class FileManager {
	private volatile static FileManager instance;
	private RandomAccessFile file;
	private boolean isLinked = false;

	private FileManager() {
	}

	public String path = "c:/EnglishWord/data";

	public static FileManager getInstance() {
		if (instance == null) {
			synchronized (FileManager.class) {
				if (instance == null) {
					instance = new FileManager();
					System.out.println("System Log : FileManager is created");
				}
			}
		}
		return instance;
	}

	public void setLink(Calendar date, boolean isWrite) throws Exception {
		String month;
		String day;
		if (date.get(Calendar.MONTH) + 1 < 10) {
			month = "0" + String.valueOf(date.get(Calendar.MONTH) + 1);
		} else {
			month = String.valueOf(date.get(Calendar.MONTH) + 1);
		}
		if (date.get(Calendar.DAY_OF_MONTH) < 10) {
			day = "0" + String.valueOf(date.get(Calendar.DAY_OF_MONTH));
		} else {
			day = String.valueOf(date.get(Calendar.DAY_OF_MONTH));
		}

		String fileName = path + "/englishData_" + date.get(Calendar.YEAR) + ""
				+ month + "" + day + ".es";
		File a = new File(path);
		checkFile(a);
		if (isWrite) {
			file = new RandomAccessFile(fileName, "rw");
			file.seek(file.length());
		} else {
			file = new RandomAccessFile(fileName, "r");
		}
		isLinked = true;
		System.out.println("System Log : FileManager is Linked");

	}

	public void setLink(String fileName) throws FileNotFoundException {
		fileName = "data\\" + fileName;
		file = new RandomAccessFile(fileName, "r");
		System.out.println("System Log : FileManager is Linked");
	}

	public void endLink() {
		try {
			file.close();
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			isLinked = false;
			System.out.println("System Log : FileManager is unLinked");
		}
	}

	public void fileWrite(String data) {
		try {
			file.writeUTF(data + "\n");
			System.out.println("System Log : Word is writed");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public LinkedList<StringBuffer[]> fileRead(Calendar date) {
		LinkedList<StringBuffer[]> words = new LinkedList<StringBuffer[]>();
		try {
			if (file != null) {
				file.seek(0);
				while (file.getFilePointer() < file.length()) {
					String data = file.readUTF();
					char[] cdata = new char[data.length()];
					cdata = data.toCharArray();
					StringBuffer[] sepData = new StringBuffer[2];
					sepData[0] = new StringBuffer();
					sepData[1] = new StringBuffer();
					int o = 0;
					for (char i : cdata) {
						if (i == '/') {
							o++;
							continue;
						}
						if (i == '\n') {
							continue;
						}
						sepData[o].append(i);
					}
					words.add(sepData);
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
			System.out
					.println("System err : FileManager generated Exception does reading file");
		}
		System.out.println("System Log : Words is read");
		return words;
	}

	public LinkedList<StringBuffer[]> filesRead(Calendar[] date) {
		LinkedList<StringBuffer[]> words = new LinkedList<StringBuffer[]>();
		int dateLength = date.length;
		for (int i = 0; i < dateLength; i++) {
			words.addAll(fileRead(date[i]));
		}
		return words;
	}

	public String[] fileList() {
		File a = new File(path);
		checkFile(a);
		return a.list();
	}

	public boolean getIsLinked() {
		return isLinked;
	}

	private void checkFile(File pos) {
		if (!pos.exists()) {
			if (pos.mkdirs()) {
				System.out.println("System Log : File Setting completed");
			}
		}
	}
}

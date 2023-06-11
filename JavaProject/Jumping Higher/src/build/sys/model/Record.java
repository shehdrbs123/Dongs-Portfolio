package build.sys.model;

import build.JumpingHigher;
import build.interfaces.DrawType;
import build.sys.log.Log;

public class Record extends DrawObject implements Runnable{
	private int blockCount;
	private int height;
	private int time;
	public static volatile Record instance;

	public static Record getInstance() {
		if (instance == null) {
			synchronized (Record.class) {
				if (instance == null) {
					instance = new Record(220,20,0,0,DrawType.TIME);
					Log.log("RecordInstance is created");
				}
			}
		}
		return instance;
	}

	private Record(int x,int y,int width, int height, DrawType bt) {
		super(x,y,width,height,bt);
		init();
	}

	private void init() {
		blockCount = 0;
		height = 0;
		time = 0;
	}

	public void run() {
		init();
		Log.log("Time is running");
		while (!JumpingHigher.getInstance().isGameEnd()) {
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			addTime();
		}
		Log.log("Time is Dead");
	}

	public int getBlockCount() {
		return blockCount;
	}

	public void setBlockCount(int blockcount) {
		this.blockCount = blockcount;
	}

	public void addBlockcount() {
		blockCount++;
	}

	public int getHeight() {
		return height;
	}

	public void setHeight(int height) {
		this.height = height;
	}

	public void addHeight(int add) {
		height += add;
	}

	public String getTime() {
		StringBuffer time = new StringBuffer("00:00");
		int minute = this.time / 60;
		int second = this.time % 60;
		
		if (minute < 10) {
			time.replace(0, 1, "0");
			time.replace(1, 2, String.valueOf(minute));
		} else {
			time.replace(0, 1, String.valueOf(minute));
		}
		if (second < 10) {
			time.replace(3, 4, "0");
			time.replace(4, 5, String.valueOf(second));
		} else {
			time.replace(3, 5, String.valueOf(second));

		}
		return time.toString();
	}

	public void addTime() {
		time++;
	}
}

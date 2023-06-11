package build.sys.model;

import java.util.Random;

import build.interfaces.DrawType;
import build.sys.control.BlockController;

public class Blink extends DrawObject {
	private boolean appear;
	private int count;
	private int time;
	public Blink(int x, int y, int width, int height, DrawType type) {
		super(x, y, width, height, type);
		appear = true;
		count = new Random().nextInt(14)+1;
		time = 1300/BlockController.standardTime;
		// TODO Auto-generated constructor stub
	}

	public void getAttribute(){
		count++;
		if(count >= time){
			appear = !appear;
			count = 0;
		}
	}
	public boolean isAppear(){
		return appear;
	}
}

package build.sys.model;

import build.interfaces.DrawType;
import build.sys.control.BlockController;

public class Dropdown extends DrawObject{
	private int accelate;
	private int count;
	private boolean solid;
	private int time;
	public Dropdown(int x, int y, int width, int height, DrawType type) {
		super(x, y, width, height, type);
		accelate = 0;
		solid = true;
		time = 400/BlockController.standardTime;
		count = 0;
		// TODO Auto-generated constructor stub
	}
	public void crashed(){
		solid = false;
	}
	public void getAttribute(){
		if(!solid){
			if(count>= time){
				accelate += 5;
				this.setY(this.getY()+accelate);
			}else{
				count++;
			}
		}	
	}
}

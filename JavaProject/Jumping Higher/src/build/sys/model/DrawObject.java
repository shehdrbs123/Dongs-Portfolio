package build.sys.model;

import java.awt.Graphics;
import java.awt.Point;
import build.interfaces.*;
import build.sys.view.BlockDrawing;

public class DrawObject implements BlockStructure,Sprite{
	private Point pos;
	private DrawType type;
	private int width, height;
	public DrawObject(int x, int y, DrawType type){
		this.pos = new Point(x,y);
		this.type = type;
		width = BlockStructure.WIDTH;
		height = BlockStructure.HEIGHT;
	}
	public DrawObject(int x, int y,int width, int height, DrawType type){
		this.pos = new Point(x,y);
		this.type = type;
		this.width = width;
		this.height = height;
	}
	
	public DrawObject(Point pos, DrawType type){
		this.pos = pos;
		this.type = type;
	}
	
	public void setX(int x) {
		// TODO Auto-generated method stub
		pos.x = x;
	}

	public void setY(int y) {
		// TODO Auto-generated method stub
		pos.y = y;
	}

	public int getX() {
		// TODO Auto-generated method stub
		return pos.x;
	}

	public int getY() {
		// TODO Auto-generated method stub
		return pos.y;
	}

	public DrawType getType() {
		// TODO Auto-generated method stub
		return type;
	}
	@Override
	public int getWidth() {
		// TODO Auto-generated method stub
		return width;
	}
	@Override
	public int getHeight() {
		// TODO Auto-generated method stub
		return height;
	}
	@Override
	public void paint(Graphics g) {
		// TODO Auto-generated method stub
		BlockDrawing.draw(g,this);
	}
	public void getAttribute(){}
}

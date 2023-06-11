package build.interfaces;

import java.awt.Graphics;

public interface Sprite {
	public void paint(Graphics g);
	public int getX();
	public int getY();
	public int getWidth();
	public int getHeight();
	public DrawType getType();
}

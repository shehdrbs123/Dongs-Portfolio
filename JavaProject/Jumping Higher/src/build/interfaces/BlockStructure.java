package build.interfaces;

public interface BlockStructure{
	public final int WIDTH = 20;
	public final int HEIGHT = 8;
	public void setX(int x);
	public void setY(int y);
	public int getX();
	public int getY();
	public int getWidth();
	public int getHeight();
	public DrawType getType();
}

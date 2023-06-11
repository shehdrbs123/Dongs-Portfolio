package build.sys.model;

import build.interfaces.DrawType;

public class Pierce extends DrawObject {
	private final int triHalfWidth = 7;
	private final int triHeight = 15;
	
	public Pierce(int x, int y, int width, int height, DrawType type) {
		super(x, y, width, height, type);
		// TODO Auto-generated constructor stub
	}

	public int getHalfWidth() {
		return triHalfWidth;
	}

	public int getTriHeight() {
		return triHeight;
	}

}

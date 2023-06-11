package build.sys.control;

import java.awt.Rectangle;

import build.interfaces.BlockStructure;
import build.interfaces.DrawType;
import build.interfaces.Controller;
import build.sys.log.Log;
import build.sys.model.DrawObject;
import build.sys.model.DrawContainer;

public class CrashListener implements Controller {
	private static volatile CrashListener instance;
	private DrawContainer blocks;

	private CrashListener() {
		blocks = DrawContainer.getInstance();
	}

	public static CrashListener getInstance() {
		if (instance == null) {
			synchronized (CrashListener.class) {
				if (instance == null) {
					instance = new CrashListener();
				}
			}
		}
		return instance;

	}

	public DrawType isCrashed(int x, int y) {
		BlockStructure b;
		for (int i = 0; i < blocks.getLength(); i++) {
			b = (BlockStructure) blocks.getBlock(i);
			if (b.getType() != DrawType.BUNDLE) {
				if (b.getY() < y && y < b.getY() + b.getHeight()) {
					if (b.getX() < x && x < b.getX() + b.getWidth()) {
						return b.getType();
					}
				}
			}
		}
		return null;
	}

	public DrawObject whatCrashed(BlockStructure b) {
		BlockStructure b1 = null;
		for (int i = 1; i < blocks.getLength(); i++) {
			if (b == (b1 = blocks.getBlock(i)))
				continue;
			if (b.getY() >= 395) return new DrawObject(0,0,0,0,DrawType.NORMAL);
			int bx1 = b.getX();
			int bx2 = b.getX() + b.getWidth();
			if ((b1.getX() < bx2 && bx2 < b1.getX() + b1.getWidth())
					|| (b1.getX() < bx1 && bx1 < b1.getX() + b1.getWidth())) {
				int by2 = b.getY() + b.getHeight();
				int accel= MoveController.getInstance().getAccelate();
				if(accel >0 ){
					if(by2 <= b1.getY() && by2 + accel > b1.getY()){
						b.setY(b1.getY()-b.getHeight());// 충돌이 발생할 경우 유저의 위치를 해당 블록에 위쪽에 고정시킴
						return (DrawObject)b1;
					}
				}
			}
		}
		return null;
	}
	
	public boolean isCrashed(Rectangle b/*타격점*/, DrawObject b1/*유저*/){ // pierce 전용 충돌 검사
		int bx1 = (int) b.getX();
		int bx2 = (int) (b.getX() + b.getWidth());
		if ((b1.getX() < bx2 && bx2 < b1.getX() + b1.getWidth())
				|| (b1.getX() < bx1 && bx1 < b1.getX() + b1.getWidth())) {
			int by1 = (int) b.getY();
			int by2 = (int) (b.getY() + b.getHeight());
			if(b1.getY() < by2 && by2 <b1.getY() + b1.getHeight() 
					|| b1.getY() < by1 && by1 < b1.getY() + b1.getHeight()){
				return true;
			}
		}
		return false;
	}
}

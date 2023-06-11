package build.sys.control;

import java.awt.Rectangle;

import build.JumpingHigher;
import build.interfaces.DrawType;
import build.interfaces.Controller;
import build.scene.Scene;
import build.sys.log.Log;
import build.sys.model.*;

public class MoveController extends Thread implements Controller {
	private int accelate = 0;
	private static MoveController instance;
	private boolean isFloor;

	private MoveController() {
	}

	public static MoveController getInstance() {
		if (instance == null) {
			synchronized (MoveController.class) {
				if (instance == null) {
					instance = new MoveController();
				}
			}
		}
		return instance;
	}

	private void userMoveCheck() {
		int btnCode = KeyController.getBtnPressed();
		DrawObject user = (DrawObject) DrawContainer.getInstance().getBlock(1);
		CrashListener crash = CrashListener.getInstance();
		DrawObject bt = crash.whatCrashed(user);// 어떤 블록과 부딫혔는지 조사
		// 블록 충돌 처리
		if (bt != null) {
			// 맨 아래 충돌 결정(화면이 올라갔을때 적용X)
			if (user.getY() >= Scene.screenY - user.getHeight()) {
				if (!isFloor) {
					user.setY(Scene.screenY - user.getHeight());
				} else {
					JumpingHigher.getInstance().gameEnd();
					return;
				}
			}
			switch (bt.getType()) {
				case NORMAL:
					accelate = 0;
					break;
				case BLINK:
					if (((Blink) bt).isAppear()) {
						accelate = 0;
					}
					break;
				case DROPDOWN:
					((Dropdown)bt).crashed();
					accelate = 0;
					break;
				case PIERCE://pierce 충돌 검사
					Pierce p = (Pierce)bt;
					int width = (p.getHalfWidth()-3)*2;
					int x = p.getX() + p.getWidth()/2 - width/2;
					int y = p.getY() - p.getTriHeight() + 5;
					int height = p.getTriHeight() - 5 ;
					Rectangle att = new Rectangle(x,y,width,height);
					boolean result =crash.isCrashed(att, user);
					if(result){
						JumpingHigher.getInstance().gameEnd();
						return;
					}
					accelate = 0;
					break;
			}
			if ((btnCode & 0b00000100) == 4) {
				if(bt.getType() != DrawType.BLINK){
					accelate = -15;
				}else{
					if(((Blink)bt).isAppear()){
						accelate = -15;
					}
				}
			}
		}

		// 유저의 Y위치에 따라 움직일 대상을 정함
		if (user.getY() + accelate < 150) {
			if (accelate < 0) {
				BlockController.getInstance().moveAllBlocks(-accelate);
				if (!isFloor)
					isFloor = true;
			}
		} else {
			user.setY(user.getY() + accelate);
		}
		// 키 값에 따라 유저를 움직임
		if ((btnCode & 0b00000010) == 2) {
			if (user.getX() - 8 > 0) {
				user.setX(user.getX() - 6);
			}
		}
		if ((btnCode & 0b00000001) == 1) {
			if (user.getX() + 8 < 260) {
				user.setX(user.getX() + 6);
			}
		}
	}

	public void blockMoveCheck() {
		DrawContainer blocks = DrawContainer.getInstance();
		for (int i = 0; i < blocks.getLength(); i++) {
			if (blocks.getBlock(i).getY() > Scene.screenY) {
				BlockController.getInstance().blockRemove(
						(DrawObject) blocks.getBlock(i));
			}
		}
	}

	public void run() {
		isFloor = false;
		Log.log("MoveController is running");
		while (!JumpingHigher.getInstance().isGameEnd()) {
			userMoveCheck();
			blockMoveCheck();
			accelate += 1;
			try {
				Thread.sleep(21);
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
		Log.log("MoveController is Dead");
	}

	public int getAccelate() {
		return accelate;
	}

	public void setAccelateZero() {
		accelate = 0;
	}
}

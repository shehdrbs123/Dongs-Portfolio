package build.sys.control;

import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import build.JumpingHigher;
import build.interfaces.DrawType;
import build.interfaces.Controller;

public class KeyController extends KeyAdapter implements Controller,
		MouseListener {
	private static KeyController instance;
	private static volatile byte btnPressed = 0;

	private KeyController() {
	}

	public static KeyController getInstance() {
		if (instance == null) {
			synchronized (KeyController.class) {
				if (instance == null) {
					instance = new KeyController();
				}
			}
		}
		return instance;
	}

	@Override
	public void keyPressed(KeyEvent arg0) {
		// TODO Auto-generated method stub
		int keyCode = arg0.getKeyCode();
		switch (keyCode) {
			case KeyEvent.VK_SPACE:
				if ((btnPressed & 0b00000100) == 4) {
					return;
				} else {
					btnPressed += 4;
				}
				break;
			case KeyEvent.VK_LEFT:
				if ((btnPressed & 0b00000010) == 2) {
					return;
				} else {
					btnPressed += 2;
				}
				break;
			case KeyEvent.VK_RIGHT:
				if ((btnPressed & 0b00000001) == 1) {
					return;
				} else {
					btnPressed += 1;
				}
				break;
		}
	}

	@Override
	public void keyReleased(KeyEvent arg0) {
		// TODO Auto-generated method stub
		int keyCode = arg0.getKeyCode();
		switch (keyCode) {
			case KeyEvent.VK_SPACE:
				if ((btnPressed & 0b00000100) == 4) {
					btnPressed -= 4;
				}
				break;
			case KeyEvent.VK_LEFT:
				if ((btnPressed & 0b00000010) == 2) {
					btnPressed -= 2;
				}
				break;
			case KeyEvent.VK_RIGHT:
				if ((btnPressed & 0b00000001) == 1) {
					btnPressed -= 1;
				}
				break;
		}
	}

	@Override
	public void keyTyped(KeyEvent arg0) {
		// TODO Auto-generated method stub

	}

	public static byte getBtnPressed() {
		return btnPressed;
	}
	public static void initBtnPressed() {
		btnPressed = 0;
	}

	@Override
	public void mouseClicked(MouseEvent e) {
		// TODO Auto-generated method stub
		DrawType t = CrashListener.getInstance().isCrashed(e.getX(), e.getY());
		if (t != null) {
			JumpingHigher.getInstance().setSceneNum(t);
		}
	}

	@Override
	public void mouseEntered(MouseEvent e) {
		// TODO Auto-generated method stub

	}

	@Override
	public void mouseExited(MouseEvent e) {
		// TODO Auto-generated method stub

	}

	@Override
	public void mousePressed(MouseEvent e) {
		// TODO Auto-generated method stub

	}

	@Override
	public void mouseReleased(MouseEvent e) {
		// TODO Auto-generated method stub

	}

}
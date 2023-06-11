package build;

import java.awt.Dialog;
import java.awt.event.KeyListener;
import java.awt.event.MouseListener;

import javax.swing.JOptionPane;

import build.interfaces.DrawType;
import build.interfaces.Controller;
import build.sys.control.BlockController;
import build.sys.control.CrashListener;
import build.sys.control.GameFlow;
import build.sys.control.KeyController;
import build.sys.control.MoveController;
import build.sys.log.Log;
import build.sys.model.DrawContainer;
import build.sys.model.Record;
import build.sys.view.Draw;
import build.sys.view.GameFrame;
import build.sys.view.ScenesContainer;

public class JumpingHigher extends GameFlow{
	private static volatile JumpingHigher instance;
	private static boolean end = false;
	private static boolean pause = false;
	private static boolean gameEnd;
	private ScenesContainer scenes;
	private GameFrame frame;
	private Controller[] cons;
	private int sceneNum;
	private JumpingHigher(){}
	
	public static JumpingHigher getInstance(){
		if(instance == null){
			synchronized(JumpingHigher.class){
				if(instance == null){
					instance = new JumpingHigher();
				}
			}
		}
		return instance;
	}

	@Override
	protected void init() {
		// TODO Auto-generated method stub
		//Model 초기화
		scenes = ScenesContainer.getInstance();
		sceneNum=0;
		
		//view 초기화
		Log.log("Frame Setting");
		frame = new GameFrame();
		Draw draw = new Draw();
		frame.add(draw);
		Log.log("Frame Setting Complete");
		
		//Controller 초기화
		Log.log("Controller Setting");
		cons = new Controller[4];
		cons[0] = (Controller) BlockController.getInstance();
		cons[1] = (Controller) KeyController.getInstance();
		cons[2] = (Controller) MoveController.getInstance();
		cons[3] = (Controller) CrashListener.getInstance();
		Log.log("Controller Setting Complete");
	}
	private void makeThread(Thread a){
		a.setDaemon(true);
		a.start();
	}

	@Override
	protected synchronized void gameProcessing() {
		Log.log("System Starting Complete");
		// TODO Auto-generated method stub
		DrawContainer blocks = DrawContainer.getInstance();
		while(end==false){
			try {
				Thread.sleep(200);
			} catch (InterruptedException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			gameEnd = false;
			scenes.getScene(sceneNum).makeScene(blocks);//blocks에 그릴 객체들을 적재시킴
			Draw draw = (Draw)frame.getComponent(0);
			switch(sceneNum){
				case 0 :
					draw.addMouseListener((MouseListener)cons[1]);
					draw.repaint();
					frame.setVisible(true);
					break;
				case 1 :
					draw.removeMouseListener((MouseListener)cons[1]);
					KeyController.initBtnPressed();	
					draw.addKeyListener((KeyListener)cons[1]);
					draw.repaint();
					makeThread(new Thread(draw));
					makeThread(new Thread((MoveController)cons[2]));
					makeThread(new Thread((BlockController)cons[0]));
					makeThread(new Thread(Record.getInstance()));
					break;
				case 2 :
					break;
			}
			try {
				this.wait();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				sceneNum = 0;
			}
		}
	}

	@Override
	public synchronized void end() {//게임 오버 됬을때
		// TODO Auto-generated method stub
		end = true;
		this.notify();
	}

	@Override
	protected void pause()//멈추고 싶을 때 부르는 것
	{
		// TODO Auto-generated method stub
		
	}
	public synchronized void gameEnd()//게임이 종료될때(비정상 종료);
	{
		sceneNum = 0;
		gameEnd = true;
		JOptionPane.showConfirmDialog(frame, "Game Over","게임 종료",JOptionPane.CLOSED_OPTION);
		this.notify();
	}
	public synchronized void setSceneNum(DrawType b){
		if(b != null){
			switch(b){
				case BUTTON_START :
					sceneNum = 1;
					break;
				case BUTTON_HELP :
					sceneNum = 2;
					break;
			}
		}else{
			sceneNum = 0;
		}
		this.notify();
	}
	public boolean isGameEnd(){
		return gameEnd;
	}
	public static void main(String[] args){
		Log.log("System Starting");
		JumpingHigher.getInstance().game();
	}
}

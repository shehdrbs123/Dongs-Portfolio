package build.sys.view;

import java.awt.Canvas;
import java.awt.Graphics;
import java.awt.Image;

import build.JumpingHigher;
import build.interfaces.Sprite;
import build.scene.Scene;
import build.sys.log.Log;
import build.sys.model.DrawContainer;
import build.sys.model.Record;


public class Draw extends Canvas implements Runnable{
	DrawContainer blocks;
	Record time;
	public Draw(){
		blocks = DrawContainer.getInstance();
		time = Record.getInstance();
	}
	
	public void paint(Graphics g){
		Image image = createImage(Scene.screenX,Scene.screenY);
		Graphics pen = image.getGraphics();
		for(int i=0; i<blocks.getLength();i++){
			((Sprite)blocks.getBlock(i)).paint(pen);
		}
		g.drawImage(image,0,0,this);
	}
	public void update(Graphics g){
		paint(g);
	}
	public void run(){
		Log.log("Draw is running");
		while(!JumpingHigher.getInstance().isGameEnd()){
			repaint();
			try{
				Thread.sleep(21);
			}catch(Exception e){
				e.printStackTrace();
			}
		}
		Log.log("Draw is Dead");
	}
}

package build.sys.control;

import java.util.Random;

import build.JumpingHigher;
import build.interfaces.DrawType;
import build.interfaces.Controller;
import build.sys.log.Log;
import build.sys.model.Blink;
import build.sys.model.DrawObject;
import build.sys.model.DrawContainer;
import build.sys.model.Dropdown;
import build.sys.model.Pierce;


public class BlockController extends Thread implements Controller{
	//블록을 움직이고, 만들고, 삭제하는 클래스
	public static final int standardTime = 21; 
	private static volatile BlockController instance;
	private DrawContainer blocks;
	private BlockController(){
		blocks = DrawContainer.getInstance();
	}
	public static BlockController getInstance(){
		if(instance == null){
			synchronized(BlockController.class){
				if(instance == null){
					instance = new BlockController();
				}
			}
		}
		return instance;
	}
	public void moveAllBlocks(int accelate){
		int i = 3;
		DrawObject block;
		for(;i<blocks.getLength();i++){
			block = (DrawObject) blocks.getBlock(i);
			block.setY(block.getY()+accelate);
			if(blocks.getBlock(blocks.getLength()-1).getY() > 100){
				makeBlock();
			}
		}
	}
	public void blockRemove(DrawObject block){
		blocks.removeBlock(block);
	}
	public void makeBlock(){
		Random rand = new Random();
		int ranNum = rand.nextInt(99)+1;
		DrawObject block = null;
		if(ranNum < 70){
			block = new DrawObject(rand.nextInt(182)+50, 0, 50,15,DrawType.NORMAL);
		}else if(ranNum < 78){
			block = new Pierce(rand.nextInt(182)+50, 0, 50,15,DrawType.PIERCE);
		}else if(ranNum < 90){
			block = new Dropdown(rand.nextInt(182)+50, 0, 50,15,DrawType.DROPDOWN);
		}else if(ranNum < 100){
			block = new Blink(rand.nextInt(182)+50, 0, 50,15,DrawType.BLINK);
		}
		blocks.addDrawObjects(block);
	}
	public void run(){
		Log.log("BlockController is running");
		while(!JumpingHigher.getInstance().isGameEnd()){
			activateAttribute();
			try {
				Thread.sleep(21);
			} catch (InterruptedException e) {
			// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		Log.log("BlockController is Dead");
	}
	private void activateAttribute(){
		DrawObject block;
		for(int i = 3; i< blocks.getLength(); i++){
			block = (DrawObject) blocks.getBlock(i);
			block.getAttribute();
		}
	}
}

package build.scene;

import java.util.Random;

import build.interfaces.DrawType;
import build.sys.model.DrawObject;
import build.sys.model.DrawContainer;
import build.sys.model.Record;

public class scene1 extends Scene{

	@Override
	public void makeScene(DrawContainer blocks) {
		// TODO Auto-generated method stub
		blocks.removeAll();
		this.init(blocks);
		
		DrawObject user, time;
		DrawObject[] block;
		
		user = new DrawObject(140,395,40,40,DrawType.USER);
		blocks.addDrawObjects(user);
		time = Record.getInstance();
		blocks.addDrawObjects(time);
		block = new DrawObject[5];
		Random rand = new Random();
		for(int i=0; i<5;i++){
			block[i] = new DrawObject(rand.nextInt(182)+50, Scene.screenY - i*80, 50,15,DrawType.NORMAL);
			blocks.addDrawObjects(block[i]);
		}
	}
}

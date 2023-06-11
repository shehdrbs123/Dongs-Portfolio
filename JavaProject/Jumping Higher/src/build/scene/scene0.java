package build.scene;

import build.interfaces.DrawType;
import build.sys.model.DrawObject;
import build.sys.model.DrawContainer;

public class scene0 extends Scene{

	@Override
	public void makeScene(DrawContainer drawObjs) {
		// TODO Auto-generated method stub
		drawObjs.removeAll();
		this.init(drawObjs);
		DrawObject title,start,help;
		
		title = new DrawObject(34,120,DrawType.TITLE);
		start = new DrawObject(74,250,140,50,DrawType.BUTTON_START);
		help = new DrawObject(74,310,140,50,DrawType.BUTTON_HELP);
		
		drawObjs.addDrawObjects(title);
		drawObjs.addDrawObjects(start);
		drawObjs.addDrawObjects(help);
	}
}

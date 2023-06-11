package build.scene;

import build.interfaces.DrawType;
import build.sys.model.DrawObject;
import build.sys.model.DrawContainer;

public abstract class Scene {
	public abstract void makeScene(DrawContainer blocks);
	public static final int screenY = 435;
	public static final int screenX = 282;
	public void init(DrawContainer blocks){
		blocks.addDrawObjects(new DrawObject (0,0,screenX,screenY,DrawType.BUNDLE));
	};
}

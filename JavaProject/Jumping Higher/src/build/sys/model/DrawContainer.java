package build.sys.model;

import java.util.LinkedList;
import build.interfaces.BlockStructure;

public class DrawContainer {
	private static volatile DrawContainer instance;
	LinkedList<BlockStructure> blocks;
	private DrawContainer(){
		blocks = new LinkedList<BlockStructure>();
	}
	public static DrawContainer getInstance(){
		if(instance == null){
			synchronized(DrawContainer.class){
				if(instance == null){
					instance = new DrawContainer();
				}
			}
		}
		return instance;
	}
	public void addDrawObjects(DrawObject b){
		blocks.add(b);
	}
	public void removeBlock(DrawObject b){
		blocks.remove(b);
	}
	public BlockStructure getBlock(int i){
		return blocks.get(i);
	}
	public void removeAll(){
		blocks.removeAll(blocks);
	}
	public int getLength(){
		return blocks.size();
	}
}

package build.sys.view;

import java.io.File;
import java.util.ArrayList;

import build.scene.Scene;
import build.sys.log.Log;

public class ScenesContainer {
	private static volatile ScenesContainer instance;
	ArrayList<Scene> scenes;

	private ScenesContainer() {
		scenes = new ArrayList<Scene>();
		SceneInit();
	}

	public static ScenesContainer getInstance() {
		if (instance == null) {
			synchronized (ScenesContainer.class) {
				if (instance == null) {
					instance = new ScenesContainer();
				}
			}
		}
		return instance;
	}

	public void SceneInit(){
		Log.log("File Loading");
		String filePath = "bin/build/scene";
		int fileCount = 0;
		File file = new File(filePath);
		if(file.isDirectory()){
			fileCount = file.list().length-1;
		}
		sceneLoad(fileCount);
		Log.log("File Loading Complete");
	}
	public void sceneLoad(int fileCount){
		for(int i=0; i<fileCount; i++){
			try {
				Scene s = (Scene)Class.forName("build.scene.scene" + i).newInstance();
				scenes.add(s);
			} catch (ClassNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (InstantiationException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IllegalAccessException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}

	public Scene getScene(int num) {
		return scenes.get(num);
	}
}

package build.sys.control;

public abstract class GameFlow {
	protected abstract void init();
	protected abstract void gameProcessing();
	protected abstract void end();
	protected abstract void pause();
	public void game(){
		init();
		gameProcessing();
		end();
	}
}

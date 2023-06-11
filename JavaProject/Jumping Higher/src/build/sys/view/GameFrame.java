package build.sys.view;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Frame;
import java.awt.Toolkit;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import java.util.ArrayList;

import build.JumpingHigher;
import build.interfaces.BlockStructure;
import build.interfaces.DrawType;
import build.sys.control.KeyController;
import build.sys.model.DrawObject;

public class GameFrame extends Frame implements WindowListener{
	private int frameX=300;
	private int frameY=480;
	public GameFrame(){
		frameInit();
	}
	private void frameInit(){
		Toolkit toolkit = Toolkit.getDefaultToolkit();
		Dimension screenSize = toolkit.getScreenSize();
		int xpos = (int)screenSize.width/2 - frameX/2;
		int ypos = (int)screenSize.height/2 - frameY/2;
		this.setLocation(xpos,ypos);
		this.setSize(frameX,frameY);
		this.setResizable(true);
		this.addWindowListener(this);
	}
 
	@Override
	public void windowActivated(WindowEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void windowClosed(WindowEvent arg0) {
		// TODO Auto-generated method stub
	}

	@Override
	public void windowClosing(WindowEvent arg0) {
		// TODO Auto-generated method stub
		JumpingHigher.getInstance().end();
		this.dispose();
	}

	@Override
	public void windowDeactivated(WindowEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void windowDeiconified(WindowEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void windowIconified(WindowEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void windowOpened(WindowEvent arg0) {
		// TODO Auto-generated method stub
		
	}
}

package build.sys.view;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import build.sys.model.*;
import build.interfaces.Sprite;

public class BlockDrawing {
	public static void draw(Graphics g,Sprite t){
		switch(t.getType()){
			case USER :
				g.setColor(Color.BLUE);
				g.fillRect(t.getX(), t.getY(), t.getWidth(), t.getHeight());
				break;
			case TITLE :
				g.setFont(new Font(null, 0, 30));
				g.setColor(Color.BLACK);
				g.drawString("Jumping Higher", t.getX(), t.getY());
				break;
			case BUNDLE :
				g.setColor(Color.GRAY);
				g.fillRect(t.getX(), t.getY(), t.getWidth(), t.getHeight());
				break;
			case BUTTON_START :
				g.setColor(Color.CYAN);
				g.fillRect(t.getX(), t.getY(), t.getWidth(), t.getHeight());
				g.setColor(Color.BLACK);
				g.setFont(new Font(null,0,15));
				g.drawString("START",t.getX()+47,t.getY()+30);
				break;
			case BUTTON_HELP :
				g.setColor(Color.CYAN);
				g.fillRect(t.getX(), t.getY(), t.getWidth(), t.getHeight());
				g.setColor(Color.BLACK);
				g.setFont(new Font(null,0,15));
				g.drawString("HELP",t.getX()+53,t.getY()+30);
				break;
			case NORMAL :
				g.setColor(Color.BLACK);
				g.fillRect(t.getX(), t.getY(), t.getWidth(), t.getHeight());
				break;
			case DROPDOWN :
				g.setColor(Color.DARK_GRAY);
				g.fillRect(t.getX(), t.getY(), t.getWidth(), t.getHeight());
				break;
			case PIERCE :
				g.setColor(Color.BLACK);
				g.fillRect(t.getX(), t.getY(), t.getWidth(), t.getHeight());
				int center = t.getX() + t.getWidth()/2;
				Pierce p = (Pierce)t;
				int[] triX = {center-p.getHalfWidth(),center,center+p.getHalfWidth()};
				int[] triY = {t.getY(),t.getY()-p.getTriHeight(),t.getY()};
				g.fillPolygon(triX, triY, 3);
				break;
			case BLINK :
				if(((Blink)t).isAppear()){
					g.setColor(Color.LIGHT_GRAY);
				}else{
					g.setColor(Color.GRAY);
				}
				g.fillRect(t.getX(), t.getY(), t.getWidth(), t.getHeight());
				break;
			case TIME :
				g.setFont(new Font(null, 0, 20));
				g.setColor(Color.BLACK);
				g.drawString(Record.getInstance().getTime(), t.getX(), t.getY());
				break;
		}
	}
}

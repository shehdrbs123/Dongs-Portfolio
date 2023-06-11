package graphics;


import javax.swing.*;
import java.awt.event.MouseAdapter;

public class StudyReportPane extends JDialog {
	private volatile static StudyReportPane SRinstance = null;

	private StudyReportPane() {
	}

	public static StudyReportPane getInstance() {
		if (SRinstance == null) {
			synchronized (StudyReportPane.class) {
				if (SRinstance == null) {
					return new StudyReportPane();
				}
			}
		}
		return SRinstance;
	}
}

class SRHandler extends MouseAdapter {
}

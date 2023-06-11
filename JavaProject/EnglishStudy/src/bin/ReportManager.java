package bin;

public class ReportManager {
	private static volatile ReportManager instance;
	private int RegistryWords;
	private int StudyWords;
	private int averageStudyDay;
	private ReportManager(){}
	public static ReportManager getInstance(){
		if(instance == null){
			synchronized(ReportManager.class){
				if(instance == null){
					instance = new ReportManager();
					System.out.println("ReportManager is created");
				}
			}
		}
		return instance;
	}
}

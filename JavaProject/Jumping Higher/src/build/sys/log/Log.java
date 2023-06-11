package build.sys.log;

public class Log {
	public static void log(String log){
		StringBuilder strBuild = new StringBuilder("System Log : ");
		strBuild.append(log);
		System.out.println(strBuild);
	}
}

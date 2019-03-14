package cn.itcast_03;

import java.io.File;

public class FileDemo1 {
	public static void main(String[] args) {
		
		File srcFolder = new File("/etc");
		
		fun(srcFolder);
	}

	private static void fun(File srcFolder) {
		File[] fileArr = srcFolder.listFiles();
		
		if (fileArr == null) {
			return;
		}
		
		for (File f : fileArr) {
			if (f.isDirectory()) {
				fun(f);
			} else {
				System.out.println(f.getAbsolutePath());
			}
		}
	}
}

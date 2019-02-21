package cn.itcast_02;

import java.io.File;

public class FileDemo2 {
	public static void main(String[] args) {
		File f = new File("/home");
		String[] s = f.list();
		for (String ss : s) {
			System.out.println(ss);
		}
	}
}

package cn.itcast_02;

import java.io.File;
import java.io.IOException;

public class FileDemo {
	public static void main(String[] args) throws IOException {
		File f = new File("test/a.txt");
//		System.out.println("mkdir : " + f.mkdir());
		
		System.out.println("createNewFile : " + f.createNewFile());
		
		System.out.println("del : " + f.delete());
	}
}

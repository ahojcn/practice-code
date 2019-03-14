package cn.itcast_04;

import java.io.FileInputStream;
import java.io.IOException;

public class FileInputStreamDemo {
	public static void main(String[] args) throws IOException {
		FileInputStream fis = new FileInputStream("test.txt");
		
		int by = -1;
		while ((by = fis.read()) != -1) {
			System.out.print((char) by);
		}
		
		fis.close();
	}
}

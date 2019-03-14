package cn.itcast_04;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

/*
 * test.txt => newTest.txt
 */
public class CopyFileDemo {
	public static void main(String[] args) throws IOException {
		FileInputStream fis = new FileInputStream("test.txt");
		FileOutputStream fos = new FileOutputStream("newTest.txt");
		
		int by = -1;
		while ((by = fis.read()) != -1) {
			fos.write(by);
		}
		
		fis.close();
		fos.close();
	}
}

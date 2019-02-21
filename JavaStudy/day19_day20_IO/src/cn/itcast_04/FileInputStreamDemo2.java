package cn.itcast_04;

import java.io.FileInputStream;
import java.io.IOException;

public class FileInputStreamDemo2 {
	public static void main(String[] args) throws IOException{
		FileInputStream fis = new FileInputStream("test.txt");
		
		byte[] b = new byte[1024]; // 一般长度为 1024 或者 1024 的整数倍
		int len = -1;
		while ((len = fis.read(b)) != -1) {
			System.out.print(new String(b, 0, len));
		}
		
		fis.close();
	}
}

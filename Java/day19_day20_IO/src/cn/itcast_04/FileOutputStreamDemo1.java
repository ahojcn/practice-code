package cn.itcast_04;

import java.io.FileOutputStream;
import java.io.IOException;

public class FileOutputStreamDemo1 {
	public static void main(String[] args) throws IOException {
		FileOutputStream fos = new FileOutputStream("test.txt", true);
		fos.write("hello,IO.".getBytes());
		fos.write("\r\n".getBytes());
		fos.write('J');
		fos.write("Java".getBytes(), 1, 3);
		fos.close();
	}
}

package cn.itcast_01;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class BufferedDemo {
	public static void main(String[] args) throws IOException {
		BufferedWriter bw = new BufferedWriter(new FileWriter("a.txt"));
		
		for (int i = 0; i < 10; i++) {
			bw.write("hello" + i);
			bw.newLine();
			bw.flush();
		}
		
		BufferedReader br = new BufferedReader(new FileReader("a.txt"));
		
		String line = null;
		
		while ((line = br.readLine()) != null) {
			System.out.println(line);
		}
		
		bw.close();
		br.close();
	}
}

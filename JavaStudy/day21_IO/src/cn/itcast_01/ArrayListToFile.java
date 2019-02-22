package cn.itcast_01;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class ArrayListToFile {
	public static void main(String[] args) throws IOException{
		ArrayList<String> array = new ArrayList<String>();
		array.add("Hello");
		array.add("World");
		array.add("Java");
		
		BufferedWriter bw = new BufferedWriter(new FileWriter("b.txt"));
		for (String s : array) {
			bw.write(s);
			bw.newLine();
		}
		bw.close();
	}
}

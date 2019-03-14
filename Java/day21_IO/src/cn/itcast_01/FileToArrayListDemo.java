package cn.itcast_01;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Random;

public class FileToArrayListDemo {
	public static void main(String[] args) throws IOException{
		ArrayList<String> arr = new ArrayList<String>();
		BufferedReader br = new BufferedReader(new FileReader("c.txt"));
		
		String line = null;
		while ((line = br.readLine()) != null) {
			arr.add(line);
		}
		
		br.close();
		
		for (String s : arr) {
			System.out.println(s);
		}
		
		Random r = new Random();
		int index = r.nextInt(arr.size());
		
		System.out.println(arr.get(index));
	}
}

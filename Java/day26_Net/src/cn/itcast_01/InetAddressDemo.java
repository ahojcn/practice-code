package cn.itcast_01;

import java.net.InetAddress;
import java.net.UnknownHostException;

public class InetAddressDemo {
	public static void main(String[] args) throws UnknownHostException {
		InetAddress add = InetAddress.getByName("8.8.8.8");
		
		String name = add.getHostName();
		String ip = add.getHostAddress();
		
		System.out.println(name + "---" + ip);
	}
}

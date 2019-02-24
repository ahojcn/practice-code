package udp_test;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class ReceiveDemo {
	public static void main(String[] args) throws IOException {
		DatagramSocket ds = new DatagramSocket(10086);
		
		byte[] buf = new byte[1024];
		int length = buf.length;
		
		DatagramPacket dp = new DatagramPacket(buf, length);
		
		ds.receive(dp);
		
		byte[] buffer = dp.getData();
		int len = dp.getLength();
		String str = new String(buffer,0, len);
		
		InetAddress address = dp.getAddress();
		String ip = address.getHostAddress();
		
		System.out.println(ip + " said : " + str);
		
		ds.close();
	}
}

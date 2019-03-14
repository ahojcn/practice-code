package udp_test;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class SendDemo {
	public static void main(String[] args) throws IOException{
		DatagramSocket ds = new DatagramSocket();
		
		byte[] buf = "hello udp".getBytes();
		int length = buf.length;
		
		InetAddress address = InetAddress.getByName("127.0.0.1");
		
		DatagramPacket dp = new DatagramPacket(buf, length, address, 10086);
		
		ds.send(dp);
		
		ds.close();
	}
}

package tcp_test;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;

public class ClientDemo {
	public static void main(String[] args) throws IOException {
		Socket s = new Socket("127.0.0.1", 9999);
		
		// 向服务器发送数据
		OutputStream os = s.getOutputStream();
		os.write("吼吼吼".getBytes());
		
		// 从服务器接收返回的数据
		InputStream is = s.getInputStream();
		byte[] buf = new byte[1024];
		int len = is.read(buf);
		String Client = new String(buf, 0, len);
		System.out.println("client : " + Client);
		
		s.close();
	}
}

package tcp_test;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerDemo {
	public static void main(String[] args) throws IOException {
		ServerSocket ss = new ServerSocket(9999);
		
		// 监听 9999 端口，与客户端建立连接
		Socket s = ss.accept();
		
		// 接收数据
		InputStream is = s.getInputStream();
		byte[] str = new byte[1024];
		int len = is.read(str);
		String server = new String(str, 0, len);
		System.out.println("server : " + server);
		
		// 向客户端返回一个数据
		OutputStream os = s.getOutputStream();
		os.write("数据已收到".getBytes());
		
		// 关闭连接
		s.close();
	}
}

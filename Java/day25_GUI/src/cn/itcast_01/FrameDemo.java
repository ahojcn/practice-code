package cn.itcast_01;

import java.awt.Frame;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class FrameDemo {
	public static void main(String[] args) {
//		Frame f = new Frame();
		
		Frame f = new Frame("Hello Java GUI");
		
//		f.setTitle("Hello Java");	// 设置窗口标题，也可以通过构造传入
		
		f.setSize(400, 300);	// 单位：像素
		
		f.setLocation(400, 300);
		
//		f.addWindowListener(new WindowListener() {
//			
//			@Override
//			public void windowOpened(WindowEvent e) {
//			}
//			
//			@Override
//			public void windowIconified(WindowEvent e) {
//			}
//			
//			@Override
//			public void windowDeiconified(WindowEvent e) {
//			}
//			
//			@Override
//			public void windowDeactivated(WindowEvent e) {
//			}
//			
//			@Override
//			public void windowClosing(WindowEvent e) {
//				System.exit(0);
//			}
//			
//			@Override
//			public void windowClosed(WindowEvent e) {
//			}
//			
//			@Override
//			public void windowActivated(WindowEvent e) {
//			}
//		});
		
		f.addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent e) {
				System.exit(0);
			}
		});
		
//		f.show();	// 显示窗口，已过时
		f.setVisible(true); // 显示窗口
	}
}

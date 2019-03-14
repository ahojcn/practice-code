package cn.itcast_03;

import java.awt.Button;
import java.awt.FlowLayout;
import java.awt.Frame;
import java.awt.TextArea;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class FrameDemo {
	public static void main(String[] args) {
		Frame f = new Frame("数据转移 测试");

		f.setBounds(300, 400, 300, 400);
		f.setLayout(new FlowLayout());

		// 创建文本框，20个字符宽度
		TextField tf = new TextField(20);

		// 创建按钮
		Button bu = new Button("点我转移");

		// 创建文本域
		TextArea ta = new TextArea(10, 30);

		f.add(tf);
		f.add(bu);
		f.add(ta);

		// 添加按钮点击事件
		bu.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				String str = tf.getText().trim();
				tf.setText("");
				// ta.setText(str + "\n");
				ta.append(str + "\n");
				tf.requestFocus();
			}
		});

		// 添加窗口关闭时间
		f.addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent e) {
				System.exit(0);
			}
		});
		
		f.setVisible(true);
	}
}

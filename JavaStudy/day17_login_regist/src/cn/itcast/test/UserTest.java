package cn.itcast.test;

import java.util.Scanner;

import cn.itcast.dao.UserDao;
import cn.itcast.dao.impl.UserDaoImpl;
import cn.itcast.pojo.User;

/**
 * 用户测试类
 * 
 * @author hanoi_ahoj
 * @version V1.0
 */
public class UserTest {
	public static void main(String[] args) {
		while (true) {
			System.out.println("---------- Welcome ---------");
			System.out.println("1. login");
			System.out.println("2. regist");
			System.out.println("3. exit");
			System.out.println("input > ");
			Scanner sc = new Scanner(System.in);
			String input = sc.nextLine();
			
			UserDao ud = new UserDaoImpl();
			
			switch (input) {
			case "1":
				System.out.println("---------- Login ---------");
				System.out.println("input username > ");
				String username = sc.nextLine();
				System.out.println("input password > ");
				String password = sc.nextLine();
				boolean flag = ud.isLogin(username, password);
				if (flag) {
					System.out.println("ok");
					System.exit(0);
				} else {
					System.out.println("username or password wrong, try again or regist.");
				}
				break;
			case "2":
				System.out.println("---------- Regist ---------");
				System.out.println("input username > ");
				String newUsername = sc.nextLine();
				System.out.println("input password > ");
				String newPassword = sc.nextLine();
				User u = new User();
				u.setUsername(newUsername);
				u.setPassword(newPassword);
				ud.regist(u);
				System.out.println("regist seccused!");
				break;
			case "3":
			default:
				System.out.println("bye!");
				System.exit(0);
			}
		}
	}
}

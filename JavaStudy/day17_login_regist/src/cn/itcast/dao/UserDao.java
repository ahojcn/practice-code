package cn.itcast.dao;

import cn.itcast.pojo.User;

/**
 * 这是针对用户进行操作的接口
 * 
 * @author hanoi_ahoj
 * @version V1.0
 */
public interface UserDao {
	/**
	 * 这是用户登录功能
	 * 
	 * @param username
	 * @param password
	 * @return 返回登录是否成功
	 */
	public abstract boolean isLogin(String username, String password);

	/**
	 * 这是用户注册功能
	 * 
	 * @param user 要注册的用户信息
	 */
	public abstract void regist(User user);
}

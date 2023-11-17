package com.system.dao;

import com.system.entity.User;

public interface UserDao {

	/**
	 * 根据c_id查询user
	 * 
	 * @param id
	 * @return
	 */
	User selectUserByCid(int id);

	/**
	 * 更新用户信息
	 * 
	 * @param id
	 * @return
	 */
	int updateUserByCid(int id, User user);

	User selectAdminByCid(String id, String password);

	int AdminResetUserByCid(int id);

	int updateStaus(int id, int status);
}

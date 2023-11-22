package com.system.service;

import com.system.entity.User;

public interface UserService {
	User selectUserByCid(int id);

	boolean updateUserByCid(int id, User user);

	User selectAdminByCid(String id, String password);

	boolean updateStatus(int id, int status);

	boolean AdminResetUserByCid(int id);
}

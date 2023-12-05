package com.system.service;

import com.system.dao.UserDao;
import com.system.dao.UserDaoImpl;
import com.system.entity.User;

public class UserServiceImpl implements UserService {

	private UserDao userDao;

	@Override
	public User selectUserByCid(int id) {
		userDao = new UserDaoImpl();
        return userDao.selectUserByCid(id);
	}

	@Override
	public boolean updateUserByCid(int id, User user) {
		userDao = new UserDaoImpl();
		int flag = userDao.updateUserByCid(id, user);
        return flag == 1;
	}

	@Override
	public User selectAdminByCid(String id, String password) {
		userDao = new UserDaoImpl();
        return userDao.selectAdminByCid(id, password);
	}

	@Override
	public boolean updateStatus(int id, int status) {
		userDao = new UserDaoImpl();
		int flag = userDao.updateStaus(id, status);
		return flag == 1;
	}

	@Override
	public boolean AdminResetUserByCid(int id) {
		userDao = new UserDaoImpl();
		int flag = userDao.AdminResetUserByCid(id);
		return flag == 1;
	}

}

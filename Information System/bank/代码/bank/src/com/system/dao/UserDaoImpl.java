package com.system.dao;

import com.system.entity.User;
import com.system.utils.DB;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class UserDaoImpl implements UserDao {
	private Connection connection;
	private PreparedStatement ps;
	private ResultSet rs;

	@Override
	public User selectUserByCid(int id) {
		String sql = "select * from user where c_id = ?";
		connection = new DB().getConnection();
		User user = null;
		try {
			ps = connection.prepareStatement(sql);
			ps.setInt(1, id);
			rs = ps.executeQuery();
			while (rs.next()) {
				user = new User();
				user.setId(rs.getInt("id"));
				user.setUsername(rs.getString("username"));
				user.setSex(rs.getString("sex"));
				user.setTelephone(rs.getString("telephone"));
				user.setC_id(id);
			}
			connection.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return user;
	}

	@Override
	public int updateUserByCid(int id, User user) {
		String sql = "update user set username = ?,sex=?,telephone = ? where c_id = ?";
		connection = new DB().getConnection();
		int flag = 0;
		try {
			ps = connection.prepareStatement(sql);
			ps.setString(1, user.getUsername());
			ps.setString(2, user.getSex());
			ps.setString(3, user.getTelephone());
			ps.setInt(4, id);
			flag = ps.executeUpdate();
			
			connection.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return flag;
	}

	@Override
	public User selectAdminByCid(String id, String password) {
		String sql = "select * from admins where id = ? and password = ?";
		connection = new DB().getConnection();
		User user = null;
		try {
			ps = connection.prepareStatement(sql);
			ps.setString(1, String.valueOf(id));
			ps.setString(2, String.valueOf(password));
			rs = ps.executeQuery();
			while (rs.next()) {
				user = new User();
				user.setId(rs.getInt("id"));
			}
			connection.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return user;
	}

	@Override
	public int AdminResetUserByCid(int id) {
		String sql = "update card set password = sha1(123456) where cardname = ?";
		connection = new DB().getConnection();
		int flag = 0;
		try {
			ps = connection.prepareStatement(sql);
			ps.setInt(1, id);
			flag = ps.executeUpdate();
			connection.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return flag;
	}

	@Override
	public int updateStaus(int id, int status) {
		String sql = "update card set valid = ? where cardname = ?";
		connection = new DB().getConnection();
		int flag = 0;
		try {
			ps = connection.prepareStatement(sql);
			ps.setInt(1, status);
			ps.setInt(2, id);
			flag = ps.executeUpdate();
			connection.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return flag;
	}
}

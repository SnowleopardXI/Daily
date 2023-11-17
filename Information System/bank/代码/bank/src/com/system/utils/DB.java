package com.system.utils;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class DB {

	// 数据库地址
	private String Driver_name = "jdbc:mysql://10.40.172.1:3306/swing_bank?serverTimezone=Asia/Shanghai&useSSL=false&characterEncoding=utf8&noAccessToProcedureBodies=true";
	// 数据库用户名
	private String USER = "bank";
	// 数据库密码
	private String PASS = "123456";
	// 数据库连接
	public Connection con;

	// 构造方法
	public DB() {
		try {
			// 加载驱动
			Class.forName("com.mysql.cj.jdbc.Driver");
			// 获取连接
			con = DriverManager.getConnection(Driver_name, USER, PASS);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	// 获取连接
	public Connection getConnection() {
		if (con == null) {
			new DB();
		}
		return con;
	}

	// 释放连接
	public void close(ResultSet resultSet, Statement statement, Connection connection) {

		if (resultSet != null) try {
            resultSet.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

		if (statement != null) {
			try {
				statement.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}

		if (connection != null) {
			try {
				connection.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
	}

	// 释放连接
	public void close(Statement statement, Connection connection) {

		if (statement != null) {
			try {
				statement.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}

		if (connection != null) {
			try {
				connection.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
	}

	// 释放连接
	public void close(Connection connection) {

		if (connection != null) {
			try {
				connection.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
	}
}

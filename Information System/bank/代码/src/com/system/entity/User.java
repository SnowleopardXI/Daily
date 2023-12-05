package com.system.entity;

public class User {

	private int id;
	private String username;
	private String sex;
	private String telephone;
	private int c_id;

	public User() {
		super();
	}

	public User(int id, String username, String sex, String telephone, int c_id) {
		super();
		this.id = id;
		this.username = username;
		this.sex = sex;
		this.telephone = telephone;
		this.c_id = c_id;
	}

	public User(int id) {
		super();
		this.id = id;
	}
	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getUsername() {
		return username;
	}

	public void setUsername(String username) {
		this.username = username;
	}

	public String getSex() {
		return sex;
	}

	public void setSex(String sex) {
		this.sex = sex;
	}

	public String getTelephone() {
		return telephone;
	}

	public void setTelephone(String telephone) {
		this.telephone = telephone;
	}

	public int getC_id() {
		return c_id;
	}

	public void setC_id(int c_id) {
		this.c_id = c_id;
	}

	@Override
	public String toString() {
		return "User [id=" + id + ", username=" + username + ", sex=" + sex + ", telephone=" + telephone + ", c_id="
				+ c_id + "]";
	}

}

package com.system.entity;

import java.math.BigDecimal;

public class Card {

	private int id;
	private String cardname;
	private String password;
	private BigDecimal price;
	private User user;

	public Card() {
		super();
	}

	public Card(int id, String cardname, String password, BigDecimal price, User user) {
		super();
		this.id = id;
		this.cardname = cardname;
		this.password = password;
		this.price = price;
		this.user = user;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getCardname() {
		return cardname;
	}

	public void setCardname(String cardname) {
		this.cardname = cardname;
	}

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password;
	}

	public BigDecimal getPrice() {
		return price;
	}

	public void setPrice(BigDecimal price) {
		this.price = price;
	}

	public User getUser() {
		return user;
	}

	public void setUser(User user) {
		this.user = user;
	}

	@Override
	public String toString() {
		return "Card [id=" + id + ", cardname=" + cardname + ", password=" + password + ", price=" + price + ", user="
				+ user + "]";
	}
}

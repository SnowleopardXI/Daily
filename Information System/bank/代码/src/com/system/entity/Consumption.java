package com.system.entity;

import java.math.BigDecimal;

public class Consumption {
	
	private int id;
	private int c_id;
	private String type;
	private BigDecimal price;
	private String time;

	public Consumption() {
		super();
	}


	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getType() {
		return type;
	}

	public void setType(String type) {
		this.type = type;
	}

	public BigDecimal getPrice() {
		return price;
	}

	public void setPrice(BigDecimal price) {
		this.price = price;
	}

	public String getTime() {
		return time;
	}

	public void setTime(String time) {
		this.time = time;
	}

	@Override
	public String toString() {
		return "Consumption [id=" + id + ", c_id=" + c_id + ", type=" + type + ", price=" + price + ", time=" + time
				+ "]";
	}


}

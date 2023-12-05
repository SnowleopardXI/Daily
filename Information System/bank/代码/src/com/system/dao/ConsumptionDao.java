package com.system.dao;

import java.util.List;

import com.system.entity.Card;
import com.system.entity.Consumption;

public interface ConsumptionDao {

	int insertConsumption(Card card, String money);

	int Withdraw(Card card, String money);

	List<Consumption> selectByCid(int id);

}

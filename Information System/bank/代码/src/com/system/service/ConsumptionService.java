package com.system.service;

import java.util.List;

import com.system.entity.Card;
import com.system.entity.Consumption;

public interface ConsumptionService {

	boolean insertConsumption(Card card, String money);

	boolean Withdraw(Card card, String money);

	List<Consumption> selectByCid(int id);

}

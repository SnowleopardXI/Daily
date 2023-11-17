package com.system.service;

import com.system.dao.ConsumptionDao;
import com.system.dao.ConsumptionDaoImpl;
import com.system.entity.Card;
import com.system.entity.Consumption;

import java.util.List;

public class ConsumptionServiceImpl implements ConsumptionService {

	private ConsumptionDao consumptionDao;

	@Override
	public boolean insertConsumption(Card card, String money) {
		consumptionDao = new ConsumptionDaoImpl();
		int flag = consumptionDao.insertConsumption(card, money);
        return flag == 1;
	}

	@Override
	public boolean quMoney(Card card, String money) {
		consumptionDao = new ConsumptionDaoImpl();
		int flag = consumptionDao.quMoney(card, money);
        return flag == 1;
	}

	@Override
	public List<Consumption> selectByCid(int id) {
		consumptionDao = new ConsumptionDaoImpl();
        return consumptionDao.selectByCid(id);
	}

}

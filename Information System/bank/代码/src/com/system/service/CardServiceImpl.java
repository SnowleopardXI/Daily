package com.system.service;

import com.system.dao.CardDao;
import com.system.dao.CardDaoImpl;
import com.system.entity.Card;
import com.system.entity.User;

import java.sql.SQLException;

public class CardServiceImpl implements CardService {

	private CardDao cardDao;

	@Override
	public boolean selectIsRepeat(String cardname) {
		cardDao = new CardDaoImpl();
		Card card = cardDao.selectIsRepeat(cardname);
        return card != null;
	}

	@Override
	public boolean insertCardAndUser(Card card, User user) {
		cardDao = new CardDaoImpl();
		int flag = cardDao.insertCardAndUser(card, user);
        return flag == 1;
	}

	@Override
	public Card login(String cardName, String password) {
		cardDao = new CardDaoImpl();
        return cardDao.selectCard(cardName, password);
	}

	@Override
	public boolean updatePasswordById(Card card, String password, String newPassword) throws SQLException {
		cardDao = new CardDaoImpl();
		int flag = cardDao.updatePasswordById(card, password, newPassword);
        return flag == 1;
	}

	@Override
	public Card selectCardById(int id) {
		cardDao = new CardDaoImpl();
        return cardDao.selectCardById(id);
	}

	@Override
	public User selectCardByCardName(String cardName) {
		cardDao = new CardDaoImpl();
        return cardDao.selectCardByCardName(cardName);
	}

	@Override
	public boolean TransferMoney(int id, int c_id, String money) {
		cardDao = new CardDaoImpl();
		int flag = cardDao.TransferMoney(id, c_id, money);
        return flag == 1;
	}

	@Override
	public boolean IsValid(String cardName) {
		cardDao = new CardDaoImpl();
		int flag = cardDao.IsValid(cardName);
		return flag == 1;
	}
}

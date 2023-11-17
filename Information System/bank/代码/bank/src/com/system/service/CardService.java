package com.system.service;

import com.system.entity.Card;
import com.system.entity.User;

import java.sql.SQLException;

public interface CardService {

	boolean selectIsRepeat(String cardname);

	/**
	 * 注册
	 */
	boolean insertCardAndUser(Card card, User user);

	/**
	 * 登录
	 * 
	 * @param cardName
	 * @param password
	 * @return
	 */
	Card login(String cardName, String password);

	/**
	 * 修改银行卡密码
	 *
	 * @param password
	 * @param newPassword
	 * @return
	 */
	boolean updatePasswordById(Card card, String password, String newPassword) throws SQLException;

	/**
	 * 根据id查询 card
	 * 
	 * @param id
	 * @return
	 */
	Card selectCardById(int id);

	/**
	 * 根据卡号查询
	 * 
	 * @param cardName
	 * @return
	 */
	User selectCardByCardName(String cardName);

	/**
	 * 转账成功
	 * 
	 * @param id
	 * @param c_id
	 * @param money
	 * @return
	 */
	boolean TransferMoney(int id, int c_id, String money);

	boolean IsValid(String cardName);
}

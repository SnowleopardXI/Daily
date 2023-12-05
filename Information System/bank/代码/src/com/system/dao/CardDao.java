package com.system.dao;

import com.system.entity.Card;
import com.system.entity.User;

import java.sql.SQLException;

public interface CardDao {

	/**
	 * 查询银行卡是否重复
	 * 
	 * @param cardname
	 * @return
	 */
	Card selectIsRepeat(String cardname);

	/**
	 * 注册
	 * 
	 * @param card
	 * @return
	 */
	int insertCardAndUser(Card card, User user);

	/**
	 * 登录
	 * 
	 * @param cardName
	 * @param password
	 * @return
	 */
	Card selectCard(String cardName, String password);

	/**
	 * 修改密码
	 * 
	 * @param card
	 * @return
	 */
	int updatePasswordById(Card card, String password) throws SQLException;

	int updatePasswordById(Card card, String oldPassword, String password) throws SQLException;

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
	 * 转账
	 * 
	 * @param id
	 * @param c_id
	 * @param money
	 * @return
	 */
	int TransferMoney(int id, int c_id, String money);

	int IsValid(String cardName);

}

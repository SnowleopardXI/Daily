package com.system.dao;

import com.system.entity.Card;
import com.system.entity.User;
import com.system.utils.DB;

import java.math.BigDecimal;
import java.sql.*;


public class CardDaoImpl implements CardDao {

	private Connection connection;
	private PreparedStatement ps;
	private CallableStatement cs;
	private ResultSet rs;

	@Override
	public Card selectIsRepeat(String cardname) {
		String sql = "select * from card where cardname = ?";
		connection = new DB().getConnection();
		Card card = null;
		try {
			ps = connection.prepareStatement(sql);
			ps.setString(1, cardname);
			rs = ps.executeQuery();
			while (rs.next()) {
				card = new Card();

			}
			connection.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return card;
	}

	@Override
	public int insertCardAndUser(Card card, User user) {
		// card表
		String sql_1 = "insert into card(cardname,password,price) values(?,sha1(?),?)";
		// consumption表
		String sql = "insert into consumption(c_id,type,price) values(?,?,0)";
		// user表
		String sql_2 = "insert into user(username,sex,telephone,c_id) values(?,?,?,?)";
		connection = new DB().getConnection();
		int flag = 0;
		try {
			connection.setAutoCommit(false);
			// 插入银行卡信息
			ps = connection.prepareStatement(sql_1, Statement.RETURN_GENERATED_KEYS);
			ps.setString(1, card.getCardname());
			ps.setString(2, card.getPassword());
			ps.setBigDecimal(3, new BigDecimal("0"));
			ps.executeUpdate();
			rs = ps.getGeneratedKeys();
			if (rs.next()) {
				card.setId(rs.getInt(1));
			}
			
			// 插入消费记录
			ps = connection.prepareStatement(sql);
			ps.setInt(1, card.getId());
			ps.setString(2, "开户");
			ps.executeUpdate();

			// 插入用户信息
			ps = connection.prepareStatement(sql_2);
			ps.setString(1, user.getUsername());
			ps.setString(2, user.getSex());
			ps.setString(3, user.getTelephone());
			ps.setInt(4, card.getId());
			flag = ps.executeUpdate();

			connection.commit();
			connection.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			try {
				connection.rollback();
			} catch (SQLException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			e.printStackTrace();
		}
		return flag;
	}

	@Override
	public Card selectCard(String cardName, String password) {
		connection = new DB().getConnection();
		Card card = null;
        String sql = "select * from card where cardname = ? and password = sha1(?) and valid = 1";
        connection = new DB().getConnection();
		try {
			ps = connection.prepareStatement(sql);
			ps.setString(1, cardName);
			ps.setString(2, password);
			rs = ps.executeQuery();
			while (rs.next()) {
				card = new Card();
				card.setId(rs.getInt("id"));
				card.setCardname(rs.getString("cardname"));
				card.setPassword(rs.getString("password"));
				card.setPrice(rs.getBigDecimal("price"));
			}
			connection.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return card;
	}

	@Override
	public int updatePasswordById(Card card, String password) throws SQLException {
		return 0;
	}

	@Override
	public int IsValid(String cardName) {
		String sql = "select count(*) as count from card where cardname = ? and valid = 1";
		connection = new DB().getConnection();
		int flag=0;
		try {
			ps = connection.prepareStatement(sql);
			ps.setString(1, cardName);
			rs = ps.executeQuery();
			while (rs.next()) {
				flag = rs.getInt("count");
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return flag;
	}

	@Override
	public int updatePasswordById(Card card, String oldPassword, String password) throws SQLException {
		String sql = "CALL update_pass(?,?,?,@flag)";
		connection = new DB().getConnection();
		int flag = 0;
		try {
			cs = connection.prepareCall(sql);
			cs.setInt(1, card.getId());
			cs.setString(2, oldPassword);
			cs.setString(3, password);
			cs.execute();

			rs = cs.executeQuery("select @flag");
			while (rs.next()) {
				flag = rs.getInt("@flag");
			}
			connection.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return flag;
	}

	@Override
	public Card selectCardById(int id) {
		String sql = "select * from card where id = ?";
		connection = new DB().getConnection();
		Card card = null;
		try {
			ps = connection.prepareStatement(sql);
			ps.setInt(1, id);
			rs = ps.executeQuery();
			while (rs.next()) {
				card = new Card();
				card.setId(rs.getInt("id"));
				card.setCardname(rs.getString("cardname"));
				card.setPassword(rs.getString("password"));
				card.setPrice(rs.getBigDecimal("price"));


            }

			connection.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return card;
	}

	@Override
	public User selectCardByCardName(String cardName) {
		String sql = "select u.c_id,u.username from card c,user u where c.cardname = ? and u.c_id = c.id";
		connection = new DB().getConnection();
		User user = null;
		try {
			ps = connection.prepareStatement(sql);
			ps.setString(1, cardName);
			rs = ps.executeQuery();
			while (rs.next()) {
				user = new User();
				user.setUsername(rs.getString("u.username"));
				user.setC_id(rs.getInt("u.c_id"));
			}
			connection.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return user;
	}

	@Override
	public int TransferMoney(int id, int c_id, String money) {
		String sql = "select * from card where id = ?";
		connection = new DB().getConnection();
		int flag = 0;
		// 本银行卡
		Card card = new Card();
		// 转入的银行卡
		Card card_1 = new Card();
		try {
			// 查询余额
			connection.setAutoCommit(false);
			ps = connection.prepareStatement(sql);
			ps.setInt(1, id);
			rs = ps.executeQuery();
			while (rs.next()) {
				card.setId(rs.getInt("id"));
				card.setCardname(rs.getString("cardname"));
				card.setPrice(rs.getBigDecimal("price"));
			}

			// 余额是否充足
			if (card.getPrice().compareTo(new BigDecimal(money)) == -1) {
				return flag;
			} else {

				String sql_4 = "select * from card where id = ?";
				ps = connection.prepareStatement(sql_4);
				ps.setInt(1, c_id);
				rs = ps.executeQuery();
				while (rs.next()) {
					card_1.setCardname(rs.getString("cardname"));
					card_1.setPrice(rs.getBigDecimal("price"));

				}

				// 本银行卡，扣钱+余额更新
				String sql_1 = "insert into consumption(type,price,c_id) values(?,?,?)";
				ps = connection.prepareStatement(sql_1);
				ps.setString(1, "转出:账号信息 " + card_1.getCardname());
				ps.setBigDecimal(2, new BigDecimal(money));
				ps.setInt(3, id);
				ps.executeUpdate();
				
				String sql_2 = "update card set price = ? where id = ?";
				ps = connection.prepareStatement(sql_2);
				ps.setBigDecimal(1, card.getPrice().subtract(new BigDecimal(money)));
				ps.setInt(2, id);
				ps.executeUpdate();

				// 转给的账号，加钱+余额更新
				String sql_3 = "insert into consumption(type,price,c_id) values(?,?,?)";
				ps = connection.prepareStatement(sql_3);
				ps.setString(1, "转入:账号信息 " + card.getCardname());
				ps.setBigDecimal(2, new BigDecimal(money));
				ps.setInt(3, c_id);
				ps.executeUpdate();
				


				String sql_5 = "update card set price = ? where id = ?";
				ps = connection.prepareStatement(sql_5);
				ps.setBigDecimal(1, card_1.getPrice().add(new BigDecimal(money)));
				ps.setInt(2, c_id);
				flag = ps.executeUpdate();

				connection.commit();

			}
			connection.close();
		} catch (SQLException e) {
			try {
				connection.rollback();
			} catch (SQLException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			e.printStackTrace();
		}
		return flag;
	}

}
